#include "wasm4.h"
#include "math.h"
#include "sprites.h"

u8 x, y, dx, dy;

void start() {
  PALETTE[0] = (u8)0xfff6d3;
  PALETTE[1] = (u8)0xf9a875;
  PALETTE[2] = (u8)0xeb6b6f;
  PALETTE[3] = (u8)0x7c3f58;

  dx = 1;
  dy = 1;
  x = 20;
  y = 35;
}

void update () {
  *DRAW_COLORS=0x12;
  text("HELLO WORLD", 10, 10);

  *DRAW_COLORS=0x34;
  blit(sprite, x, y, 8, 8, BLIT_1BPP);
  x = x + dx;
  y = y + dy;
  if (x >= (160 - 8) || x <= 0) { dx *= -1; }
  if (y >= (160 - 8) || y <= 0) { dy *= -1; }
}
