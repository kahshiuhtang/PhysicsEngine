#include "circle.hpp"
#include "drawer.hpp"
#include "consts.hpp"
#include <iostream>
namespace Entity {
    Circle::Circle(float x, float y, int window_width, int window_height){
        x_pos = x;
        y_pos = y;
        x_vel = 0.0f;
        y_vel = 0.0f;
        wind_width = window_width;
        wind_height = window_height;
    }
    void Circle::draw(SDL_Renderer * renderer) const{
        Renderer::Drawer::DrawCircle(renderer, x_pos, y_pos, 25);
    }
    void Circle::update(){
        y_vel += (GRAVITY * DELTA);
        y_pos += y_vel * DELTA;
        if (y_pos > wind_height) {
            y_vel = -y_vel * BOUNCE_FACTOR;
            if (std::abs(y_vel) < 0.1f) {
                y_vel = 0;
            }
        }
        std::cout << y_pos << std::endl;
    }
    float Circle::getX() const{
        return x_pos;
    }
    float Circle::getY() const{
        return y_pos;
    }   

}
