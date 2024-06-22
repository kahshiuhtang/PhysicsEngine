#ifndef PSM_SYSTEM_STATE_H
#define PSM_SYSTEM_STATE_H

#include <vector>
#include "entity.hpp"
namespace PSM
{
    class SystemState
    {
    public:
        bool init();
        bool create_objects(int cnt);
        bool create_object(int *pos);
        bool update();

    private:
        std::vector<PSM::Entity *> objects;
    };
}
#endif