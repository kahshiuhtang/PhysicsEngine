#include "tracker.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
#include <cstdlib> 
#include <iostream>
namespace Engine{
    Tracker::Tracker(int window_width, int window_height, const char *window_name){
        if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
            printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
            exit(EXIT_FAILURE);
        }

        window = SDL_CreateWindow( window_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN );
        if( window == NULL ){
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            exit(EXIT_FAILURE);
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if (!renderer) {
            std::cerr << "Could not create renderer: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(window);
            SDL_Quit();
            exit(EXIT_FAILURE);
        }

    }
    void Tracker::draw(const Entity::EntityInterface& entity) const{
        //entity.draw();
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        //DrawCircle(renderer, 250, 250, 50);
        SDL_RenderPresent(renderer);
        SDL_Delay(5000);
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
    int Tracker::main_loop(){
        SDL_Event e; 
        bool quit = false; 
        while( quit == false ){ 
            while( SDL_PollEvent( &e ) ){ 
                if( e.type == SDL_QUIT ) 
                    quit = true; 
            }
        }
        return 0;
    }
    Tracker::~Tracker() {
        SDL_DestroyWindow( window );
	    SDL_Quit();
    }
}