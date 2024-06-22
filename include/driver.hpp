#ifndef PSIM_DRIVER_H
#define PSIM_DRIVER_H

#include "renderer.hpp"
#include "solver.hpp"
#include "system_state.hpp"

namespace psim
{
    class Driver
    {
    public:
        Driver();
        bool init();
        bool create_objects();
        bool run();
        bool stop();

    private:
        Renderer renderer;
        Solver solver;
        SystemState state;

        bool _setup_gui();
        bool _update();
    };
}
#endif