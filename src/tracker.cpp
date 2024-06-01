#include "tracker.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
namespace Tracker{
    Tracker::Tracker(int window_width, int window_height, std::string window_name){

    }
    void Tracker::draw(const Entity::EntityInterface& entity) const{
        entity.draw();
    }
    void Tracker::update(){

    }
    std::shared_ptr<Entity::EntityInterface> Tracker::create_obj(Shape shape){
        switch(shape){
            case Shape::CIRCLE:
                return std::make_shared<Entity::Circle>(350.0f, 250.0f);
            case Shape::TRIANGLE:
                return std::make_shared<Entity::Triangle>(350.0f, 250.0f);
            case Shape::RECTANGLE:
                return std::make_shared<Entity::Rectangle>(350.0f, 250.0f);
            default:
                return nullptr;
        }
    } 
}