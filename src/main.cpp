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
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main()
{
	Engine::Tracker tracker(SCREEN_WIDTH, SCREEN_HEIGHT, "Physics Simulator");
	tracker.create_obj(Engine::Shape::CIRCLE);
	tracker.main_loop();
    return 0;
}