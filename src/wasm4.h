// wasm4.h
#ifndef WASM4_H
#define WASM4_H

#include "types.h"

// Convenience macros
#define PALETTE ((u8*)0x4)
#define FRAMEBUFFER ((u8*)0xa0)
#define DRAW_COLORS ((u8*)0x14)
#define GAMEPAD1 ((u8*)0x16)
/* #define GAMEPAD2_PTR ((unsigned char*)&GAMEPAD2) */
/* #define GAMEPAD3_PTR ((unsigned char*)&GAMEPAD3) */
/* #define GAMEPAD4_PTR ((unsigned char*)&GAMEPAD4) */
/* #define MOUSE_X_PTR ((unsigned char*)&MOUSE_X) */
/* #define MOUSE_Y_PTR ((unsigned char*)&MOUSE_Y) */
/* #define MOUSE_BUTTONS_PTR ((unsigned char*)&MOUSE_BUTTONS) */

// Imported functions - attributes work here!
__attribute__((import_module("env"), import_name("blit")))
extern void blit(const unsigned char* data, int x, int y, int width, int height, int flags);

__attribute__((import_module("env"), import_name("blitSub")))
extern void blitSub(const unsigned char* data, int x, int y, int width, int height, int srcX, int srcY, int stride, int flags);

__attribute__((import_module("env"), import_name("line")))
extern void line(int x1, int y1, int x2, int y2);

__attribute__((import_module("env"), import_name("hline")))
extern void hline(int x, int y, int len);

__attribute__((import_module("env"), import_name("vline")))
extern void vline(int x, int y, int len);

__attribute__((import_module("env"), import_name("oval")))
extern void oval(int x, int y, int width, int height);

__attribute__((import_module("env"), import_name("rect")))
extern void rect(int x, int y, int width, int height);

__attribute__((import_module("env"), import_name("text")))
extern void text(const char* str, int x, int y);

__attribute__((import_module("env"), import_name("tone")))
extern void tone(int frequency, int duration, int volume, int flags);

/** Prints a message to the debug console. */
__attribute__((__format__ (__printf__, 1, 2)))
__attribute__((import_module("env"), import_name("tracef")))
void tracef (const char* fmt, ...);

// Constants
#define BUTTON_LEFT   16
#define BUTTON_RIGHT  32
#define BUTTON_UP     64
#define BUTTON_DOWN   128
#define BUTTON_1      1
#define BUTTON_2      2

#define BLIT_1BPP     0
#define BLIT_2BPP     1
#define BLIT_ROTATE   2
#define BLIT_FLIP_X   4
#define BLIT_FLIP_Y   8

#endif
