#ifndef _GAME
#define _GAME
#include "space.h"
#include "character.h"
#include "card.h"
#include "map.h"
#include "ui.h"
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
        std::vector<space*> fogs;
        std::vector<card> deck;
        std::vector<card> hand;
        std::vector<card> c;
        std::vector<card> b;
        int action;
        bool alivee;
        int damage;
    public:
        game(std::string );
        game(std::string, std::string);
        void age(game &, map& , ui);
        void choose_location(game &, map& , ui);
        void choose_character(game &, map& , ui);
        std::string get_age();
        std::string get_name_player();
        bool alive();
        void start_game(game & , map & , ui);
        void pick_card(game &);
        void creat_deck();
        void card_effects(card* , game & , map& , ui , card* = nullptr );
        void feeding_frenzy(card &);
        void mistform(map & , ui);
        void ambush(card& ,game &);
        void choose_fighter(game & , map & , ui);
        void choose_target(game& , ui);
        void baptism_of_blood(map & , ui);
        void beastform(card& , ui);
        void dash(map& , ui);
        void expolit();
        void look_into_my_eyes(game &, card & , card*);
        void prey_upon(map & , game & );
        void attack(game& , map & , card* , ui, card* = nullptr );
        void administer_aid(map& , ui);
        void counterpunch(map& , game& , ui);
        std::vector <character*> get_neighborenemy(character& , game&);
        std::vector <character*> get_neighborenemyzone(character&, game&);
        void education_never_ends(game &);
        void eliminate_the_impossible(game& , ui);
        void fixed_point_in_a_changing_age(game&);
        void master_of_disguise(game & , map & , ui);
        void the_game_is_afoot(map & , ui);
        void study_methods(game & , ui);
        void thirst_for_sustenance(map&);
        void deduce_strategy(card& , card*);
        std::vector <space*> get_fog();
        void coded_notes(ui);
        void covert(map& , ui);
        void dreaming(game&);
        void emerge_from_mist(card&);
        void impossible_to_see(card*);
        void into_thin_air(map& , ui);
        void lurking(ui , map&);
        void reign_of_terror(game&);
        void rolling_fog(map& , ui);
        void slip_away();
        void step_lightly(game&);
        void vanish();
        void save(std::string , game);
        void load_game(std::string ,map& , int );
        character get_hero();
        int get_nhand();
        int get_ndeck();
        std::vector<character> get_sidekicks();
};

#endif