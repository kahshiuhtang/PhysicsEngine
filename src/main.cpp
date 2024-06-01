#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include "kernel.cuh"
#include <cstdlib>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 512), "Physics Engine");
    sf::CircleShape circle(20.f);
    circle.setFillColor(sf::Color::Green);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(375.0f, 275.0f);  
    float currentVel = 0.0f;
    float currentPos = 275.0f;
    float const gravity = 9.8f;
    float time = 0.01;
    bool hitGround = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }else if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Left){
                    circle.move(-2, 0);
                }
                else if(event.key.code == sf::Keyboard::Right){
                    circle.move(2, 0);
                }
                else if(event.key.code == sf::Keyboard::Up){
                    circle.move(0, -2);
                }
                else if(event.key.code == sf::Keyboard::Down){
                    circle.move(0, 2);
                }
            }
        }
        double a,b,c;
        kernel(&a, &b, &c, 5);
        window.clear();
        circle.setPosition(375.0f, currentPos); 
        window.draw(circle);
        window.display();
        std::cout << currentPos << "\n";
        if(hitGround || currentPos > 500){
            hitGround = true;
            currentPos -= currentVel;
        }else{
            currentPos = currentPos - (0.5 * - gravity * time * time) / 10;
            currentVel = (gravity * time ) / 10;
        }
        if(currentPos < 10){
            hitGround = false;
        }
        time += 0.01;
        usleep(10000);
    }

    return 0;
}