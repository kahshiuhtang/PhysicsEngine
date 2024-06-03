#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "entity.hpp"
namespace Entity {

class Rectangle : public Entity::EntityInterface {
public:
    Rectangle(float x, float y);

    void draw(SDL_Renderer * renderer) const;
    void update();
    float getX() const;
    float getY() const;

    ~Rectangle() {}
private:
    float x_pos;
    float y_pos;
};

} 

#endif 