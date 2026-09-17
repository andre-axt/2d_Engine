#ifndef PLATFORM_WINDOW_H
#define PLATFORM_WINDOW_H

#include <stdint.h>

// merely declared so far
typedef struct PlatformWindow PlatformWindow;
typedef struct PlatformGfx    PlatformGfx;
typedef struct PlatformContext PlatformContext;

int8_t platform_init(PlatformContext* ctx, const char* title, int w, int h);
void platform_shutdown(PlatformContext* ctx);

#endif
