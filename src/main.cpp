#include <SDL2/SDL.h>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include "kernel.cuh"
#include <cstdlib>
#include <stdio.h>
#include "tracker.hpp"
#include "circle.hpp"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main()
{
	Engine::Tracker tracker(800, 600, "Physics Simulator");
	Entity::Circle circle(400.0f, 300.0f);
	tracker.draw(circle);
	tracker.main_loop();
    return 0;
}