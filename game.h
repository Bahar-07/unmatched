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
    protected:
        std::string name;
        std::string yoro;
        character hero;
        character target;
        character active_character;
        std::vector<character> sidekicks;
        std::vector<card> deck;
        std::vector<card> hand;
        std::vector<card> c;
        std::vector<card> b;
        std::vector<card> discard;
        int action;
        bool alivee;
    public:
        game();
        void age(game &, map&);
        void choose_location(game &, map&);
        void choose_character(game &, map&);
        std::string get_age();
        std::string get_name_player();
        bool alive();
        void start_game(game & , map &);
        void pick_card(game &);
        void creat_deck();
        void effects(card& , game & , map& , card* = nullptr);
        void feeding_frenzy(card &);
        void mistform(map &);
        void ambush(card& ,game &);
        void choose_fighter(game & , map &);
        void choose_target(game&);
        void baptism_of_blood(map &);
        void beastform(card&);
        void dash(map&);
        void expolit();
        void look_into_my_eyes(game &, card & , card&);
        void prey_upon(map & , game & );
};

#endif