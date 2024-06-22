#ifndef PSM_RENDERER_STATE_H
#define PSM_RENDERER_STATE_H
#include <SDL2/SDL.h>
#include <iostream>

namespace PSM
{
    class Renderer
    {
    public:
        bool init(int w_height, int w_width);
        bool update();
        bool destroy();

    private:
        SDL_Renderer *renderer;
        SDL_Window *window;

        int window_height;
        int window_width;
    };
}
#endif