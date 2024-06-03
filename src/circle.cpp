#include "circle.hpp"
#include "drawer.hpp"
namespace Entity {
    Circle::Circle(float x, float y){
        x_pos = x;
        y_pos = y;
    }
    void Circle::draw(SDL_Renderer * renderer) const{
        Renderer::Drawer::DrawCircle(renderer, x_pos, y_pos, 25);
    }
    void Circle::update(){

    }
    float Circle::getX() const{
        return x_pos;
    }
    float Circle::getY() const{
        return y_pos;
    }   

}
