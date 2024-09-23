#include "swarm.h"

namespace scr {
  Swarm::Swarm() {
    m_pParticles = new Particle[N_PARTICLES];
    lastTime = 0;
  }

  Swarm::~Swarm() {
    delete m_pParticles;
  }

  void Swarm::update(int elapsed) {
    int interval = elapsed - lastTime;

    for (int i = 0; i < Swarm::N_PARTICLES; i++) {
      m_pParticles[i].update(interval);

      // int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
      // int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2;
    
      // screen.setPixel(x, y, red, green, blue);
    }
    
    lastTime = elapsed;
  }
}