#ifndef CIRCLE_H
#define CIRCLE_H
#include "entity.hpp"
namespace Entity {

class Circle : public Entity::EntityInterface {
public:
    Circle(float x, float y);

    virtual void draw() const = 0;
    virtual void update() = 0;
    virtual float getX() const = 0;
    virtual float getY() const = 0;

    virtual ~Circle() {}
private:
    float x_pos;
    float y_pos;
};

} 

#endif 