#ifndef PLATFORM_WINDOW_H
#define PLATFORM_WINDOW_H

#include <stdint.h>
#include <stdbool.h>

typedef struct PlatformWindow PlatformWindow;

typedef struct WindowConfig {
    const char* title;
    int width;
    int height;
    bool vsync;
    bool resizable;
    bool fullscreen;
} WindowConfig;

typedef struct PlatformContext {
    PlatformWindow* window;
    bool is_running;
    uint32_t width;
    uint32_t height;
} PlatformContext;

bool platform_init(PlatformContext* ctx, const WindowConfig* config);
void platform_poll_events(PlatformContext* ctx);
void platform_shutdown(PlatformContext* ctx);
double platform_get_time_seconds();

#endif
