#ifndef _CARD
#define _CARD
#include <iostream>

enum class cardtype
{
    attack,
    defense,
    versatile,
    scheme
};
enum class cardowner
{
    hero,
    sidekick,
    any
};
enum class timing
{
    beforcombat,
    duringccombat,
    aftercombat,
    none
};

class card
{
    private:
        std::string name;
        cardtype type;
        cardowner owner;
        timing time;
        int value;
        int boost;
    public:
        card(std::string , cardtype , cardowner , timing , int , int );
        std::string get_name();
        cardtype get_type();
        cardowner get_owner();
        int get_boost();
        void set_boost(int);
        void set_value(int);
        void show_card();
        timing get_time();
        int get_value();
};
#endif