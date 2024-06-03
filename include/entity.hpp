#ifndef ENTITY_H
#define ENTITY_H
#include <SDL2/SDL.h>
namespace Entity {

class EntityInterface {
public:
    virtual void draw(SDL_Renderer * renderer) const = 0;
    virtual void update() = 0;
    virtual float getX() const = 0;
    virtual float getY() const = 0;
};

} 

#endif 
