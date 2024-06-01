#include "tracker.hpp"

namespace Tracker{
    Tracker::Tracker(int window_width, int window_height, std::string window_name) : window(sf::VideoMode(window_width, window_height), window_name){

    }
    void Tracker::draw(const Entity::EntityInterface& entity) const{

    }
    void Tracker::update(){

    }
}