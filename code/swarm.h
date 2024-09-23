#ifndef SWARM_H_
#define SWARM_H_

#include "particle.h"

namespace scr {
  class Swarm {
    public:
      const static int N_PARTICLES = 4000;
    private:
      Particle * m_pParticles;
      int lastTime;
    public:
      Swarm();
      virtual ~Swarm();

      void update(int elapsed);
      
      const Particle * const getParticles() {
        return m_pParticles;
      }
  };
}

#endif