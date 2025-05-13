#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

typedef struct Mat4f {
  Vec4f a;
  Vec4f b;
  Vec4f c;
  Vec4f d;
} Mat4f;

void Mat4f_Transpose(Mat4f* m);
Mat4f Mat4f_Ortho(float left, float right, float bottom, float top, float near, float far);
Mat4f Mat4f_Perspective(float FOVy, float aspect, float near, float far);
void Mat4f_Multiply(Mat4f* a, Mat4f b);
Mat4f Mat4f_Identity();
void Mat4f_Rotate(Mat4f* matrix, float angle, Vec3f rotAxis);
void Mat4f_Translate(Mat4f* matrix, Vec3f translation);
void Mat4f_Scale(Mat4f* matrix, Vec3f scale);

#endif
