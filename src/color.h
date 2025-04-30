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

// - Casting - //
Color3i Color_Convert(Color3f* old);

// -- Math -- //
void Color_Multiply(Color3f* color, float f);
