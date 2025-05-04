#include "ray.h"

Vec3f Ray_Point(const Ray* ray, float length) {
  float x = ray->origin.x + ray->direction.x * length;
  float y = ray->origin.y + ray->direction.y * length;
  float z = ray->origin.z + ray->direction.z * length;
  Vec3f v = {.x = x, .y = y, .z = z};
  return v;
}
