#include <stdlib.h>

typedef struct particle
{
  double mass;
  double x, y, z;
  double ax, ay, az;
} Particle;

double randCord() 
{
  return ((rand() % RAND_MAX) / ((double) RAND_MAX));
}

#define N 100000
Particle particles[N];

int main()
{
  for (int me = 0; me < N; me++) {
    particles[me].mass = randCord();
    particles[me].x = randCord();
    particles[me].y = randCord();
    particles[me].z = randCord();
  }

  for (int me = 0; me < N; me++) 
    for (int other = 0; other < N; other++) {
      double dx = particles[other].x - particles[me].x;
      double dy = particles[other].y - particles[me].y;
      double dz = particles[other].z - particles[me].z;
      double factor = particles[other].mass /
	((dx * dx) + (dy * dy) + (dz * dz));
      particles[me].ax += dx * factor;
      particles[me].ay += dy * factor;
      particles[me].az += dz * factor;
    }

  double dt = 0.000001;
  for (int me = 0; me < N; me++) {
    particles[me].x += 0.5 * particles[me].ax * dt * dt;
    particles[me].y += 0.5 * particles[me].ay * dt * dt;
    particles[me].z += 0.5 * particles[me].az * dt * dt;
  }  
}
