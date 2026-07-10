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
        void show_map();
        void set_location(std::string , int);
        int move(std::string ,int, character&);
        void move2(character&);
        void move3(character& ,character& , map&);
        bool neighbor_status(character&);
        bool get_draculaandsisters_neighbors(character &);
        bool get_sherlock_neighbors(character &);
        int pray_upon(character&);
};
#endif