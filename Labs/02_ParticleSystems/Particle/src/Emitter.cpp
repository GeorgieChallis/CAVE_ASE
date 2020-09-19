#include "Emitter.h"
#include <ngl/Random.h>

Emitter::Emitter(size_t _numParticles)
{
    m_particles.resize(_numParticles);
    auto rng = ngl::Random::instance();
    for(auto &p : m_particles){
        p.pos.set(0.0f, 0.0f, 0.0f);
        p.dir = rng->getRandomVec3();
        p.maxLife = static_cast<int>(rng->randomPositiveNumber(100));
    }
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

}
