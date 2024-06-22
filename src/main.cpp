#include "driver.hpp"

int main()
{
    psim::Driver driver;
    if (driver.init())
    {
        return EXIT_FAILURE;
    }
    if (driver.run())
    {
        return EXIT_FAILURE;
    }
    if (driver.stop())
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}