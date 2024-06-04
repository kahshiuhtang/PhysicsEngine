#ifndef CIRCLE_H
#define CIRCLE_H
#include "entity.hpp"
namespace Entity {

class Circle : public Entity::EntityInterface {
public:
    Circle(float x, float y, int window_width, int window_height);

    void draw(SDL_Renderer * renderer) const;
    void update();
    float getX() const;
    float getY() const;

    ~Circle() {}
private:
    float x_pos;
    float y_pos;
    float x_vel;
    float y_vel;

    int wind_width;
    int wind_height;
};

} 

#endif 