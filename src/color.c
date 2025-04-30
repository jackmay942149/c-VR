#include "color.h"

Color3i Color_Convert(Color3f* old){
  Color3i new;
  new.r = (int) old->r;
  new.g = (int) old->g;
  new.b = (int) old->b;
  return new;
}

void Color_Multiply(Color3f* color, float f){
  color->r *= f;
  color->g *= f;
  color->b *= f;
}
