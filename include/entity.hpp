#ifndef PSM_ENTITY_H
#define PSM_ENTITY_H
namespace PSM
{
    class Entity
    {
    public:
        bool init();
        bool update();
        bool draw();
        bool destroy();

    private:
        int *pos; // array of size 3
        int *old_pos;
        float mass;
    };
}
#endif