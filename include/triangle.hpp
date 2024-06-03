#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "entity.hpp"
namespace Entity {

class Triangle : public Entity::EntityInterface {
public:
    Triangle(float x, float y);

    void draw(SDL_Renderer * renderer) const;
    void update();
    float getX() const;
    float getY() const;

    ~Triangle() {}
private:
    float x_pos;
    float y_pos;
};

} 

#endif 