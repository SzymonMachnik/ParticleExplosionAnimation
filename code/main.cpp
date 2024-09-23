#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include "screen.h"
#include <stdlib.h>
#include <time.h>
#include "swarm.h"
using namespace std;
using namespace scr;

int main(int argc, char *argv[]) {

  srand(time(NULL));

  Screen screen;
  if (screen.init() == false) {
    cout << "Error initialisating SDL" << endl;
  }

  bool quit = false;
  SDL_Event event;
  
  Swarm swarm;

  while (true) {

    int elapsed = SDL_GetTicks();

    // Update particles
    swarm.update(elapsed);
    // Draw particles

    const Particle * const pParticle = swarm.getParticles();

    unsigned char red = (1 + sin(elapsed * 0.0001)) * 127.5;
    unsigned char green = (1 + sin(elapsed * 0.0002)) * 127.5;
    unsigned char blue = (1 + sin(elapsed * 0.0003)) * 127.5;
    //red = 255, green = 255, blue = 255;

    for (int i = 0; i < Swarm::N_PARTICLES; i++) {
      Particle particle = pParticle[i];

      int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
      int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;
    
      screen.setPixel(x, y, red, green, blue);
    }

    screen.boxBlur();
    // Draw the screen
    screen.update();
    // Check for updates/messages
    if (screen.processEvents() == false) break;
  }

  screen.close();

  return 0;
}

//I love Roya
// I love Roya my bobo
//fgd
// elo elo