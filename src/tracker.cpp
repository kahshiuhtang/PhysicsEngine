#include "tracker.hpp"
#include "circle.hpp"
namespace Tracker{
    Tracker::Tracker(int window_width, int window_height, std::string window_name){

    }
    void Tracker::draw(const Entity::EntityInterface& entity) const{

    }
    void Tracker::update(){

    }
    std::unique_ptr<Entity::EntityInterface> Tracker::create_obj(Shape shape){
        switch(shape){
            case Shape::CIRCLE:
                return std::make_unique<Entity::Circle>(350.0f, 250.0f);
            case Shape::TRIANGLE:
                break;
            default:
                break;
        }
    } 
}