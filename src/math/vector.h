#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vec2f {
  float u;
  float v;
} Vec2f;

typedef struct Vec3f {
  float x;
  float y;
  float z;
} Vec3f;

typedef struct Vec4f {
  float x;
  float y;
  float z;
  float w;
} Vec4f;

// -- Vec2 Functions -- //
Vec2f Vec2f_AddFloat(Vec2f vec, float f);
Vec2f Vec2f_AddVec2(Vec2f a, Vec2f b);
Vec2f Vec2f_Multiply(Vec2f vec, float f);
float Vec2f_Dot(Vec2f a, Vec2f b);
Vec2f Vec2f_Normailze(Vec2f vec);
float Vec2f_Magnitude(Vec2f vec);
Vec2f Vec2f_Orthogonal(Vec2f vec);

// -- Vec3 Functions -- //
Vec3f Vec3f_AddFloat(Vec3f vec, float f);
Vec3f Vec3f_AddVec3(Vec3f a, Vec3f b);
Vec3f Vec3f_Multiply(Vec3f vec, float f);
float Vec3f_Dot(Vec3f a, Vec3f b);
Vec3f Vec3f_Normailze(Vec3f vec);
float Vec3f_Magnitude(Vec3f vec);
Vec3f Vec3f_Cross(Vec3f a, Vec3f b);

// -- Vec4 Functions -- //
Vec4f Vec4f_AddFloat(Vec4f vec, float f);
Vec4f Vec4f_AddVec4(Vec4f a, Vec4f b);
Vec4f Vec4f_Multiply(Vec4f vec, float f);
float Vec4f_Dot(Vec4f a, Vec4f b);
Vec4f Vec4f_Normailze(Vec4f vec);
float Vec4f_Magnitude(Vec4f vec);

#endif



