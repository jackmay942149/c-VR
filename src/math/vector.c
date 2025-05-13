#include "vector.h"
#include <math.h>

// -- Vec2 Functions -- //
Vec2f Vec2f_AddFloat(Vec2f vec, float f) {
  Vec2f v = {.u = vec.u + f, .v = vec.v + f};
  return v;
}

Vec2f Vec2f_AddVec2(Vec2f a, Vec2f b) {
  Vec2f v = {.u = a.u + b.u, .v = a.v + b.v};
  return v;
}

Vec2f Vec2f_Multiply(Vec2f vec, float f) {
  Vec2f v = {.u = vec.u * f, .v = vec.v * f};
  return v;  
}

float Vec2f_Dot(Vec2f a, Vec2f b) {
  return (a.u * b.u + a.v * b.v);  
}

float Vec2f_Magnitude(Vec2f vec) {
  return sqrt(vec.u * vec.u + vec.v * vec.v);
}

Vec2f Vec2f_Normailze(Vec2f vec) {
  float f = Vec2f_Magnitude(vec);
  Vec2f v = {.u = vec.u/f, .v = vec.v/f};
  return v;
}

// Returns Anti-Clockwise Orthogonal, Vec2f_Multiply(result, -1.0) will give clockwise
Vec2f Vec2f_Orthogonal(Vec2f vec) {
  Vec2f v = {.u = -vec.v, .v = vec.u};
  return v;
}

// -- Vec3 Functions -- //
Vec3f Vec3f_AddFloat(Vec3f vec, float f) {
  Vec3f v = {.x = vec.x + f, .y = vec.y + f, .z = vec.z + f};
  return v;
}

Vec3f Vec3f_AddVec3(Vec3f a, Vec3f b) {
  Vec3f v = {.x = a.x * b.x, .y = a.y * b.y, .z = a.z * b.z};
  return v;
}

Vec3f Vec3f_Multiply(Vec3f vec, float f) {
  Vec3f v = {.x = vec.x * f, .y = vec.y * f, .z = vec.z * f};
  return v;
}

float Vec3f_Dot(Vec3f a, Vec3f b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float Vec3f_Magnitude(Vec3f vec) {
  return (float) pow(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z, 1.0/3);
}

Vec3f Vec3f_Normailze(Vec3f vec) {
  float f = Vec3f_Magnitude(vec);
  Vec3f v = {.x = vec.x/f, .y = vec.y/f, .z = vec.z/f};
  return v;
}

Vec3f Vec3f_Cross(Vec3f a, Vec3f b) {
  Vec3f v = {.x = a.y * b.z - b.y * a.z, .y = a.x * b.z - b.x * a.z, .z = a.x * b.y - b.x * a.y};
  return v;
}

// -- Vec4 Functions -- //
Vec4f Vec4f_AddFloat(Vec4f vec, float f) {
  Vec4f v = {.x = vec.x + f, .y = vec.y + f, .z = vec.z + f, .w = vec.w + f};
  return v;
}

Vec4f Vec4f_AddVec4(Vec4f a, Vec4f b) {
  Vec4f v = {.x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z, .w = a.w + b.w};
  return v;
}

Vec4f Vec4f_MultiplyFloat(Vec4f vec, float f) {
  Vec4f v = {.x = vec.x * f, .y = vec.y * f, .z = vec.z * f, .w = vec.w * f};
  return v;
}

Vec4f Vec4f_MultiplyVec4(Vec4f a, Vec4f b) {
  Vec4f v = {.x = a.x * b.x, .y = a.y * b.y, .z = a.z * b.z, .w = a.w * b.w};
  return v;
}

float Vec4f_Dot(Vec4f a, Vec4f b) {
  return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

float Vec4f_Magnitude(Vec4f vec) {
  return (float) pow(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w, 1.0/4);
}

Vec4f Vec4f_Normailze(Vec4f vec) {
  float f = Vec4f_Magnitude(vec);
  Vec4f v = {.x = vec.x/f, .y = vec.y/f, .z = vec.z/f, .w = vec.w/f};
  return v;
}
