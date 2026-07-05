#ifndef _GAME
#define _GAME
#include "space.h"
#include "character.h"
#include "card.h"
#include "map.h"
#include <vector>
#include <string>



class game
{
    private:
        std::string name;
        std::string yoro;
        character hero;
        std::vector<character> sidekicks;
        std::vector<card> deck;
        std::vector<card> hand;
        std::vector<card> discard;
        bool alivee = true;
    public:
        game();
        void age(game &, map&);
        void choose_location(game &, map&);
        void choose_character(game &, map&);
        std::string get_age();
        std::string get_name_player();
        bool alive();
        void start_game(game & , map &);
        void creat_deck();
};
#endif