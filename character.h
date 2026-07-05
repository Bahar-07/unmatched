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
    public:
        character();
        character(std::string ,int);
        std::string get_name();
        int get_hp();
        space* get_location();
        void set_location(space*);

};
#endif