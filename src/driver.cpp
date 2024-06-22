#include "driver.hpp"

namespace PSM
{
    Driver::Driver()
    {
    }
    bool Driver::init()
    {
        bool err = false;
        _setup_gui();
        return err;
    }
    bool Driver::create_objects()
    {
        bool err = false;

        return err;
    }
    bool Driver::run()
    {
        bool err = false;
        SDL_Event e;
        bool quit = false;
        while (quit == false)
        {
            SDL_PollEvent(&e);
            if (e.type == SDL_QUIT)
                quit = true;
            // update();
            // draw();
            SDL_Delay(10);
        }
        return err;
    }
    bool Driver::_setup_gui()
    {
        bool err = false;
        renderer.init(800, 800);
        return err;
    }
    bool Driver::_update()
    {
        bool err = false;
        return err;
    }
    bool Driver::stop()
    {
        bool err = false;

        return err;
    }
}