#include "sphereRandomGen.h"

#include <math.h>

void genPointOnSphere(float u1, float u2, float &x, float &y, float &z) {
  auto theta = 2 * M_PI * u1;
  auto phi = acos(2 * u2 - 1);
  float sinPhi, cosPhi, sinTheta, cosTheta;
  __sincosf(phi, &sinPhi, &cosPhi);
  __sincosf(theta, &sinTheta, &cosTheta);
  x = sinPhi * cosTheta;
  y = sinPhi * sinTheta;
  z = cosPhi;
}