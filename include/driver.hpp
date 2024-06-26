#ifndef PSM_DRIVER_H
#define PSM_DRIVER_H

#include "renderer.hpp"
#include "solver.hpp"
#include "system_state.hpp"

namespace PSM
{
    class Driver
    {
    public:
        Driver();
        bool init();
        bool add_object(int *pos);
        bool run();
        bool stop();

    private:
        Renderer renderer;
        Solver solver;
        SystemState state;

        bool _setup_window();
        bool _setup_gui();
        bool _update();
    };
}
#endif