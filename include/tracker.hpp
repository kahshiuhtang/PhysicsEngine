#ifndef TRACKER_H
#define TRACKER_H
#include <string>
#include "entity.hpp"
#include <memory>
namespace Tracker {

enum Shape {
    CIRCLE,
    TRIANGLE
};

class Tracker {
public:
    Tracker(int window_width, int window_height, std::string window_name);

    void draw(const Entity::EntityInterface& entity) const;
    void update();
    std::unique_ptr<Entity::EntityInterface> create_obj(Shape shape);

    virtual ~Tracker() {}
private:
    float x_pos;
    float y_pos;
};

} 

#endif 