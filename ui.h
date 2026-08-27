#ifndef _UI
#define _UI
#include "raylib.h"
#include <string>
#include <vector>
class map;
class game;
class card;
class character;
class ui
{
    public:
        int action_menu();
        int agee(std::string , std::string);
        int choose_character(game);
        int choose_space(map& , std::string , std::vector<int> );
        int yesorno(std::string);
        int choose_acharacter(std::string,std::vector<std::string>);
        std::string get_text_input(std::string);
        bool button(Rectangle ,const char* );
        int draw_game_screen(game& player1, game& player2, map& g);
        bool draw_status_window(game& player, bool enemy);
        void p(std::string);
        int choose_card( std::vector<card>&);
        int choose_aacharacter(std::string ,std::vector<character*> );
        bool show_card(std::vector<card>&);
        void showsomthing(std::string , int);
        void showhelp(std::string , int);
};
#endif