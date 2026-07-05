#include "card.h"

card::card()
{
    name = "";
    type =cardtype::attack;
    owner = cardowner::hero;
    time = timing::none;
    value = 0;
    boost = 0;
    effect = "";
}
card::card(std::string n , cardtype  t, cardowner o, timing ti , int v, int b)
{
    name = n;
    type =t;
    owner = o;
    time = ti;
    value = v;
    boost = b;
}