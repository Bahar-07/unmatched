#ifndef _CHARACTER
#define _CHARACTER
#include <string>
#include "space.h"

class space;

class character
{
    private:
        std::string name;
        int hp;
        space * location;
        int move;
        bool status;
    public:
        character();
        character(std::string ,int , int);
        std::string get_name();
        int get_hp();
        void set_hp(int);
        bool get_status();
        space* get_location();
        void set_location(space*);
        int get_move();
        void set_status();
};
#endif