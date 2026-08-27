#include "card.h"


card::card(std::string n , cardtype  t, cardowner o, timing ti , int v, int b , std::string f)
{
    name = n;
    type =t;
    owner = o;
    time = ti;
    value = v;
    boost = b;
    image = f;
}
std::string card::get_image_path()
{
    return image;
}
std::string card::get_name()
{
    return name;
}
void card::set_value(int v)
{
    value = v;
}
void card::show_card()
{
    std::cout <<name << "    ";
    if(type == cardtype::attack)
    {
        std::cout << "card type: attack    ";
    }
    if(type == cardtype::defense)
    {
        std::cout << "card type: defense    ";
    }
    if(type == cardtype::scheme)
    {
        std::cout << "card type: scheme    ";
    }
    if(type == cardtype::versatile)
    {
        std::cout << "card type: versatile    ";
    }
    if(owner == cardowner::any)
    {
        std::cout << "card owner: any    ";
    }
    if(owner == cardowner::hero)
    {
        std::cout << "card owner: hero    ";
    }
    if(owner == cardowner::sidekick)
    {
        std::cout << "card owner: sidekick    ";
    }
    if(time == timing::aftercombat)
    {
        std::cout << "card timing: after combat    ";
    }
    if(time == timing::beforcombat)
    {
        std::cout << "card timing: befor combat    ";
    }
    if(time == timing::duringccombat)
    {
        std::cout << "card timing: during combat    ";
    }
    if(time == timing::none)
    {
        std::cout << "                             ";
    }
    std::cout << "value: " << value << "    " << "boost: " << boost << std::endl;
}
cardtype card::get_type()
{
    return type;
}
cardowner card::get_owner()
{
    return owner;
}
int card::get_boost()
{
    return boost;
}
void card::set_boost(int boost)
{
    this->boost = boost;
}
timing card::get_time()
{
    return time;
}
int card::get_value()
{
    return value;
}