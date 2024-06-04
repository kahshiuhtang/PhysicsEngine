#ifndef DRAWER_H
#define DRAWER_H
#include <SDL2/SDL.h>
namespace Renderer {

class Drawer {
public:

    static int DrawCircle(SDL_Renderer * renderer, int x, int y, int radius);
    static int FillCircle(SDL_Renderer * renderer, int x, int y, int radius);

    ~Drawer() {}
private:
    float x_pos;
    float y_pos;
};

} 

#endif 