#ifndef EMITTER_H_
#define EMITTER_H_

#include "Particle.h"
#include <memory>
#include <ngl/AbstractVAO.h>
#include <vector>

class Emitter {
public:
    Emitter(size_t _numParticles);
    ~Emitter() = default;
    void update();
    void draw() const;
private:
    std::vector<Particle> m_particles;
    std::unique_ptr<ngl::AbstractVAO> m_vao;
};


#endif
