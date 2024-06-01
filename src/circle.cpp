#include "circle.hpp"

namespace Entity {
    Circle::Circle(float x, float y){
        x_pos = x;
        y_pos = y;
    }
    void Circle::draw() const{

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
