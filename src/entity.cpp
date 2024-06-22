#include "entity.hpp"

namespace PSM
{
    bool Entity::init()
    {
        bool err = false;
        pos = new int[3];
        old_pos = new int[3];
        return err;
    }
    bool Entity::destroy()
    {
        bool err = false;
        delete pos;
        delete old_pos;
        return err;
    }
}