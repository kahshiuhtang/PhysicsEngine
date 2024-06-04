#include "tracker.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
#include <cstdlib> 
#include <iostream>
namespace Engine{
    Tracker::Tracker(int window_width, int window_height, const char *window_name){
        wind_height = window_height;
        wind_width = window_width;
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
    void Tracker::draw() const{
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White
        for (const auto& entity : entities) {
            entity->draw(renderer);
        }
        SDL_RenderPresent(renderer);
    }
    void Tracker::update(){
        for (const auto& entity : entities) {
            entity->update();
        }
    }
    std::shared_ptr<Entity::EntityInterface> Tracker::create_obj(Shape shape){
        switch(shape){
            case Shape::CIRCLE: {
                std::shared_ptr<Entity::Circle> new_circle = std::make_shared<Entity::Circle>(350.0f, 250.0f, wind_width, wind_height);
                entities.push_back(new_circle);
                return new_circle;
            }
            case Shape::TRIANGLE: {
                std::shared_ptr<Entity::Triangle> new_triangle = std::make_shared<Entity::Triangle>(350.0f, 250.0f);
                entities.push_back(new_triangle);
                return new_triangle;
            }
            case Shape::RECTANGLE: {
                std::shared_ptr<Entity::Rectangle> new_rectangle = std::make_shared<Entity::Rectangle>(350.0f, 250.0f);
                entities.push_back(new_rectangle);
                return new_rectangle;
            }
            default:
                return nullptr;
        }
    } 
    int Tracker::main_loop(){
        SDL_Event e; 
        bool quit = false; 
        while( quit == false ){ 
            SDL_PollEvent( &e );
            if( e.type == SDL_QUIT ) 
                quit = true; 
            update();
            draw();
            SDL_Delay(10);
        }
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;

        
    }
    Tracker::~Tracker() {
    }
}