#include "map.h"
#include <iostream>

map::map()
{
   spaces.push_back(space(1 , {zone::ice} , true ));
   spaces.push_back(space(2 , {zone::ice} , false));
   spaces.push_back(space(3 , {zone::ice} , false));
   spaces.push_back(space(4 , {zone::ice} , false));
   spaces.push_back(space(5 , {zone::ice} , false));
   spaces.push_back(space(6 , {zone::blue , zone::broun} , false));
   spaces.push_back(space(7 , {zone::ice , zone::blue} , false));
   spaces.push_back(space(8 , {zone::blue} , false));
   spaces.push_back(space(9 , {zone::blue , zone::gray} , false));
   spaces.push_back(space(10 , {zone::blue , zone::green} , false));
   spaces.push_back(space(11 , {zone::green} , false));
   spaces.push_back(space(12 , {zone::green} , true));
   spaces.push_back(space(13 , {zone::green ,zone::gray} , false));
   spaces.push_back(space(14 , {zone::green ,zone::purple} , false));
   spaces.push_back(space(15 , {zone::broun , zone::green , zone::white} , false));
   spaces.push_back(space(16 , {zone::gray} , true));
   spaces.push_back(space(17 , {zone::gray} , false));
   spaces.push_back(space(18 , {zone::gray} , false));
   spaces.push_back(space(19 , {zone::gray} , false));
   spaces.push_back(space(20 , {zone::gray} , false));
   spaces.push_back(space(21 , {zone::gray} , false));
   spaces.push_back(space(22 , {zone::gray} , false));
   spaces.push_back(space(23 , {zone::gray , zone::purple} , false));
   spaces.push_back(space(24 , {zone::purple} , false));
   spaces.push_back(space(25 , {zone::purple} , false));
   spaces.push_back(space(26 , {zone::purple} , false));
   spaces.push_back(space(27 , {zone::white} , false));
   spaces.push_back(space(28 , {zone::white} , false));
   spaces.push_back(space(29 , {zone::white} , true));
   spaces.push_back(space(30 , {zone::broun} , false));
   spaces.push_back(space(31 , {zone::broun} , false));
   spaces.push_back(space(32 , {zone::broun} , false));
    neighborr();
}
space * map::get_space(int id)
{
    for(space &s : spaces)
    {
        if(s.get_id() == id)
        {
            return &s;
        }
    }
}
void map::neighborr()
{
    get_space(1)->add_neighbor(get_space(2));
    get_space(1)->add_neighbor(get_space(3));
    get_space(3)->add_neighbor(get_space(4));
    get_space(3)->add_neighbor(get_space(8));
    get_space(2)->add_neighbor(get_space(5));
    get_space(4)->add_neighbor(get_space(6));
    get_space(5)->add_neighbor(get_space(6));
    get_space(5)->add_neighbor(get_space(32));
    get_space(6)->add_neighbor(get_space(7));
    get_space(7)->add_neighbor(get_space(8));
    get_space(8)->add_neighbor(get_space(9));
    get_space(9)->add_neighbor(get_space(10));
    get_space(9)->add_neighbor(get_space(16));
    get_space(10)->add_neighbor(get_space(11));
    get_space(11)->add_neighbor(get_space(12));
    get_space(11)->add_neighbor(get_space(13));
    get_space(12)->add_neighbor(get_space(14));
    get_space(13)->add_neighbor(get_space(18));
    get_space(13)->add_neighbor(get_space(19));
    get_space(13)->add_neighbor(get_space(20));
    get_space(14)->add_neighbor(get_space(15));
    get_space(14)->add_neighbor(get_space(26));
    get_space(14)->add_neighbor(get_space(25));
    get_space(14)->add_neighbor(get_space(21));
    get_space(14)->add_neighbor(get_space(20));
    get_space(15)->add_neighbor(get_space(27));
    get_space(15)->add_neighbor(get_space(28));
    get_space(15)->add_neighbor(get_space(30));
    get_space(15)->add_neighbor(get_space(31));
    get_space(16)->add_neighbor(get_space(17));
    get_space(17)->add_neighbor(get_space(18));
    get_space(18)->add_neighbor(get_space(19));
    get_space(19)->add_neighbor(get_space(20));
    get_space(20)->add_neighbor(get_space(21));
    get_space(21)->add_neighbor(get_space(22));
    get_space(21)->add_neighbor(get_space(23));
    get_space(22)->add_neighbor(get_space(23));
    get_space(23)->add_neighbor(get_space(24));
    get_space(24)->add_neighbor(get_space(25));
    get_space(24)->add_neighbor(get_space(26));
    get_space(26)->add_neighbor(get_space(27));
    get_space(27)->add_neighbor(get_space(28));
    get_space(28)->add_neighbor(get_space(29));
    get_space(30)->add_neighbor(get_space(31));
    get_space(30)->add_neighbor(get_space(32));
    get_space(31)->add_neighbor(get_space(32));
    
    get_space(2)->add_neighbor(get_space(1));
    get_space(3)->add_neighbor(get_space(1));
    get_space(4)->add_neighbor(get_space(3));
    get_space(8)->add_neighbor(get_space(3));
    get_space(5)->add_neighbor(get_space(2));
    get_space(6)->add_neighbor(get_space(4));
    get_space(6)->add_neighbor(get_space(5));
    get_space(32)->add_neighbor(get_space(5));
    get_space(7)->add_neighbor(get_space(6));
    get_space(8)->add_neighbor(get_space(7));
    get_space(9)->add_neighbor(get_space(8));
    get_space(10)->add_neighbor(get_space(9));
    get_space(16)->add_neighbor(get_space(9));
    get_space(11)->add_neighbor(get_space(10));
    get_space(12)->add_neighbor(get_space(11));
    get_space(13)->add_neighbor(get_space(11));
    get_space(14)->add_neighbor(get_space(12));
    get_space(18)->add_neighbor(get_space(13));
    get_space(19)->add_neighbor(get_space(13));
    get_space(20)->add_neighbor(get_space(13));
    get_space(15)->add_neighbor(get_space(14));
    get_space(26)->add_neighbor(get_space(14));
    get_space(25)->add_neighbor(get_space(14));
    get_space(21)->add_neighbor(get_space(14));
    get_space(20)->add_neighbor(get_space(14));
    get_space(27)->add_neighbor(get_space(15));
    get_space(28)->add_neighbor(get_space(15));
    get_space(30)->add_neighbor(get_space(15));
    get_space(31)->add_neighbor(get_space(15));
    get_space(17)->add_neighbor(get_space(16));
    get_space(18)->add_neighbor(get_space(17));
    get_space(19)->add_neighbor(get_space(18));
    get_space(20)->add_neighbor(get_space(19));
    get_space(21)->add_neighbor(get_space(20));
    get_space(22)->add_neighbor(get_space(21));
    get_space(23)->add_neighbor(get_space(21));
    get_space(23)->add_neighbor(get_space(22));
    get_space(24)->add_neighbor(get_space(23));
    get_space(25)->add_neighbor(get_space(24));
    get_space(26)->add_neighbor(get_space(24));
    get_space(27)->add_neighbor(get_space(26));
    get_space(28)->add_neighbor(get_space(27));
    get_space(29)->add_neighbor(get_space(28));
    get_space(31)->add_neighbor(get_space(30));
    get_space(32)->add_neighbor(get_space(30));
    get_space(32)->add_neighbor(get_space(31));
}