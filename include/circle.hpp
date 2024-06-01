#ifndef CIRCLE_H
#define CIRCLE_H
#include "entity.hpp"
namespace Entity {

class Circle : public Entity::EntityInterface {
public:
    Circle(float x, float y);

    void draw() const;
    void update();
    float getX() const;
    float getY() const;

    ~Circle() {}
private:
    float x_pos;
    float y_pos;
};

} 

#endif 