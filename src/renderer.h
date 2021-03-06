#ifndef RENDERER_H
#define RENDERER_H

#include <vector>

#include "map.h"
#include "snake.h"
#ifdef __WIN32__
#include "SDL.h"
#elif __linux__
#include <SDL2/SDL.h>
#endif

class Renderer {
   public:
    Renderer(const std::size_t screen_width, const std::size_t screen_height,
             const std::size_t grid_width, const std::size_t grid_height);
    ~Renderer();

    void Render(Map map, Snake const snake, SDL_Point const &food);
    void UpdateWindowTitle(int score, int fps);

   private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;

    const std::size_t screen_width;
    const std::size_t screen_height;
    const std::size_t grid_width;
    const std::size_t grid_height;
};

#endif