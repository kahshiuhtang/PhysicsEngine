#ifndef ENTITY_H
#define ENTITY_H

namespace Entity {

class EntityInterface {
public:
    virtual void draw() const = 0;
    virtual void update() = 0;
    virtual float getX() const = 0;
    virtual float getY() const = 0;
};

} 

#endif 
