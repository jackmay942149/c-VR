#include "matrix.h"
#include "vector.h"
#include <math.h>

#define M_PI 3.14

void Mat4f_Transpose(Mat4f* m) {
  Vec4f a = {.x = m->a.x, .y = m->b.x, .z = m->c.x, .w = m->d.x};
  Vec4f b = {.x = m->a.y, .y = m->b.y, .z = m->c.y, .w = m->d.y};
  Vec4f c = {.x = m->a.z, .y = m->b.z, .z = m->c.z, .w = m->d.z};
  Vec4f d = {.x = m->a.w, .y = m->b.w, .z = m->c.w, .w = m->d.w};

  m->a = a; m->b = b; m->c = c; m->d = d;
  return;
}

void Mat4f_Multiply(Mat4f* a, Mat4f b) {
  Mat4f_Transpose(&b);
  Vec4f vecA = {.x = Vec4f_Dot(a->a, b.a), .y = Vec4f_Dot(a->a, b.b), .z = Vec4f_Dot(a->a, b.c), .w = Vec4f_Dot(a->a, b.d)};
  Vec4f vecB = {.x = Vec4f_Dot(a->b, b.a), .y = Vec4f_Dot(a->b, b.b), .z = Vec4f_Dot(a->b, b.c), .w = Vec4f_Dot(a->b, b.d)};
  Vec4f vecC = {.x = Vec4f_Dot(a->c, b.a), .y = Vec4f_Dot(a->c, b.b), .z = Vec4f_Dot(a->c, b.c), .w = Vec4f_Dot(a->c, b.d)};
  Vec4f vecD = {.x = Vec4f_Dot(a->d, b.a), .y = Vec4f_Dot(a->d, b.b), .z = Vec4f_Dot(a->d, b.c), .w = Vec4f_Dot(a->d, b.d)};
  a->a = vecA;
  a->b = vecB;
  a->c = vecC;
  a->d = vecD;
  return;
}

Mat4f Mat4f_Identity() {
  Vec4f a = {.x = 1.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f};
  Vec4f b = {.x = 0.0f, .y = 1.0f, .z = 0.0f, .w = 0.0f};
  Vec4f c = {.x = 0.0f, .y = 0.0f, .z = 1.0f, .w = 0.0f};
  Vec4f d = {.x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 1.0f};
  Mat4f matrix = {.a = a, .b = b, .c = c, .d = d};
  return matrix;
}

// https://www.songho.ca/opengl/gl_projectionmatrix.html#ortho
Mat4f Mat4f_Ortho(float left, float right, float bottom, float top, float near, float far) {
  Vec4f a = {.x = 2/(right - left), .y = 0.0f, .z = 0.0f, .w = - (right + left)/(right - left)};
  Vec4f b = {.x = 0.0f, .y = 2/(top - bottom), .z = 0.0f, .w = - (top + bottom)/(top - bottom)};
  Vec4f c = {.x = 0.0f, .y = 0.0f, .z = -2/(far - near), .w = - (far + near)/(far - near)};
  Vec4f d = {.x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 1.0f};
  Mat4f matrix = {.a = a, .b = b, .c = c, .d = d};
  return matrix;
}

Mat4f Mat4f_Perspective(float FOVy, float aspect, float near, float far) {
  FOVy = FOVy *  M_PI / 180.0f;
  Vec4f a = {.x = 1/(aspect * (float) tan(FOVy/2)), .y = 0.0f, .z = 0.0f, .w = 0.0f};
  Vec4f b = {.x = 0.0f, .y = 1/((float) tan(FOVy/2)), .z = 0.0f, .w = 0.0f};
  Vec4f c = {.x = 0.0f, .y = 0.0f, .z = - (far + near)/(far - near), .w = -2 * far * near / (far - near)};
  Vec4f d = {.x = 0.0f, .y = 0.0f, .z = -1.0f, .w = 0.0f};
  Mat4f matrix = {.a = a, .b = b, .c = c, .d = d};
  return matrix;
}

void Mat4f_Rotate(Mat4f* matrix, float angle, Vec3f rotAxis) {
  angle =  (float) angle * M_PI/ 180.0f;
  
  Vec4f rotVecA = {
    .x = (float) (cos(angle) + rotAxis.x * rotAxis.x * (1 - cos(angle))),
    .y = (float) (rotAxis.x * rotAxis.y * (1 - cos(angle)) - rotAxis.z * sin(angle)),
    .z = (float) (rotAxis.x * rotAxis.z * (1 - cos(angle)) + rotAxis.y * sin(angle)),
    .w = 0
  };

  Vec4f rotVecB = {
    .x = (float) (rotAxis.y * rotAxis.x * (1 - cos(angle)) + rotAxis.z * sin(angle)),
    .y = (float) (cos(angle) + rotAxis.y * rotAxis.y * (1 - cos(angle))),
    .z = (float) (rotAxis.y * rotAxis.z * (1 - cos(angle)) - rotAxis.x * sin(angle)),
    .w = 0
  };

  Vec4f rotVecC = {
    .x = (float) (rotAxis.z * rotAxis.x * (1 - cos(angle)) - rotAxis.y * sin(angle)),
    .y = (float) (rotAxis.z * rotAxis.y * (1 - cos(angle)) + rotAxis.x * sin(angle)),
    .z = (float) (cos(angle) + rotAxis.z * rotAxis.z * (1 - cos(angle))),
    .w = 0
  };

  Vec4f rotVecD = {.x = 0, .y = 0, .z = 0, .w = 1};
  Mat4f rotMatrix = {.a = rotVecA, .b = rotVecB, .c = rotVecC, .d = rotVecD};

  Mat4f_Multiply(matrix, rotMatrix);
  return;
}
void Mat4f_Translate(Mat4f* matrix, Vec3f translation) {
  Mat4f translateMatrix = Mat4f_Identity();
  translateMatrix.a.w = translation.x;
  translateMatrix.b.w = translation.y;
  translateMatrix.c.w = translation.z;

  Mat4f_Multiply(matrix, translateMatrix);
}

void Mat4f_Scale(Mat4f* matrix, Vec3f scale);
