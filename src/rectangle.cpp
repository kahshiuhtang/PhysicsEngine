#include "rectangle.hpp"

namespace Entity {
    Rectangle::Rectangle(float x, float y){
        x_pos = x;
        y_pos = y;
    }
    void Rectangle::draw() const{

    }
    void Rectangle::update(){

    }
    float Rectangle::getX() const{
        return x_pos;
    }
    float Rectangle::getY() const{
        return y_pos;
    }   

}