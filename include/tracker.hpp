#ifndef TRACKER_H
#define TRACKER_H
#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include <string>
namespace Tracker {

class Tracker {
public:
    Tracker(int window_width, int window_height, std::string window_name);

    virtual void draw(const Entity::EntityInterface& entity) const = 0;
    virtual void update() = 0;

    virtual ~Tracker() {}
private:
    float x_pos;
    float y_pos;
    sf::RenderWindow window;
};

} 

#endif 