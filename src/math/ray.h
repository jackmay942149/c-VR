#ifndef RAY_H
#define RAY_H

#include "vector.h"

typedef struct Ray {
  Vec3f origin;
  Vec3f direction;
} Ray;

// Returns a end point of the ray given a length
Vec3f Ray_Point(const Ray* ray, float length);

#endif
