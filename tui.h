#ifndef _TUI
#define _TUI
#include "map.h"
#include "space.h"
#include <string>
class tui
{
    public:
        int main_menu();
        int action_menu();
        int agee(std::string , std::string);
        int choose_character();
        int choose_space(map& , std::string , std::vector<int>);
        int yesorno(std::string);
        int choose_acharacter(std::string,std::vector<std::string>);
    
};
#endif