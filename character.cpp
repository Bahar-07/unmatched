#include "character.h"

character::character()
{
    name = "";
    hp = 0;
    location = nullptr;
    status =true;
}
character::character(std::string name , int hp , int move )
{
    this->name = name;
    this->hp = hp;
    location = nullptr; 
    this->move = move;
    status = true;
}
std::string character::get_name()
{
    return name;
}
int character::get_hp()
{
    return hp;
}
void character::set_hp(int hp)
{
    this->hp = hp;
}
space* character::get_location()
{
    return location;
}
void character::set_location(space * l)
{
    location = l;
}
int character::get_move()
{
    return move;
}
void character::set_status()
{
    if(hp <= 0)
    {
        status = false;
    }
    else
    {
        status = true;
    }
}
bool character::get_status()
{
    return status;
}