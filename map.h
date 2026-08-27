#ifndef _MAP
#define _MAP
#include "space.h"
#include "ui.h"
#include "game.h"
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
        void move(std::string ,int, character& , map &  , ui );
        void move2(character& ,ui);
        void move3(character& ,character& , map&, ui);
        int pray_upon(character&);
        void move_invisibleman(std::string ,int , character& , map & , game & , ui);
        void set_locationf(std::string , int );
};
#endif