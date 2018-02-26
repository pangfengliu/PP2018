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
      double factor = 1.0 / ((dx * dx) + (dy * dy) + (dz * dz));
      particles[me].ax = dx * particles[other].mass;
      particles[me].ay = dy * particles[other].mass;
      particles[me].az = dz * particles[other].mass;
    }

  double dt = 0.000001;
  for (int me = 0; me < N; me++) {
    particles[me].x += particles[me].ax * dt;
    particles[me].y += particles[me].ay * dt;
    particles[me].z += particles[me].az * dt;
  }  
}
