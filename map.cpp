#include "map.h"


#include <iostream>

map::map()
{
   spaces.push_back(space(1 , {zone::ice} , true ,{116 , 191}));
   spaces.push_back(space(2 , {zone::ice} , false , { 264 , 154}));
   spaces.push_back(space(3 , {zone::ice} , false , {102 , 310}));
   spaces.push_back(space(4 , {zone::ice} , false , {230 , 320}));
   spaces.push_back(space(5 , {zone::ice} , false , { 350 , 274}));
   spaces.push_back(space(6 , {zone::blue , zone::broun} , false , {388 , 404}));
   spaces.push_back(space(7 , {zone::ice , zone::blue} , false , {266 , 450}));
   spaces.push_back(space(8 , {zone::blue} , false , {134 , 482}));
   spaces.push_back(space(9 , {zone::blue , zone::gray} , false , {204 , 624}));
   spaces.push_back(space(10 , {zone::blue , zone::green} , false , {392 , 564}));
   spaces.push_back(space(11 , {zone::green} , false , {542 , 490}));
   spaces.push_back(space(12 , {zone::green} , true , {654 , 428}));
   spaces.push_back(space(13 , {zone::green ,zone::gray} , false , {588 , 620}));
   spaces.push_back(space(14 , {zone::green ,zone::purple} , false , {800 , 484}));
   spaces.push_back(space(15 , {zone::broun , zone::green , zone::white} , false ,{802 , 268}));
   spaces.push_back(space(16 , {zone::gray} , true , {268 , 718}));
   spaces.push_back(space(17 , {zone::gray} , false , {388 , 692}));
   spaces.push_back(space(18 , {zone::gray} , false , {508 , 710}));
   spaces.push_back(space(19 , {zone::gray} , false , {640 , 722}));
   spaces.push_back(space(20 , {zone::gray} , false , {738 , 648}));
   spaces.push_back(space(21 , {zone::gray} , false , {886 , 652}));
   spaces.push_back(space(22 , {zone::gray} , false , {992 , 720}));
   spaces.push_back(space(23 , {zone::gray , zone::purple} , false , {1078 , 636}));
   spaces.push_back(space(24 , {zone::purple} , false , {1062 , 490}));
   spaces.push_back(space(25 , {zone::purple} , false , {924 , 514}));
   spaces.push_back(space(26 , {zone::purple} , false , {980 , 406}));
   spaces.push_back(space(27 , {zone::white} , false , {990 , 276}));
   spaces.push_back(space(28 , {zone::white} , false , {922 , 188}));
   spaces.push_back(space(29 , {zone::white} , true , {1068 , 192}));
   spaces.push_back(space(30 , {zone::broun} , false , {678 , 180}));
   spaces.push_back(space(31 , {zone::broun} , false , {606 , 272}));
   spaces.push_back(space(32 , {zone::broun} , false , {466 , 180}));
    neighborr();
    secret_pass();
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
void map::secret_pass()
{
    get_space(1)->add_secret_passage(get_space(16));
    get_space(1)->add_secret_passage(get_space(12));
    get_space(1)->add_secret_passage(get_space(29));
    get_space(12)->add_secret_passage(get_space(1));
    get_space(12)->add_secret_passage(get_space(16));
    get_space(12)->add_secret_passage(get_space(29));
    get_space(16)->add_secret_passage(get_space(29));
    get_space(16)->add_secret_passage(get_space(1));
    get_space(16)->add_secret_passage(get_space(12));
    get_space(29)->add_secret_passage(get_space(12));
    get_space(29)->add_secret_passage(get_space(16));
    get_space(29)->add_secret_passage(get_space(1));
}
void map::show_map()
{
    for(space s: spaces)
    {
        s.show_space();
    }
}
void map::set_location(std::string b , int a)
{
    for(space &s:spaces)
    {
        if(s.get_id() == a)
        {
            s.set_thisspacet(b);
        }
    }
}
void map::move(std::string c ,int l , character& character , map & g ,ui t)
{
    g.show_map();
    int ch;
    std::cout << "where do you want to go?" << std::endl ;
    for(space &s:spaces)
    {
        if(s.get_id() == l)
        {
           while (true)
           {
                    ch = s.show_neighbors_for_move(t, g);
                    break;
                
                
           }
           if(ch == 400)
           {
                break;
                return;
           }
           else
           {
                s.set_thisspacef();
                break;
           }
            
        }
    }
    if(ch == 400)
    {
        return;
    }
    character.set_location(get_space(ch));
    set_location(c ,ch);
}
void map::move_invisibleman(std::string c ,int l , character& character , map & g, game & p , ui tu)
{
    g.show_map();
    int ch;
    std::cout << "where do you want to go?" << std::endl ;
    for(space &s:spaces)
    {
        if(s.get_id() == l)
        {
            
            ch = s.move_invisible(p ,tu ,g);
            
                
           
           if(ch == 400)
           {
                break;
           }
           else
           {
                s.set_thisspacef();
                break;
           }
            
        }
    }
    if(ch == 400)
    {
        return;
    }
    character.set_location(get_space(ch));
    set_location(c ,ch);
}
void map::move2(character&h , ui ee)
{
    
    int a;
    a =std::stoi( ee.get_text_input("where do you want to go? (1  32)"));
    if(a> 32 || a < 1)
    {
        throw std::invalid_argument("please choose (1 - 32)");
    }
    else
    {
        for(space &s:spaces)
        {
            if(s.get_id() == a)
            {
                if(s.get_thisspace() == "e")
                {
                    h.get_location()->set_thisspacef();
                    h.set_location(&s);
                    set_location(h.get_name() ,a);
                }
                else
                {
                    ee.p("this space isnt empty");
                    move2(h , ee);
                }
            }
        }
    }

}
void map::move3(character & h , character & si , map& g , ui ee)
{
    int a;
    a =std::stoi(ee.get_text_input("where do you want to go? (1  32 (pay attention to the zone color))"));
    if(a> 32 || a < 1)
    {
        throw std::invalid_argument("please choose (1 - 32)");
    }
    else
    {
        int t = 0;
        int i = h.get_location()->get_zone().size();
        int j = g.get_space(a)->get_zone().size();
        for(int z= 0 ; z < i ; z++)
        {
            for(int m = 0 ; m < j ; m++)
            {
                if(h.get_location()->get_zone()[z] == g.get_space(a)->get_zone()[m])
                {
                    t+=1;
                }
            }
        }
        if(t == 0)
        {
            ee.p("you cant choose this space");
            std::cout << "you cant choose this space" << std::endl;
            move3(h,si,g, ee);
        } 
        else
        {
            for(space &s:spaces)
            {
                
                if(s.get_id() == a)
                {
                    if(s.get_thisspace() == "e")
                    {
                        si.get_location()->set_thisspacef();
                        si.set_location(get_space(a));
                        set_location(si.get_name() ,a);
                    }
                    else
                    {
                        ee.p("this space isnt empty");
                        std::cout << "this space isnt empty" << std::endl;
                        move3(h , si , g , ee);
                    }
                }
            }
        }
    }
}

void map::set_locationf(std::string b, int a)
{
    for(space &s:spaces)
    {
        if(s.get_id() == a)
        {
            s.set_fogt(b);
        }
    }
}
int map::pray_upon(character& h)
{
    for(space &s:spaces)
    {
        if(s.get_id() == h.get_location()->get_id())
        {
            if(s.prey_uponn() == 3)
            {
                h.set_hp(h.get_hp()+ 2);
                return 3;
            }
            if(s.prey_uponn() == 2)
            {
                h.set_hp(h.get_hp()+ 1);
                return 2;
            }
            if(s.prey_uponn() == 1)
            {
                h.set_hp(h.get_hp()+ 1);
                return 1;
            }
            if(s.prey_uponn() == 0)
            {
                return 0;
            }
        }
    }
}
