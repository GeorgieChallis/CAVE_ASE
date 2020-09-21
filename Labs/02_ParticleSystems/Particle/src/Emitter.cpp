#include "Emitter.h"
#include <ngl/Random.h>
#include <ngl/SimpleVAO.h>
#include <ngl/VAOFactory.h>

Emitter::Emitter(size_t _numParticles)
{
    m_particles.resize(_numParticles);
    auto rng = ngl::Random::instance();
    for(auto &p : m_particles){
        p.pos.set(0.0f, 0.0f, 0.0f);
        p.dir = rng->getRandomVec3();
        p.maxLife = static_cast<int>(rng->randomPositiveNumber(100));
    }
    m_vao = ngl::VAOFactory::createVAO(ngl::simpleVAO, GL_POINTS);
}

void Emitter::update()
{
    auto rng = ngl::Random::instance();
    for(auto& p : m_particles){
        if (++p.life >= p.maxLife)
        {
            p.pos.set(0.0f, 0.0f, 0.0f);
            p.life = 0;
            p.dir = rng->getRandomVec3();
            p.maxLife = static_cast<int>(rng->randomPositiveNumber(100));
        }
    }
}

void Emitter::draw() const
{
    glPointSize(10);
    m_vao->bind();
    m_vao->setData(ngl::SimpleVAO::VertexData(
                       m_particles.size()*sizeof (Particle), m_particles[0].pos.m_x)
    );
    m_vao->setVertexAttributePointer(0, 3, GL_FLOAT, sizeof (Particle), 0);
    m_vao->setVertexAttributePointer(1, 3, GL_FLOAT, sizeof (Particle), 6);
    m_vao->setNumIndices(m_particles.size());
    m_vao->draw();
    m_vao->unbind();
}
