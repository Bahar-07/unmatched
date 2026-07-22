#ifndef _GAME
#define _GAME
#include "space.h"
#include "character.h"
#include "card.h"
#include "map.h"
#include "tui.h"
#include <vector>
#include <string>



class game
{
    protected:
        std::string name;
        std::string yoro;
        character  hero;
        character* target;
        character* active_character;
        std::vector<character> sidekicks;
        std::vector<card> deck;
        std::vector<card> hand;
        std::vector<card> c;
        std::vector<card> b;
        int action;
        bool alivee;
        int damage;
    public:
        game();
        void age(game &, map& , tui);
        void choose_location(game &, map& , tui);
        void choose_character(game &, map& , tui);
        std::string get_age();
        std::string get_name_player();
        bool alive();
        void start_game(game & , map & , tui);
        void pick_card(game &);
        void creat_deck();
        void card_effects(card* , game & , map& , card* = nullptr);
        void feeding_frenzy(card &);
        void mistform(map &);
        void ambush(card& ,game &);
        void choose_fighter(game & , map &);
        void choose_target(game&);
        void baptism_of_blood(map &);
        void beastform(card&);
        void dash(map&);
        void expolit();
        void look_into_my_eyes(game &, card & , card*);
        void prey_upon(map & , game & );
        void attack(game& , map & , card* , card* = nullptr);
        void administer_aid(map&);
        void counterpunch(map& , game&);
        std::vector <character*> get_neighborenemy(character& , game&);
        std::vector <character*> get_neighborenemyzone(character&, game&);
        void education_never_ends(game &);
        void eliminate_the_impossible(game&);
        void fixed_point_in_a_changing_age(game&);
        void master_of_disguise(game & , map &);
        void the_game_is_afoot(map &);
        void study_methods(game &);
        void thirst_for_sustenance(map&);
        void deduce_strategy(card& , card*);
};

#endif