#ifndef COLOR_H
#define COLOR_H

// - 3 Channel Colors - //
typedef struct {
  float r;
  float g;
  float b;
} Color3f;

typedef struct {
  int r;
  int g;
  int b;
} Color3i;

typedef struct ColorBuffer {
  int size;
  Color3i buffer[];
} ColorBuffer;

// - Casting - //
Color3i Color_Convert(Color3f* old);

// -- Math -- //
void Color_Multiply(Color3f* color, float f);

#endif
