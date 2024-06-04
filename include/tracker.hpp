#ifndef TRACKER_H
#define TRACKER_H
#include "entity.hpp"
#include <memory>
#include <vector>
#include <SDL2/SDL.h>
namespace Engine {

enum Shape {
    CIRCLE,
    TRIANGLE,
    RECTANGLE,
};

class Tracker {
public:
    Tracker(int window_width, int window_height, const char *window_name);

    void draw() const;
    int main_loop();
    void update();
    std::shared_ptr<Entity::EntityInterface> create_obj(Shape shape);

    ~Tracker();
private:
    std::vector<std::shared_ptr<Entity::EntityInterface>> entities;
    SDL_Renderer* renderer;
    SDL_Window* window;

    int wind_height;
    int wind_width;
};

} 

#endif 