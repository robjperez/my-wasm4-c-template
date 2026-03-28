#include "math.h"

u8 clamp(i16 x, u8 min, u8 max) {
    return x >= max ? max : (x <= min ? min : x);
}

float clampf(float x, float min, float max) {
  return x >= max ? max : (x <= min ? min : x);
}
