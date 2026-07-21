#ifndef _MAP
#define _MAP
#include "space.h"
#include <vector>
#include <string>
#include "character.h"

class space;
class map
{
    private:
        std::vector <space> spaces;
    public:
        map();
        space * get_space(int);
        void neighborr();
        void secret_pass();
        void show_map();
        void set_location(std::string , int);
        void move(std::string ,int, character& , map & g);
        void move2(character&);
        void move3(character& ,character& , map&);
        int pray_upon(character&);
};
#endif