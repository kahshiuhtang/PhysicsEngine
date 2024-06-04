#ifndef FORCE_GEN_H
#define FORCE_GEN_H
#include "state.hpp"
namespace Engine{
    class ForceGenerator{
        public:
            ForceGenerator();
            virtual ~ForceGenerator();

            virtual void apply(State *system) = 0;


    };  
}
#endif