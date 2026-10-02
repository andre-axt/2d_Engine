#include "platform_window.h"
#include <SDL2/SDL.h>
#include <stdlib.h>

struct PlatformWindow {
    SDL_Window* sdl_window;
    SDL_Renderer* sdl_renderer;
};

bool platform_init(PlatformContext* ctx, const WindowConfig* config) {
    if (!ctx || !config) return false;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }

    Uint32 window_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI;
    if (config->resizable)  window_flags |= SDL_WINDOW_RESIZABLE;
    if (config->fullscreen) window_flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;

    SDL_Window* sdl_win = SDL_CreateWindow(
        config->title ? config->title : "2D Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        config->width,
        config->height,
        window_flags
    );

    if (!sdl_win) {
        SDL_Log("Failed to create SDL Window: %s", SDL_GetError());
        SDL_Quit();
        return false;
    }

    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    if (config->vsync) {
        render_flags |= SDL_RENDERER_PRESENTVSYNC;
    }

    SDL_Renderer* sdl_ren = SDL_CreateRenderer(sdl_win, -1, render_flags);
    if (!sdl_ren) {
        SDL_Log("Failed to create SDL Renderer: %s", SDL_GetError());
        SDL_DestroyWindow(sdl_win);
        SDL_Quit();
        return false;
    }

    PlatformWindow* win = (PlatformWindow*)malloc(sizeof(PlatformWindow));
    if (!win) {
        SDL_DestroyRenderer(sdl_ren);
        SDL_DestroyWindow(sdl_win);
        SDL_Quit();
        return false;
    }

    win->sdl_window = sdl_win;
    win->sdl_renderer = sdl_ren;

    ctx->window = win;
    ctx->is_running = true;
    ctx->width = config->width;
    ctx->height = config->height;

    return true;
}

void platform_poll_events(PlatformContext* ctx) {
    if (!ctx) return;

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                ctx->is_running = false;
                break;

            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    ctx->width = (uint32_t)event.window.data1;
                    ctx->height = (uint32_t)event.window.data2;
                }
                break;

            default:
                break;
        }
    }
}

double platform_get_time_seconds(void) {
    static uint64_t frequency = 0;
    if (frequency == 0) {
        frequency = SDL_GetPerformanceFrequency();
    }
    return (double)SDL_GetPerformanceCounter() / (double)frequency;
}

void platform_shutdown(PlatformContext* ctx) {
    if (!ctx || !ctx->window) return;

    if (ctx->window->sdl_renderer) {
        SDL_DestroyRenderer(ctx->window->sdl_renderer);
    }
    if (ctx->window->sdl_window) {
        SDL_DestroyWindow(ctx->window->sdl_window);
    }

    free(ctx->window);
    ctx->window = NULL;

    SDL_Quit();
    ctx->is_running = false;
}
