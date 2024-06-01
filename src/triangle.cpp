#include "triangle.hpp"

namespace Entity {
    Triangle::Triangle(float x, float y){
        x_pos = x;
        y_pos = y;
    }
    void Triangle::draw() const{

    }
    void Triangle::update(){

    }
    float Triangle::getX() const{
        return x_pos;
    }
    float Triangle::getY() const{
        return y_pos;
    }   

}