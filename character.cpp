#include "character.h"

character::character()
{
    name = "";
    hp = 0;
    location = nullptr;
}
character::character(std::string name , int hp )
{
    this->name = name;
    this->hp = hp;
    location = nullptr; 
}
std::string character::get_name()
{
    return name;
}
int character::get_hp()
{
    return hp;
}
space* character::get_location()
{
    return location;
}
void character::set_location(space * l)
{
    location = l;
}