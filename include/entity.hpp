#ifndef PSM_ENTITY_H
#define PSM_ENTITY_H
namespace PSM
{
    class Entity
    {
    public:
        bool update();
        bool draw();

    private:
        int pos_x;
        int pos_y;
        int prev_pos_x;
        int prev_pos_y;
    };
}
#endif