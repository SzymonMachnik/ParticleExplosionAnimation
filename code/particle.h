#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <SDL2/SDL.h>

namespace scr {
  struct Particle {
    double m_x;
    double m_y;

    double m_speed;
    double m_direction;

    Particle();
    virtual ~Particle();
    void update(int interval);
    void init();
  };
}

#endif