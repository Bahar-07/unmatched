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
        std::string effect;
    public:
        card();
        card(std::string , cardtype , cardowner , timing , int , int );
};
#endif