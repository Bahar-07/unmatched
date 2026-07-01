#ifndef _MAP
#define _MAP
#include "space.h"
#include <vector>

class space;
class map
{
    private:
        std::vector <space> spaces;
    public:
        map();
        space * get_space(int);
        void neighborr();
};
#endif