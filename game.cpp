#include "game.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;

game::game(string n)
{
    name = n;
    alivee = true;
    action = 2;
}
game::game(std::string pname , string age)
{
    name = pname;
    yoro = age;
    alivee = true;
    action = 2;
}
void game::age(game &enemy , map& g , ui t)
{
    
    int a;
    a = t.agee(name , enemy.name);
    if(a == 0)
    {
        yoro = "younger";
        enemy.yoro = "older";
    }
    if(a == 1)
    {
        yoro = "older";
        enemy.yoro = "younger";
    }
    if(a == 2)
    {
        int random = rand() %2;
        if(random == 0)
        {
            yoro = "older";
            enemy.yoro = "younger";
        }
        else
        {
            enemy.yoro = "older";
            yoro = "younger";
        }
       
    }
    
}
void game::choose_character(game& enemy , map& g , ui t) 
{
    bool o = false;
    int b;
    while (true)
    {
        std::cout << name << " please choose your hero" << endl;
        b = t.choose_character(*this);
        
        if(b ==0)
        {
            if(enemy.hero.get_name() != "" && enemy.hero.get_name() == "Dracula")
            {
                t.p("this character has already been selected");
               
            }
            else
            {
                hero = character("Dracula" , 13 , 2 , "melee");

                sidekicks.push_back(character("sister 1", 1 , 2 , "melee"));
                sidekicks.push_back(character("sister 2", 1 , 2 , "melee"));
                sidekicks.push_back(character("sister 3", 1 , 2 , "melee"));
                break;
            }
           
        }
        else if(b == 1)
        {
            if(enemy.hero.get_name() != "" && enemy.hero.get_name() == "Sherlock Holmes")
            {
                t.p("this character has already been selected");
                
            }
            else
            {
                hero =character("Sherlock Holmes", 16 , 2 , "melee");
                sidekicks.push_back(character("Dr.Watson", 8 , 2, "ranged"));
                break;
            }
            
        }
        if(b == 2)
        {
            if(enemy.hero.get_name() != "" && enemy.hero.get_name() == "Invisible Man")
            {
                t.p("this character has already been selected");
                
            }
            else
            {
                hero =character("Invisible Man", 15 , 2 , "melee");
                break;
            }
            
        }
        
    }
}
void game::choose_location(game& enemy , map& g , ui tt)
{ 
    int a;
    int r;
    int s;
    int t;
    g.show_map();
    while (true)
    {
        a = tt.choose_space(g, "please choose one of these spaces" , {5 ,25});
        if(a == 0)
        {
            if(enemy.hero.get_location() != nullptr &&enemy.hero.get_location()->get_id() == 5 )
            {
                tt.p("this space has already been selected");
            }
            else
            {
                if(hero.get_name() == "Dracula")
                {
                    vector<int> spaces ={1 , 2 , 3 , 4 , 7};
                    hero.set_location(g.get_space(5));
                    /*enemy.hero.set_location(g.get_space(25));*/
                    g.set_location("Dracula" , 5);
                    /*g.set_location("Sherlock Holmes" , 25);*/
                    int index = tt.choose_space(g ,name+ " please choose 3 spaces for your sisters" , {1 , 2 , 3 , 4 , 7});
                    r = spaces[index];
                        if(r ==1 || r == 2 || r == 3 || r == 4 || r == 7)
                        {
                            sidekicks[0].set_location(g.get_space(r));
                            g.set_location("sister 1" , r);
                        }
                    
                    while (true)
                    {
                        index = tt.choose_space(g ,name+ " please choose 3 spaces for your sisters" , {1 , 2 , 3 , 4 , 7});
                        s = spaces[index];
                        if((s ==1 || s == 2 || s == 3 || s == 4 || s == 7) && s != r)
                        {
                            sidekicks[1].set_location(g.get_space(s));
                            g.set_location("sister 2" , s);
                            break;
                        }
                        else
                        {
                            tt.p("this space has already been selected");
                        }
                    }
                    while (true)
                    {

                        index = tt.choose_space(g ,name+ " please choose 3 spaces for your sisters" , {1 , 2 , 3 , 4 , 7});
                        t = spaces[index];
                        if((t ==1 || t == 2 || t == 3 || t == 4 || t == 7) && t != r && t != s)
                        {
                            sidekicks[2].set_location(g.get_space(t));
                            g.set_location("sister 3" , t);
                            break;
                        }
                        else
                        {
                            tt.p("this space has already been selected");
                        }
                    }
                    spaces.clear();
                    
                }
                else if(hero.get_name() == "Sherlock Holmes")
                {
                    hero.set_location(g.get_space(5));
                    g.set_location("Sherlock Holmes" , 5);
                    vector<int> spaces ={1 , 2 , 3 , 4 , 7};
                    int index = tt.choose_space(g ,name + " please choose a spaces for Dr.Watson" , {1 , 2 , 3 , 4 , 7});
                    r = spaces[index];
                
                    if(r ==1 || r == 2 || r == 3 || r == 4 || r == 7)
                    {
                        sidekicks[0].set_location(g.get_space(r));
                        g.set_location("Dr.Watson" , r);
                    
                    }
                    spaces.clear();
               
                }
                else if(hero.get_name() == "Invisible Man")
                {
                    int index;
                    hero.set_location(g.get_space(5));
                    g.set_location("Invisible Man" , 5);
                    vector<int> spacess ={1 , 2 , 3 , 4 , 7};
                    index = tt.choose_space(g ,name + " please choose 3 spaces for fogs " , {1 , 2 , 3 , 4 , 7});
                    r = spacess[index];
                
                    if(r == 1 || r == 2 || r == 3 || r == 4 || r == 7)
                    {
                        fogs.push_back(g.get_space(r));
                        g.set_locationf("fog" , r);
                    }
                    while (true)
                    {
                        index = tt.choose_space(g ,name + " please choose 3 spaces for fogs " , {1 , 2 , 3 , 4 , 7});
                        s = spacess[index];
                        if((s == 1 || s == 2 || s == 3 || s == 4 || s == 7 ) && s != r)
                        {
                            fogs.push_back(g.get_space(s));
                            g.set_locationf("fog" , s);
                            break;
                        }
                        else
                        {
                           tt.p("this space has already been selected");
                        }
                    }
                    while (true)
                    {

                        index = tt.choose_space(g ,name + " please choose 3 spaces for fogs " , {1 , 2 , 3 , 4 , 7});
                        t = spacess[index];
                        if((t == 1 || t == 2 || t == 3 || t == 4 || t == 7) && t != r && t != s)
                        {
                            fogs.push_back(g.get_space(t));
                            g.set_locationf("fog" , t);
                            break;
                        }
                        else
                        {
                            tt.p("this space has already been selected");
                        }
                    }
                    spacess.clear();
                }
                break;
            }
        }
        else if(a == 1)
        {
            
            if(enemy.hero.get_location() != nullptr && enemy.hero.get_location()->get_id() == 25 )
            {
                tt.p("this space has already been selected");
            }
            else
            {
                if(hero.get_name() == "Dracula")
                {
                    hero.set_location(g.get_space(25));
                    g.set_location("Dracula" , 25);
                    vector<int> spaces ={14 , 23 , 24 , 26};
                    int index = tt.choose_space(g ,name + " please choose 3 spaces for your sisters " , {14 , 23 , 24 , 26});
                    r = spaces[index];
                        if(r ==14 || r == 23 || r == 24 || r == 26 )
                        {
                            sidekicks[0].set_location(g.get_space(r));
                            g.set_location("sister 1" , r);
                        }
                    while (true)
                    {
                        index = tt.choose_space(g ,name + " please choose 3 spaces for your sisters " , {14 , 23 , 24 , 26});
                        s = spaces[index];
                        if((s ==14 || s == 23 || s == 24 || s == 26 ) && s != r)
                        {
                            sidekicks[1].set_location(g.get_space(s));
                            g.set_location("sister 2" , s);
                            break;
                        }
                        else
                        {
                            tt.p("this space has already been selected");
                        }
                    }
                    while (true)
                    {
                        index = tt.choose_space(g ,name + " please choose 3 spaces for your sisters " , {14 , 23 , 24 , 26});
                        t = spaces[index];
                        if((t ==14 || t == 23 || t == 24 || t == 26 ) && t != r && t != s)
                        {
                            sidekicks[2].set_location(g.get_space(t));
                            g.set_location("sister 3" , t);
                            break;
                        }
                        else
                        {
                            tt.p("this space has already been selected");
                        }
                    }
                    spaces.clear();
                }
                else if(hero.get_name() == "Sherlock Holmes")
                {
                    hero.set_location(g.get_space(25));
                    g.set_location("Sherlock Holmes" , 25);
                    vector<int> spaces ={14 , 23 , 24 , 26};
                    int index = tt.choose_space(g ,name + " please choose a spaces for Dr.Watson " , {14 , 23 , 24 , 26});
                    r = spaces[index];
                    if(r ==14 || r == 23 || r == 24 || r == 26)
                    {
                        sidekicks[0].set_location(g.get_space(r));
                        g.set_location("Dr.Watson" , r);
                    }
                    spaces.clear();
                    
                }
                else if(hero.get_name() == "Invisible Man")
                {
                    hero.set_location(g.get_space(25));
                    g.set_location("Invisible Man" , 25);
                    int index;
                    vector<int> spacess ={14 , 23 , 24 , 26};
                    index = tt.choose_space(g ,name + " please choose 3 spaces for fogs " , {14 , 23 , 24 , 26});
                    r = spacess[index];
                
                    if(r == 14 || r == 23 || r == 24 || r == 26 )
                    {
                        fogs.push_back(g.get_space(r));
                        g.set_locationf("fog" , r);
                    }
                    while (true)
                    {
                        index = tt.choose_space(g ,name + " please choose 3 spaces for fogs " , {14 , 23 , 24 , 26});
                        s = spacess[index];
                        if((s == 14 || s == 23 || s == 24 || s == 26) && s != r)
                        {
                            fogs.push_back(g.get_space(s));
                            g.set_locationf("fog" , s);
                            break;
                        }
                        else
                        {
                            tt.p("this space has already been selected");
                        }
                    }
                    while (true)
                    {

                        index = tt.choose_space(g ,name + " please choose 3 spaces for fogs " , {14 , 23 , 24 , 26});
                        t = spacess[index];
                        if((t == 14 || t == 23 || t == 24 || t == 26 ) && t != r && t != s)
                        {
                            fogs.push_back(g.get_space(t));
                            g.set_locationf("fog" , t);
                            break;
                        }
                        else
                        {
                            tt.p("this space has already been selected");
                        }
                    }
                    spacess.clear();
                }
                break;
            }
        }
    }
    
    
}
string game::get_age()
{
    return yoro;
}
string game::get_name_player()
{
    return name;
}
bool game::alive()
{
    if(hero.get_status())
    {
        alivee = true;
    }
    else
    {
        alivee = false;
    }
    return alivee;
}
void game::creat_deck()
{
    if(hero.get_name()== "Dracula")
    {
        deck.push_back(card("feeding frenzy" ,{cardtype::attack} , {cardowner::hero} , {timing::duringccombat} , 2 , 3 , "feeding-frenzy.png"));
        deck.push_back(card("feeding frenzy" ,{cardtype::attack} , {cardowner::hero} , {timing::duringccombat} , 2 , 3 , "feeding-frenzy.png"));
        deck.push_back(card("mistform" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2 , "mistform.png"));
        deck.push_back(card("mistform" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2 , "mistform.png"));
        deck.push_back(card("ambush" ,{cardtype::attack} , {cardowner::any} , {timing::duringccombat} , 2 , 3 , "ambush.png"));
        deck.push_back(card("ambush" ,{cardtype::attack} , {cardowner::any} , {timing::duringccombat} , 2 , 3 , "ambush.png"));
        deck.push_back(card("baptism of blood" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2 , "baptism-of-blood.png"));
        deck.push_back(card("baptism of blood" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2 , "baptism-of-blood.png"));
        deck.push_back(card("beastform" ,{cardtype::attack} , {cardowner::hero} , {timing::duringccombat} , 6 , 4 , "beastform.png"));
        deck.push_back(card("beastform" ,{cardtype::attack} , {cardowner::hero} , {timing::duringccombat} , 6 , 4 , "beastform.png"));
        deck.push_back(card("dash" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 1 , "dash.png"));
        deck.push_back(card("dash" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 1 , "dash.png"));
        deck.push_back(card("dash" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 1 , "dash.png"));
        deck.push_back(card("exploit" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 4 , 1 , "exploit.png"));
        deck.push_back(card("exploit" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 4 , 1 , "exploit.png"));
        deck.push_back(card("exploit" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 4 , 1 , "exploit.png"));
        deck.push_back(card("look into my eyes" ,{cardtype::defense} , {cardowner::hero} , {timing::duringccombat} , 1 , 2 , "look-into-my-eyes.png"));
        deck.push_back(card("look into my eyes" ,{cardtype::defense} , {cardowner::hero} , {timing::duringccombat} , 1 , 2 , "look-into-my-eyes.png"));
        deck.push_back(card("look into my eyes" ,{cardtype::defense} , {cardowner::hero} , {timing::duringccombat} , 1 , 2 , "look-into-my-eyes.png"));
        deck.push_back(card("pray upon" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 4 , "prey-upon.png"));
        deck.push_back(card("pray upon" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 4 , "prey-upon.png"));
        deck.push_back(card("ravening seduction" ,{cardtype::scheme} , {cardowner::sidekick} , {timing::none} , 0 , 2 , "ravening-seduction.png"));
        deck.push_back(card("ravening seduction" ,{cardtype::scheme} , {cardowner::sidekick} , {timing::none} , 0 , 2 , "ravening-seduction.png"));
        deck.push_back(card("ravening seduction" ,{cardtype::scheme} , {cardowner::sidekick} , {timing::none} , 0 , 2 , "ravening-seduction.png"));
        deck.push_back(card("thirst for sustenance" ,{cardtype::attack} , {cardowner::sidekick} , {timing::aftercombat} , 3 , 3 , "thirst-for-sustenance.png"));
        deck.push_back(card("thirst for sustenance" ,{cardtype::attack} , {cardowner::sidekick} , {timing::aftercombat} , 3 , 3 , "thirst-for-sustenance.png"));
        deck.push_back(card("thirst for sustenance" ,{cardtype::attack} , {cardowner::sidekick} , {timing::aftercombat} , 3 , 3 ,"thirst-for-sustenance.png"));
        deck.push_back(card("feint" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 2 , "feint (1).png"));
        deck.push_back(card("feint" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 2 , "feint (1).png"));
        deck.push_back(card("feint" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 2 , "feint (1).png"));


    }
    if(hero.get_name()== "Sherlock Holmes")
    {
        deck.push_back(card("administer aid" ,{cardtype::scheme} , {cardowner::sidekick} , {timing::none} , 0 , 2 , "administer-aid.png"));
        deck.push_back(card("administer aid" ,{cardtype::scheme} , {cardowner::sidekick} , {timing::none} , 0 , 2 , "administer-aid.png"));
        deck.push_back(card("counterpunch" ,{cardtype::versatile} , {cardowner::hero} , {timing::aftercombat} , 3 , 1 , "counterpunch.png"));
        deck.push_back(card("counterpunch" ,{cardtype::versatile} , {cardowner::hero} , {timing::aftercombat} , 3 , 1 , "counterpunch.png"));
        deck.push_back(card("counterpunch" ,{cardtype::versatile} , {cardowner::hero} , {timing::aftercombat} , 3 , 1 , "counterpunch.png"));
        deck.push_back(card("deduce strategy" ,{cardtype::versatile} , {cardowner::hero} , {timing::duringccombat} , 3 , 1 , "deduce-strategy.png"));
        deck.push_back(card("deduce strategy" ,{cardtype::versatile} , {cardowner::hero} , {timing::duringccombat} , 3 , 1 , "deduce-strategy.png"));
        deck.push_back(card("deduce strategy" ,{cardtype::versatile} , {cardowner::hero} , {timing::duringccombat} , 3 , 1 , "deduce-strategy.png"));
        deck.push_back(card("education never ends" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 1 , "education-never-ends.png"));
        deck.push_back(card("education never ends" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 1 , "education-never-ends.png"));
        deck.push_back(card("eliminate the impossible" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2 , "eliminate-the-impossible.png"));
        deck.push_back(card("eliminate the impossible" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2 , "eliminate-the-impossible.png"));
        deck.push_back(card("feint_" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 1 , "feint (2).png"));
        deck.push_back(card("feint_" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 1 , "feint (2).png"));
        deck.push_back(card("feint_" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 1 , "feint (2).png"));
        deck.push_back(card("fixed point in a changing age" ,{cardtype::versatile} , {cardowner::sidekick} , {timing::aftercombat} , 3 , 1 , "fixed-point-in-a-changing-age.png"));
        deck.push_back(card("fixed point in a changing age" ,{cardtype::versatile} , {cardowner::sidekick} , {timing::aftercombat} , 3 , 1 , "fixed-point-in-a-changing-age.png"));
        deck.push_back(card("master of disguise" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2 , "master-of-disguise.png"));
        deck.push_back(card("master of disguise" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2 , "master-of-disguise.png"));
        deck.push_back(card("the game is afoot" ,{cardtype::attack} , {cardowner::hero} , {timing::aftercombat} , 5 , 2 , "the-game-is-afoot.png"));
        deck.push_back(card("the game is afoot" ,{cardtype::attack} , {cardowner::hero} , {timing::aftercombat} , 5 , 2 , "the-game-is-afoot.png"));
        deck.push_back(card("service revolver" ,{cardtype::attack} , {cardowner::sidekick} , {timing::none} , 5 , 3 , "service-revolver.png"));
        deck.push_back(card("service revolver" ,{cardtype::attack} , {cardowner::sidekick} , {timing::none} , 5 , 3 , "service-revolver.png"));
        deck.push_back(card("study methodes" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 2 , "study-methods.png"));
        deck.push_back(card("study methodes" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 2 , "study-methods.png"));


    }
    if(hero.get_name() == "Invisible Man")
    {
        deck.push_back(card("coded notes" ,{cardtype::defense} , {cardowner::hero} , {timing::aftercombat} , 3 , 2 , "coded-notes.png"));
        deck.push_back(card("coded notes" ,{cardtype::defense} , {cardowner::hero} , {timing::aftercombat} , 3 , 2 , "coded-notes.png"));
        deck.push_back(card("covert preparation" ,{cardtype::versatile} , {cardowner::hero} , {timing::aftercombat} , 2 , 1 , "covert-preparation.png"));
        deck.push_back(card("covert preparation" ,{cardtype::versatile} , {cardowner::hero} , {timing::aftercombat} , 2 , 1 , "covert-preparation.png"));
        deck.push_back(card("covert preparation" ,{cardtype::versatile} , {cardowner::hero} , {timing::aftercombat} , 2 , 1 , "covert-preparation.png"));
        deck.push_back(card("dreaming of revenge" ,{cardtype::versatile} , {cardowner::hero} , {timing::aftercombat} , 3 , 1 , "dreaming-of-revenge.png"));
        deck.push_back(card("dreaming of revenge" ,{cardtype::versatile} , {cardowner::hero} , {timing::aftercombat} , 3 , 1 , "dreaming-of-revenge.png"));
        deck.push_back(card("emerge from mist" ,{cardtype::attack} , {cardowner::hero} , {timing::duringccombat} , 3 , 2 , "emerge-from-mist.png"));
        deck.push_back(card("emerge from mist" ,{cardtype::attack} , {cardowner::hero} , {timing::duringccombat} , 3 , 2 , "emerge-from-mist.png"));
        deck.push_back(card("impossible yo see" ,{cardtype::versatile} , {cardowner::hero} , {timing::beforcombat} , 2 , 2 , "impossible-to-see.png"));
        deck.push_back(card("impossible yo see" ,{cardtype::versatile} , {cardowner::hero} , {timing::beforcombat} , 2 , 2 , "impossible-to-see.png"));
        deck.push_back(card("into thin air" ,{cardtype::defense} , {cardowner::hero} , {timing::aftercombat} , 4 , 1 , "into-thin-air.png"));
        deck.push_back(card("into thin air" ,{cardtype::defense} , {cardowner::hero} , {timing::aftercombat} , 4 , 1 , "into-thin-air.png"));
        deck.push_back(card("lurking" ,{cardtype::defense} , {cardowner::hero} , {timing::aftercombat} , 2 , 2 , "lurking.png"));
        deck.push_back(card("lurking" ,{cardtype::defense} , {cardowner::hero} , {timing::aftercombat} , 2 , 2 , "lurking.png"));
        deck.push_back(card("ring of terror" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 1 , "reign-of-terror.png"));
        deck.push_back(card("ring of terror" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 1 , "reign-of-terror.png"));
        deck.push_back(card("rolling fog" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 1 , "rolling-fog.png"));
        deck.push_back(card("rolling fog" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 1 , "rolling-fog.png"));
        deck.push_back(card("slip away" ,{cardtype::attack} , {cardowner::hero} , {timing::aftercombat} , 3 , 2 , "slip-away.png"));
        deck.push_back(card("slip away" ,{cardtype::attack} , {cardowner::hero} , {timing::aftercombat} , 3 , 2 , "slip-away.png"));
        deck.push_back(card("slip away" ,{cardtype::attack} , {cardowner::hero} , {timing::aftercombat} , 3 , 2 , "slip-away.png"));
        deck.push_back(card("step lightly" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 1 , "step-lightly.png"));
        deck.push_back(card("step lightly" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 1 , "step-lightly.png"));
        deck.push_back(card("vanish" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 3 , "vanish.png"));
        deck.push_back(card("vanish" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 3 , "vanish.png"));

    }
}
void game::pick_card(game & enemy)
{
    int random;
    random = rand()%deck.size();
    hand.push_back(deck[random]);
    deck.erase(deck.begin() + random);
    random = rand()%deck.size();
    hand.push_back(deck[random]);
    deck.erase(deck.begin() + random);
    random = rand()%deck.size();
    hand.push_back(deck[random]);
    deck.erase(deck.begin() + random);
    random = rand()%deck.size();
    hand.push_back(deck[random]);
    deck.erase(deck.begin() + random);
    random = rand()%deck.size();
    hand.push_back(deck[random]);
    deck.erase(deck.begin() + random);
}
void game::start_game(game & enemy , map & g , ui tu)
{
    
    cout << hero.get_name() << " turn" << endl;
    while(action > 0)
    {
        b.clear();
        c.clear();
        enemy.b.clear();
        enemy.c.clear();
        int z;
        
            z = tu.draw_game_screen( enemy, *this,  g);
        
        
            if(z ==0)
            {
                if(deck.size() > 0)
                {
                    int random = rand()%deck.size();
                    hand.push_back(deck[random]);
                    deck.erase(deck.begin() + random);
                    cout << "number of cards in the hand = " << hand.size() << endl << "number of cards in the deck = " << deck.size() << endl;
                }
                else
                {
                    tu.p("deck is empty");
                    hero.set_hp(hero.get_hp() - 2);
                    hero.set_status();
                    if(hero.get_name() == "Sherlock Holmes")
                    {
                        sidekicks[0].set_hp(hero.get_hp() - 2);
                        sidekicks[0].set_status();
                    }
                    if(hero.get_name() == "Dracula")
                    {
                        sidekicks[0].set_hp(hero.get_hp() - 2);
                        sidekicks[1].set_hp(hero.get_hp() - 2);
                        sidekicks[2].set_hp(hero.get_hp() - 2);
                        sidekicks[0].set_status();
                        sidekicks[1].set_status();
                        sidekicks[2].set_status();
                    }
                }
                int h = tu.yesorno("Do you want to move your character?");
                    if(h == 0)
                    {
                        int v=tu.yesorno("Do you want to discard a card and use the boost?");
            
                        if(v == 1)
                        {
                            if(hero.get_name() == "Dracula")
                            {
                                
                                while(true)
                                {
                                    int yy = tu.choose_acharacter("Choose a character to move" , { hero.get_name() , sidekicks[0].get_name() , sidekicks[1].get_name() , sidekicks[2].get_name() });
                                
                                    if(yy == 0)
                                    {
                                        int tt = tu.choose_acharacter("How many spaces do you want to move?" , {"1" , "2" });
                                        while(tt+1 > 0)
                                        {
                                            g.move(hero.get_name(), hero.get_location()->get_id(), hero , g , tu);
                                            tt--;
                                        }
                                        break;
                                        
                                    }
                                    if(yy == 1)
                                    {
                                        if(sidekicks[0].get_status())
                                        {
                                            
                                            int tt = tu.choose_acharacter("How many spaces do you want to move?" , {"1" , "2" });
                                            
                                            while(tt+1 > 0)
                                            {
                                                g.move(sidekicks[0].get_name(), sidekicks[0].get_location()->get_id(), sidekicks[0] , g ,tu);
                                                tt--;
                                            }
                                                
                                            break;
                                        }
                                        else
                                        {
                                            tu.p("this character is dead");
                                        }
                                        
                                        
                                    }
                                    if(yy == 2)
                                    {
                                        if(sidekicks[1].get_status())
                                        {
                                            int tt = tu.choose_acharacter("How many spaces do you want to move?" , {"1" , "2" });;
                                            while(tt+1 > 0)
                                            {
                                                g.move(sidekicks[1].get_name(), sidekicks[1].get_location()->get_id(), sidekicks[1] , g, tu);
                                                tt--;
                                            }
                                            break;
                                            
                                        }
                                        else
                                        {
                                            tu.p("this character is dead");
                                        }
                                        
                                    }
                                    if(yy == 3)
                                    {
                                        if(sidekicks[2].get_status())
                                        {
                                            int tt = tu.choose_acharacter("How many spaces do you want to move?" , {"1" , "2" });;
                                            while(tt+1 > 0)
                                            {
                                                g.move(sidekicks[2].get_name(), sidekicks[2].get_location()->get_id(), sidekicks[2] , g , tu);
                                                tt--;
                                            }
                                            break;
                                            
                                        }
                                        else
                                        {
                                            tu.p("this character is dead");
                                        }
                                    }
                                }
                            }

                            if(hero.get_name() == "Sherlock Holmes")
                            {
                            
                                while(true)
                                {
                                    int yy = tu.choose_acharacter("Choose a character to move" , { hero.get_name() , sidekicks[0].get_name()});
                                
                                    if(yy == 0)
                                    {
                                        int tt = tu.choose_acharacter("How many spaces do you want to move?" , {"1" , "2" });
                                        while(tt+1 > 0)
                                        {
                                            g.move(hero.get_name(), hero.get_location()->get_id(), hero , g , tu);
                                            tt--;
                                        }
                                        break;
                                    }
                                    if(yy == 1)
                                    {
                                        if(sidekicks[0].get_status())
                                        {
                                            
                                            int tt = tu.choose_acharacter("How many spaces do you want to move?" , {"1" , "2" });
                                            
                                            while(tt+1 > 0)
                                            {
                                                g.move(sidekicks[0].get_name(), sidekicks[0].get_location()->get_id(), sidekicks[0] , g , tu);
                                                tt--;
                                            }
                                                
                                            break;
                                        }
                                        else
                                        {
                                            tu.p("this character is dead");
                                        }
                                    
                                    }
                                }
                            }
                            if(hero.get_name() == "Invisible Man")
                            {
                                int tt = tu.choose_acharacter("How many spaces do you want to move?" , {"1" , "2" });
                                while(tt+1 > 0)
                                {
                                    g.move_invisibleman(hero.get_name(), hero.get_location()->get_id(), hero , g , *this , tu);
                                    tt--;
                                }
                            }
                        
                        }
                        if(v == 0)
                        {
                            int move;
                            
                            int yy;
                            
                            while ((true))
                            {
                                yy = tu.choose_card(hand);
                                if(yy< 0 || yy > hand.size())
                                {
                                    string h = to_string(hand.size());
                                    tu.p("please choose (1 -" + h + ")");
                                }
                                else
                                {
                                    move = hand[yy].get_boost() + 2;
                                    hand.erase(hand.begin() + yy);
                                    break;
                                }
                            }
                            vector<string> tq;
                            for(int i = 0 ; i <= move ;)
                            {
                                i++;
                                tq.push_back(to_string(i));
                            }
                            if(hero.get_name() == "Dracula")
                            {
                                
                                while(true)
                                {
                                    int yy = tu.choose_acharacter("Choose a character to move" , { hero.get_name() , sidekicks[0].get_name() , sidekicks[1].get_name() , sidekicks[2].get_name() });
                                    
                                    if(yy == 0)
                                    {
                                        int tt;
                                        tt= tu.choose_acharacter("how many spaces do you want to move?" , tq) ;
                                        
                                        while(tt+ 1 > 0)
                                        {
                                            g.move(hero.get_name(), hero.get_location()->get_id(), hero , g , tu);
                                            tt--;
                                        }
                                        break;
                                        
                                    }
                                    if(yy == 1)
                                    {
                                        if(sidekicks[0].get_status())
                                        {
                                            
                                            int tt; 
                                           
                                            tt= tu.choose_acharacter("how many spaces do you want to move?" , tq) ;
                                                
                                            while(tt+ 1 > 0)
                                            {
                                                g.move(sidekicks[0].get_name(), sidekicks[0].get_location()->get_id(), sidekicks[0] , g , tu);
                                                tt--;
                                            }
                                               

                                            
                                            break;
                                        }
                                        else
                                        {
                                            tu.p("this character is dead... please choose another character");
                                            
                                        }
                                        
                                        
                                    }
                                    if(yy == 2)
                                    {
                                         if(sidekicks[1].get_status())
                                        {
                                            
                                            int tt; 
                                           
                                            tt= tu.choose_acharacter("how many spaces do you want to move?" , tq) ;
                                                
                                            while(tt + 1> 0)
                                            {
                                                g.move(sidekicks[1].get_name(), sidekicks[1].get_location()->get_id(), sidekicks[1] , g , tu);
                                                tt--;
                                            }
                                               

                                            
                                            break;
                                        }
                                        else
                                        {
                                            tu.p("this character is dead... please choose another character");
                                            
                                        }
                                        
                                    }
                                    if(yy == 3)
                                    {
                                        if(sidekicks[2].get_status())
                                        {
                                            
                                            int tt; 
                                           
                                            tt= tu.choose_acharacter("how many spaces do you want to move?" , tq) ;
                                                
                                            while(tt+ 1 > 0)
                                            {
                                                g.move(sidekicks[2].get_name(), sidekicks[2].get_location()->get_id(), sidekicks[2] , g , tu);
                                                tt--;
                                            }
                                               

                                            
                                            break;
                                        }
                                        else
                                        {
                                            tu.p("this character is dead... please choose another character");
                                            
                                        }
                                    }
                                
                                }
                            }

                            if(hero.get_name() == "Sherlock Holmes")
                            {
                            
                                while(true)
                                {
                                    int yy = tu.choose_acharacter("Choose a character to move" , { hero.get_name() , sidekicks[0].get_name() });
                                    
                                    if(yy == 0)
                                    {
                                        int tt;
                                        tt= tu.choose_acharacter("how many spaces do you want to move?" , tq) ;
                                        
                                        while(tt + 1> 0)
                                        {
                                            g.move(hero.get_name(), hero.get_location()->get_id(), hero , g , tu);
                                            tt--;
                                        }
                                        break;
                                    }
                                    if(yy == 1)
                                    {
                                        if(sidekicks[0].get_status())
                                        {
                                            
                                            int tt; 
                                           
                                            tt= tu.choose_acharacter("how many spaces do you want to move?" , tq) ;
                                                
                                            while(tt + 1> 0)
                                            {
                                                g.move(sidekicks[0].get_name(), sidekicks[0].get_location()->get_id(), sidekicks[0] , g , tu);
                                                tt--;
                                            }
                                               

                                            
                                            break;
                                        }
                                        else
                                        {
                                            tu.p("this character is dead... please choose another character");
                                            
                                        }
                                    
                                    }
                                    
                                }
                            }
                            if(hero.get_name() == "Invisible Man")
                            {
                               int tt;
                                tt= tu.choose_acharacter("how many spaces do you want to move?" , tq) ;
                                
                                while(tt+1 > 0)
                                {
                                    g.move_invisibleman(hero.get_name(), hero.get_location()->get_id(), hero , g , *this , tu);
                                    tt--;
                                }
                            }
                        }
                    
                    }
                    else if(h == 1)
                    {
                    }
                action--;
                hero.set_status();
                enemy.hero.set_status();
                for(auto &s:sidekicks)
                {
                    s.set_status();
                }
                for(auto &s:enemy.sidekicks)
                {
                    s.set_status();
                }
                        
            }
            else if(z == 1)
            {
                vector<int> index;
                for(int i = 0 ; i < hand.size() ; i++)
                {
                    if(hand[i].get_type() == cardtype::scheme )
                    {
                        c.push_back(hand[i]);
                        index.push_back(i);
                    }
                }
                if(c.empty())
                {
                    tu.p("you dont have any scheme card please choose another action");
                    start_game(enemy , g , tu);
                    return;
                }
                int yy;
                while ((true))
                {
                    yy = tu.choose_card(c);
                    if(yy< 0 || yy > c.size())
                    {
                        string h = to_string(c.size());
                        tu.p("please choose (1 -" + h + ")");
                    }
                    else
                    {
                        card_effects(&c[yy],enemy , g , tu);
                        hand.erase(hand.begin() + index[yy]);
                        break;
                    }
                }
                c.clear();
                action--;
                hero.set_status();
                enemy.hero.set_status();
                for(auto &s:sidekicks)
                {
                    s.set_status();
                }
                for(auto &s:enemy.sidekicks)
                {
                    s.set_status();
                }
            }
            else if(z == 2)
            {
                for(card  s:hand)
                {
                    if(s.get_type() == cardtype::attack || s.get_type() == cardtype::versatile)
                    {
                        c.push_back(s);
                    }
                }
                if(c.empty())
                {
                    tu.p( "you dont have any attack card please choose another action");
                    
                    start_game(enemy , g , tu);
                    return;
                }
                try
                {
                    choose_fighter(enemy , g , tu);
                }
                catch(const std::invalid_argument & e)
                {
                    std::cerr << e.what() << '\n';
                    cout << "please choose another action ..." << endl;
                    start_game(enemy , g , tu);
                    return;
                }
                choose_target(enemy , tu);
                if(active_character->get_name() == hero.get_name())
                {
                    for(card & s:c)
                    {
                        if(s.get_owner() == cardowner::hero || s.get_owner() == cardowner::any)
                        {
                            b.push_back(s);
                        }
                    }
                }
                if(hero.get_name() == "Dracula")
                {
                    if(active_character->get_name() == sidekicks[0].get_name() || active_character->get_name() == sidekicks[1].get_name() || active_character->get_name() == sidekicks[2].get_name())
                    {
                        for(card & s:c)
                        {
                            if(s.get_owner() == cardowner::sidekick || s.get_owner() == cardowner::any)
                            {
                                b.push_back(s);
                            }
                        }
                    }
                }
                if(hero.get_name() == "Sherlock Holmes")
                {
                    if(active_character->get_name() == sidekicks[0].get_name())
                    {
                        for(card & s:c)
                        {
                            if(s.get_owner() == cardowner::sidekick || s.get_owner() == cardowner::any)
                            {
                                b.push_back(s);
                            }
                        }
                    }
                }
                if(b.empty())
                {
                    tu.p("you dont have any attack card for this character");
                    
                    start_game(enemy , g , tu);
                    return;

                }

                int jj;
                int j;
                int m = 0;
               
                jj = tu.choose_card(b);
                    
                int o;
                o = tu.yesorno(target->get_name() + " do you want to choose a card?");
                
                    
                    if(o == 0)
                    {
                        for(card & s:enemy.hand)
                        {
                            if(s.get_type() == cardtype::defense || s.get_type() == cardtype::versatile)
                            {
                                enemy.c.push_back(s);
                            }
                        }
                        if(enemy.c.empty())
                        {
                            tu.p("you dont have any defense card");
                            
                        }
                        else
                        {
                            if(target->get_name() == enemy.hero.get_name())
                            {
                                for(card & s:enemy.c)
                                {
                                    if(s.get_owner() == cardowner::hero || s.get_owner() == cardowner::any)
                                    {
                                        enemy.b.push_back(s);
                                    }
                                }
                            }
                            if(enemy.hero.get_name() == "Dracula")
                            {
                                if(target->get_name() == enemy.sidekicks[0].get_name() || target->get_name() == enemy.sidekicks[1].get_name() || target->get_name() == enemy.sidekicks[2].get_name())
                                {
                                    for(card & s:enemy.c)
                                    {
                                        if(s.get_owner() == cardowner::sidekick || s.get_owner() == cardowner::any)
                                        {
                                            enemy.b.push_back(s);
                                        }
                                    }
                                }
                            }
                            if(enemy.hero.get_name() == "Sherlock Holmes")
                            {
                                if(target->get_name() == enemy.sidekicks[0].get_name())
                                {
                                    for(card & s:enemy.c)
                                    {
                                        if(s.get_owner() == cardowner::sidekick || s.get_owner() == cardowner::any)
                                        {
                                            enemy.b.push_back(s);
                                        }
                                    }
                                }
                            }
                            if(enemy.b.empty())
                            {
                                tu.p( target->get_name() + " there isn't any defense card for you");
                                
                            }
                            else
                            {
                                

                                j = tu.choose_card(enemy.b);
                                m++;
                                attack(enemy , g , &enemy.b[j] ,tu, &b[jj]);
                                for(auto i = enemy.hand.begin() ; i != enemy.hand.end() ; i++)
                                {
                                    if(enemy.b[j].get_name() == i->get_name())
                                    {
                                        enemy.hand.erase(i);
                                        break;
                                    }
                                }
                                for(auto i = hand.begin() ; i != hand.end() ; i++)
                                {
                                    if(b[jj].get_name() == i->get_name())
                                    {
                                        hand.erase(i);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    else if(o == 1)
                    {
                    
                    }
                    
                
                    if(m == 0)
                    {
                        attack(enemy , g , &b[jj] , tu);
                        for(auto i = hand.begin() ; i != hand.end() ; i++)
                        {
                            if(b[jj].get_name() == i->get_name())
                            {
                                hand.erase(i);
                                break;
                            }
                        }
                    }
                        
                
                
                action--;
                hero.set_status();
                enemy.hero.set_status();
                for(auto &s:sidekicks)
                {
                    s.set_status();
                }
                for(auto &s:enemy.sidekicks)
                {
                    s.set_status();
                }
            }
            else if(z == 3)
            {
                tu.show_card(hand);
            }
            else if(z == 4)
            {
                tu.draw_status_window(*this,false);
                int d = 0;
            cout <<"Hero: " << hero.get_name() << endl << "Health: " << hero.get_hp() << endl<< "Hand: " ;
            for(auto s:hand)
            {
                    d++;
            }
            cout << d << endl << "Deck: ";
            d = 0;
            for(auto s:deck)
            {
                    d++;
            }
            cout << d << endl << "Space: " << hero.get_location()->get_id() << endl << endl ;
            if(hero.get_name() == "Dracula")
            {
                    if(sidekicks[0].get_status())
                    {
                            cout << "Sister 1    " << "Health: " << sidekicks[0].get_hp() << " Space: " << sidekicks[0].get_location()->get_id() << endl;
                    }
                    if(sidekicks[1].get_status())
                    {
                            cout << "Sister 2    " << "Health: " << sidekicks[1].get_hp() << " Space: " << sidekicks[1].get_location()->get_id() << endl;
                    }
                    if(sidekicks[2].get_status())
                    {
                            cout << "Sister 3    " << "Health: " << sidekicks[2].get_hp() << " Space: " << sidekicks[2].get_location()->get_id() << endl;
                    }
            }
            else if(hero.get_name() == "Sherlock Holmes")
            {
                    if(sidekicks[0].get_status())
                    {
                        cout << "Dr.Watson    " << "Health: " << sidekicks[0].get_hp() << " Space: " << sidekicks[0].get_location()->get_id() << endl;
                    }
            }
            else if(hero.get_name() == "Invisible Man")
            {
                    cout << "Fogs space:    " << fogs[0]->get_id() << " , " << fogs[1]->get_id() << " , " << fogs[2]->get_id() << endl;
            }
            
            }
            else if(z == 5)
            {
                tu.draw_status_window(enemy,true);
                int d = 0;
            cout <<"Hero: " << enemy.hero.get_name() << endl << "Health: " << enemy.hero.get_hp() << endl <<"Hand: " ;
            for(auto s:enemy.hand)
            {
                    d++;
            }
            cout << d << endl << "Deck: ";
            d = 0;
            for(auto s:enemy.deck)
            {
                    d++;
            }
            cout << d << endl << "Space: " << hero.get_location()->get_id() << endl << endl ;
                if(enemy.hero.get_name() == "Dracula")
                {
                    if(enemy.sidekicks[0].get_status())
                    {
                            cout << "Sister 1    " << "Health: " << enemy.sidekicks[0].get_hp() << " Space: " << enemy.sidekicks[0].get_location()->get_id() << endl;
                    }
                    if(enemy.sidekicks[1].get_status())
                    {
                            cout << "Sister 2    " << "Health: " << enemy.sidekicks[1].get_hp() << " Space: " << enemy.sidekicks[1].get_location()->get_id() << endl;
                    }
                    if(enemy.sidekicks[2].get_status())
                    {
                            cout << "Sister 3    " << "Health: " << enemy.sidekicks[2].get_hp() << " Space: " << enemy.sidekicks[2].get_location()->get_id() << endl;
                    }
                }
            else if(enemy.hero.get_name() == "Sherlock Holmes")
            {
                    if(enemy.sidekicks[0].get_status())
                    {
                        cout << "Dr.Watson    " << "Health: " << enemy.sidekicks[0].get_hp() << " Space: " << enemy.sidekicks[0].get_location()->get_id() << endl;
                    }
            }
                else if(enemy.hero.get_name() == "Invisible Man")
            {
                    cout << "Fogs space:    " << enemy.fogs[0]->get_id() << " , " << enemy.fogs[1]->get_id() << " , " << enemy.fogs[2]->get_id() << endl;
            }
            }
            else if(z == 7)
            {
                tu.showhelp( "================ HELP ================ \n"
                "Objective:\n"
                "Defeat the enemy Hero by reducing their Health to 0\n"

                "Actions:\n"
                "- Maneuver: Move your fighter and draw one card\n"
                "- Attack: Attack an adjacent enemy\n"
                "- Scheme: Play a special card effect\n"

                "Card Types:\n"
                "- Attack\n"
                "- Defense\n"
                "- Versatile\n"
                "- Scheme\n"
                "Good luck and have fun!\n"
                "======================================\n" , 8);
            }
            else if(z == 6)
            {
                ui l;
                int choice = l.yesorno("Do you want to save the game?");
                if(choice == 0)
                {
                    string d;
                    d = tu.get_text_input("please choose a name");
                    save(d , enemy);
                }
                else
                {

                }
                cout << "Game Exited" << endl;
                exit(0);
                
            }
            alive();
            enemy.alive();
            if(!hero.get_status() || !enemy.hero.get_status())
            {
                break;
            }
        
    }
    if(hand.size() > 7)
    {
        tu.p("You have more than 7 cards");
        tu.p("Please choose card to discard");
        int hh; 
        while (hand.size() > 7)
        {
            hh = tu.choose_card(hand);
            hand.erase(hand.begin() + hh); 
        }
    }
    action = 2;
}
void game::card_effects(card * ca , game & enemy , map & g , ui tu, card * eca )
{
    if(ca->get_name() == "feeding frenzy")
    {
        feeding_frenzy(*ca);
    }
    if(ca->get_name() == "mistform")
    {
        mistform(g , tu);
    }
    if(ca->get_name() == "ambush")
    {
        ambush(*ca ,enemy);
    }
    if(ca->get_name() == "baptism of blood")
    {
        baptism_of_blood( g , tu);
    }
    if(ca->get_name() == "beastform")
    {
        beastform(*ca , tu);
    }
    if(ca->get_name() == "dash")
    {
        dash(g , tu);
    }
    if(ca->get_name() == "exploit")
    {
        expolit();
    }
    if(ca->get_name() == "look into my eyes")
    {
        look_into_my_eyes( enemy , *ca , eca);
    }
    if(ca->get_name() == "pray upon")
    {
        prey_upon( g ,enemy);
    }
    if(ca->get_name() == "ravening seduction")
    {

    }
    if(ca->get_name() == "thirst for sustenance")
    {
        thirst_for_sustenance(g);
    }
    if(ca->get_name() == "feint")
    {

    }
    if(ca->get_name() == "administer aid")
    {
        administer_aid( g , tu);
    }
    if(ca->get_name() == "counterpunch")
    {
        counterpunch( g , enemy , tu);
    }
    if(ca->get_name() == "deduce strategy")
    {
        deduce_strategy( *ca , eca);
    }
    if(ca->get_name() == "education never ends")
    {
        education_never_ends(enemy);
    }
    if(ca->get_name() == "eliminate the impossible")
    {
        eliminate_the_impossible(enemy , tu);
    }
    if(ca->get_name() == "feint_")
    {

    }
    if(ca->get_name() == "fixed point in a changing age")
    {
        fixed_point_in_a_changing_age(enemy);
    }
    if(ca->get_name() == "master of disguise")
    {
        master_of_disguise(enemy ,g , tu);
    }
    if(ca->get_name() == "the game is afoot")
    {
        the_game_is_afoot(g , tu);
    }
    if(ca->get_name() == "service revolver")
    {
        
    }
    if(ca->get_name() == "study methodes")
    {
        study_methods(enemy , tu);
    }
    if(ca->get_name() == "coded notes")
    {
        coded_notes(tu);
    }
    if(ca->get_name() == "convert preparation")
    {
        covert(g, tu);
    }
    if(ca->get_name() == "dreaming of revenge")
    {
        dreaming(enemy);
    }
    if(ca->get_name() == "emerge from mist")
    {
        emerge_from_mist(*ca);
    }
    if(ca->get_name() == "impossible to see")
    {
        impossible_to_see(eca);
    }
    if(ca->get_name() == "into thin air")
    {
        into_thin_air(g , tu);
    }
    if(ca->get_name() == "lurking")
    {
        lurking(tu , g);
    }
    if(ca->get_name() == "reign of terror")
    {
        reign_of_terror(enemy);
    }
    if(ca->get_name() == "rolling fog")
    {
        rolling_fog(g , tu);
    }
    if(ca->get_name() == "slip away")
    {
        slip_away();
    }
    if(ca->get_name() == "step lightly")
    {
        step_lightly(enemy);
    }
    if(ca->get_name() == "vanish")
    {
        vanish();
    }
}
void game::feeding_frenzy(card & ca)
{
    ui ee;
    ee.showsomthing(ca.get_name() ,2);
    cout << "               feeding frenzy" << endl;
    int t = 0;
    for(auto &sister: sidekicks)
    {
        int i = target->get_location()->get_zone().size();
        int j = sister.get_location()->get_zone().size();
        for(int z= 0 ; z < i ; z++)
        {
            for(int m = 0 ; m < j ; m++)
            {
                if(target->get_location()->get_zone()[z] == sister.get_location()->get_zone()[m])
                {
                    t+=1;
                }
            }
        }
        
    } 
    ca.set_value(t+2);
}
void game::mistform(map & g, ui ee)
{
    ee.showsomthing("Mistform" , 2);
    cout << "               mistform" << endl;
    while(true)
    {

        try
        {
            g.move2(hero , ee);
            break;
        }
        catch(const std::invalid_argument& e)
        {
            ee.p(e.what());
        }
    }  
    action++;
}
void game::ambush(card& ca ,game & enemy)
{
    ui ee;
    ee.showsomthing("Ambush" , 2);
    cout << "               ambush" << endl;
    int random = rand() % enemy.hand.size();
    ca.set_value(enemy.hand[random].get_boost());
    enemy.hand.erase(enemy.hand.begin() + random);
}
void game::baptism_of_blood(map & g , ui ee)
{
   ee.showsomthing("Baptism of blood" , 2);
    cout << "               baptism of blood" << endl;
    int a;
    int b;
    int c;
    hero.set_hp(hero.get_hp() + 2);
    if(!sidekicks[0].get_status())
    {
        a++;
    }
    if(!sidekicks[1].get_status())
    {
        b++;
    }
    if(!sidekicks[2].get_status())
    {
        c++;
    }
    if(a == 1)
    {
        sidekicks[0].set_hp(1);
        sidekicks[0].set_status();
        while(true)
        {
            try
            {
                g.move3(hero , sidekicks[0] , g , ee);
                break;
            }
            catch(const std::invalid_argument& e)
            {
                ee.p(e.what());
                std::cerr << e.what() << '\n';
            }
        }  
    }
    if(a == 0 && b == 1)
    {
        sidekicks[1].set_hp(1);
        sidekicks[1].set_status();
        while(true)
        {
            try
            {
                g.move3(hero , sidekicks[1] ,g , ee);
                break;
            }
            catch(const std::invalid_argument& e)
            {
                ee.p(e.what());
                std::cerr << e.what() << '\n';
            }
        }  
    }
    if(a == 0 && b == 0 && c == 1)
    {
        sidekicks[2].set_hp(1);
        sidekicks[2].set_status();
        while(true)
        {
            try
            {
                g.move3(hero , sidekicks[2] , g , ee);
                break;
            }
            catch(const std::invalid_argument& e)
            {
                ee.p(e.what());
                std::cerr << e.what() << '\n';
            }
        }  
    }
}
void game::beastform(card& ca , ui ee)
{
    ee.showsomthing("Beastform" , 2);
    cout << "               beastform" << endl;
    int q = 0;
    cout << "choose the cards you want to discard (enter -1 to end)" << endl;
    
    int qq = 1;
    int counter = 0;
    for(;qq != -1 ;)
    {
        qq = ee.choose_card(hand);
        
        if(qq == -1)
        {
            break;
        }
        else
        {
            counter++;
            hand.erase(hand.begin() + qq);
        }
    }
    ca.set_value(counter +6);
}
void game::dash(map & g , ui tu)
{
    tu.showsomthing("Dash" , 2);
    cout << "               dash" << endl;
    for(int i = 0 ; i < 3 ; i++)
    {
        g.move(active_character->get_name() , active_character->get_location()->get_id() ,* active_character , g , tu);
    }
}
void game::expolit()
{
    ui ee;
    ee.showsomthing("Expolit" ,2);
    cout << "                expolit" << endl;
    int random;
    random = rand()% deck.size();
    hand.push_back(deck[random]);
    deck.erase(deck.begin() + random);
}
void game::look_into_my_eyes(game & enemy , card & ca , card * eca)
{
    ui ee;
    ee.showsomthing("Look into my eyes" , 2);
    cout << "               look into my eyes" << endl;
    if(eca != nullptr)
    {
        ca.set_value(1 + eca->get_boost());
    }
}
void game::prey_upon(map & g , game & enemy)
{
    ui ee;
    ee.showsomthing("Prey upon" , 2);
    cout << "               prey upon" << endl;
    if(g.pray_upon(hero) == 3)
    {
        enemy.hero.set_hp(enemy.hero.get_hp() -1);
        enemy.sidekicks[0].set_hp(enemy.sidekicks[0].get_hp() -1);
    }
    if(g.pray_upon(hero) == 2)
    {
        enemy.hero.set_hp(enemy.hero.get_hp() -1);
    }
    if(g.pray_upon(hero) == 1)
    {
        enemy.sidekicks[0].set_hp(enemy.sidekicks[0].get_hp() -1);
    }
    if(g.pray_upon(hero) == 0)
    {
        cout << " " << endl;
    }
}
void game::administer_aid(map& g , ui ee)
{
    ee.showsomthing("Administer aid" , 2);
    cout << "                administer aid" << endl;
    int ch;
    cout << "where do you want to place Dr.Watson?" << endl;
    
    ch = hero.get_location()->show_neighbors(g ,"where do you want to place Dr.Watson?");
        
    if(ch != 400)
    {
        sidekicks[0].get_location()->set_thisspacef();
        sidekicks[0].set_location(g.get_space(ch));
        g.set_location("Dr.Watson" ,ch);
    }
    
    hero.set_hp(hero.get_hp() + 1);
    int random;
    if(deck.size() > 0)
    {
        int random = rand()%deck.size();
        hand.push_back(deck[random]);
        deck.erase(deck.begin() + random);
    }
    else
    {
        ee.p("deck is empty");
        cout << "deck is empty" << endl;
        hero.set_hp(hero.get_hp() - 2);
        hero.set_status();
        sidekicks[0].set_hp(hero.get_hp() - 2);
        sidekicks[0].set_status();
        if(hero.get_name() == "Dracula")
        {
            sidekicks[1].set_hp(hero.get_hp() - 2);
            sidekicks[2].set_hp(hero.get_hp() - 2);
            sidekicks[1].set_status();
            sidekicks[2].set_status();
        }
    }
}
void game::counterpunch(map & g , game& enemy ,ui ee)
{
    ee.showsomthing("Counter punch" , 2);
    cout << "               counter punch" << endl;
    int y = 0;
    vector <character*> enemies = get_neighborenemy(*active_character , enemy);
    for(character* e : enemies)
    {
        e->set_hp(e->get_hp() - 2);
        y++;
    }
    if(y == 0)
    {
        ee.p("there isnt any enemies next to you");
        cout << "there isnt any enemies next to you ..." << endl;
    }
}
void game::thirst_for_sustenance(map & g)
{
    ui ee;
    ee.showsomthing("Thirst for sustenance" ,2);
    cout << "               thirst for sustenance" << endl;
    if(damage> 0)
    {
        int s;
        cout << "where do you want to place Dracula?" << endl;
        s = target->get_location()->show_neighbors(g , "where do you want to place Dracula?");
        hero.get_location()->set_thisspacef();
        hero.set_location(g.get_space(s));
        g.set_location("Dracula" ,s);
    }
}
void game::coded_notes(ui ee)
{
    ee.showsomthing("Coded notes" , 2);
    for(int i = 0 ; i < 3 ; i++)
    {
        int random = rand() % deck.size();
        hand.push_back(deck[random]);
        deck.erase(deck.begin() + random);
    }
    ee.p("Choose 2 card to put them on the top of deck '\n' select in order");
    for(int i = 0 ; i < 2 ; i++)
    {
        int tt = ee.choose_card(hand);
        deck.push_back(hand[tt]);
        hand.erase(hand.begin()+tt);
    }
}
void game::covert(map& g , ui ee)
{
    //
    ee.showsomthing("Covert" ,2 );
    int random = rand() % deck.size();
    hand.push_back(deck[random]);
    deck.erase(deck.begin() + random);
    vector <int> u = {fogs[0]->get_id() , fogs[1]->get_id() , fogs[2]->get_id()};
    int cc = ee.choose_space(g,"Which fog token do you want to move?" , u);
    if(cc == 0)
    {
        for(int i = 0 ; i < 2 ; i++)
        {
            int ggg =fogs[0]->show_neighbors_fog(g, "where do you want to place fog?");
            fogs[0] = g.get_space(ggg);
        }
    }
    if(cc == 1)
    {
        for(int i = 0 ; i < 2 ; i++)
        {
            int ggg =fogs[1]->show_neighbors_fog(g, "where do you want to place fog?");
            fogs[1] = g.get_space(ggg);
        }
    }
    if(cc == 2)
    {
        for(int i = 0 ; i < 2 ; i++)
        {
            int ggg = fogs[2]->show_neighbors_fog(g, "where do you want to place fog?");
            fogs[2] = g.get_space(ggg);
        }
    }
}
void game::dreaming(game& enemy)
{
    ui ee;
    ee.showsomthing("Dreaming" , 2);
    if(hero.get_location() == fogs[0] || hero.get_location() == fogs[1] || hero.get_location() == fogs[2])
    {
        if(enemy.hero.get_location() == fogs[0] || enemy.hero.get_location() == fogs[1] || enemy.hero.get_location() == fogs[2])
        {
            enemy.hero.set_hp(enemy.hero.get_hp() - 1);
        }
        for(auto e:enemy.sidekicks)
        {
            if(e.get_location() == fogs[0] || e.get_location() == fogs[1] || e.get_location() == fogs[2])
            {
                e.set_hp(enemy.hero.get_hp() - 1);
            }
        }
    }
}
void game::emerge_from_mist(card & cardd)
{
    ui ee;
    ee.showsomthing("Emerge from mist" ,2);
    if(hero.get_location() == fogs[0] || hero.get_location() == fogs[1] || hero.get_location() == fogs[2])
    {
        cardd.set_value(5);
    }
}
void game::impossible_to_see(card* ecard)
{
    ui ee;
    ee.showsomthing("Impossible to see" ,2);
    ecard->set_value(0);
}
void game::into_thin_air(map& g ,ui ee)
{
    ee.showsomthing("Into thin air" , 2);
    vector <int> u = {fogs[0]->get_id() , fogs[1]->get_id() , fogs[2]->get_id()};
    g.move_invisibleman("Invisible Man" ,hero.get_location()->get_id() , hero , g , *this , ee);
    int cc = ee.choose_space(g,"Which fog token do you want to move?" , u);
    if(cc == 0)
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            int ggg =fogs[0]->show_neighbors_fog(g, "where do you want to place fog?");
            fogs[0] = g.get_space(ggg);
        }
    }
    if(cc == 1)
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            int ggg =fogs[1]->show_neighbors_fog(g, "where do you want to place fog?");
            fogs[1] = g.get_space(ggg);
        }
    }
    if(cc == 2)
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            int ggg = fogs[2]->show_neighbors_fog(g, "where do you want to place fog?");
            fogs[2] = g.get_space(ggg);
        }
    }
}
void game::lurking(ui ee , map& g)
{
    ee.showsomthing("Lurking" ,2);
    vector <int> u = {fogs[0]->get_id() , fogs[1]->get_id() , fogs[2]->get_id()};
    int random = rand() % deck.size();
    hand.push_back(deck[random]);
    deck.erase(deck.begin() + random);
    vector<string> d = {"move hero to space with fog token" , "move fog token up to 3 spaes"};
    int r = ee.choose_acharacter("choose..." ,d );
    if(r == 0)
    {
        
        while (true)
        {
            if(fogs[0]->get_thisspace()  != "e" && fogs[1]->get_thisspace()  != "e" && fogs[2]->get_thisspace()  != "e")
            {
                ee.p("You can't do this action");
                break;
            }
            int cc = ee.choose_space(g, "Where do you want to place Invisible Man?" ,u );
            if(cc == 0)
            { 
                if(fogs[0]->get_thisspace() == "e")
                {
                    hero.set_location(fogs[0]);
                    g.set_location("Invisible Man" , fogs[0]->get_id());
                    break;
                }
                else
                {
                    ee.p("You can't choose this space");

                }
            }
            if(cc == 1)
            {
                if(fogs[1]->get_thisspace() == "e")
                {
                    hero.set_location(fogs[1]);
                    g.set_location("Invisible Man" , fogs[1]->get_id());
                    break;
                }
                else
                {
                    ee.p("You can't choose this space");

                }
            }
            if(cc == 2)
            {
                if(fogs[2]->get_thisspace() == "e")
                {
                    hero.set_location(fogs[2]);
                    g.set_location("Invisible Man" , fogs[2]->get_id());
                    break;
                }
                else
                {
                    ee.p("You can't choose this space");

                }
            }
        }
        
        
    }
    else
    {
        int cc = ee.choose_space(g,"Which fog do you want to move?" , u);
        if(cc == 0)
        {
            for(int i = 0 ; i < 3 ; i++)
            {
                int ggg = fogs[0]->show_neighbors_fog(g, "where do you want to place fog?");
                fogs[0] = g.get_space(ggg);
            }
        }
        if(cc == 1)
        {
            for(int i = 0 ; i < 3 ; i++)
            {
                int ggg = fogs[1]->show_neighbors_fog(g, "where do you want to place fog?");
                fogs[1] = g.get_space(ggg);
            }
        }
        if(cc == 2)
        {
            for(int i = 0 ; i < 3 ; i++)
            {
                int ggg = fogs[2]->show_neighbors_fog(g, "where do you want to place fog?");
                fogs[2] = g.get_space(ggg);
            }
        }
    }
}
void game::reign_of_terror(game& enemy)
{
    ui ee;
    ee.showsomthing("Reign of terror" ,2);
    if(hero.get_location() == fogs[0] || hero.get_location() == fogs[1] || hero.get_location() == fogs[2])
    {
        enemy.hero.set_hp(enemy.hero.get_hp() - 2);
        for(auto i:enemy.sidekicks)
        {
            i.set_hp(i.get_hp()- 2);
            i.get_status();
        }
        enemy.hero.set_status();

    }
}
void game::rolling_fog(map& g , ui ee)
{
    ee.showsomthing("Rolling fog" , 2);
    vector <int> u = {fogs[0]->get_id() , fogs[1]->get_id() , fogs[2]->get_id()};
    int cc = ee.choose_space(g,"Which fog token do you want to move?" , u);
    if(cc == 0)
    {
        int ggg =fogs[0]->show_neighbors_fog(g, "where do you want to place fog?");
        fogs[0] = g.get_space(ggg); 
    }
    if(cc == 1)
    {
        int ggg =fogs[1]->show_neighbors_fog(g, "where do you want to place fog?");
        fogs[1] = g.get_space(ggg); 
    }
    if(cc == 2)
    {
        int ggg = fogs[2]->show_neighbors_fog(g, "where do you want to place fog?");
        fogs[2] = g.get_space(ggg);
    }
    action++ ;
}
void game::slip_away()
{
    

}
void game::step_lightly(game& enemy)
{
    //
    ui ee;
    if(!get_neighborenemy(hero , enemy).empty())
    {
        if(hero.get_location() == fogs[0] || hero.get_location() == fogs[1] || hero.get_location() == fogs[2])
        {
            int y = ee.choose_aacharacter("choose target" , get_neighborenemy(hero , enemy));
            get_neighborenemy(hero, enemy)[y]->set_hp(get_neighborenemy(hero, enemy)[y]->get_hp() - 3);
           
        }
        else
        {
            int y = ee.choose_aacharacter("choose target" , get_neighborenemy(hero , enemy));
            get_neighborenemy(hero, enemy)[y]->set_hp(get_neighborenemy(hero, enemy)[y]->get_hp() - 1);
        }
    }
    
}
void game::vanish()
{
    //
    ui ee;
    ee.showsomthing("Vanish" ,2);
    hero.set_hp(hero.get_hp() + 1);
    if(action == 2)
    {
        action = 0;
    }
}
vector<character> game::get_sidekicks()
{
    return sidekicks;
}
vector <character*> game::get_neighborenemyzone(character & cha ,game& enemy)
{
    vector<character*> ch; 
    if(cha.get_location()->has_zone(zone::ice))
    {
        if(enemy.hero.get_location()->has_zone(zone::ice))
        {
            ch.push_back(&enemy.hero);
        }
        if(enemy.hero.get_name() != "Invisible Man")
        {
            for(auto &s:enemy.sidekicks)
            {
                if(s.get_location()->has_zone(zone::ice))
                {
                    ch.push_back(&s);
                }
            }
        }
        
    }
    if(cha.get_location()->has_zone(zone::blue))
    {
        if(enemy.hero.get_location()->has_zone(zone::blue))
        {
            ch.push_back(&enemy.hero);
        }
        if(enemy.hero.get_name() != "Invisible Man")
        {
            for(auto &s:enemy.sidekicks)
            {
                if(s.get_location()->has_zone(zone::blue))
                {
                    ch.push_back(&s);
                }
            }
        }
    }
    if(cha.get_location()->has_zone(zone::broun))
    {
        if(enemy.hero.get_location()->has_zone(zone::broun))
        {
            ch.push_back(&enemy.hero);
        }
        if(enemy.hero.get_name() != "Invisible Man")
        {
            for(auto &s:enemy.sidekicks)
            {
                if(s.get_location()->has_zone(zone::broun))
                {
                    ch.push_back(&s);
                }
            }
        }
    }
    if(cha.get_location()->has_zone(zone::gray))
    {
        if(enemy.hero.get_location()->has_zone(zone::gray))
        {
            ch.push_back(&enemy.hero);
        }
        if(enemy.hero.get_name() != "Invisible Man")
        {
            for(auto &s:enemy.sidekicks)
            {
                if(s.get_location()->has_zone(zone::gray))
                {
                    ch.push_back(&s);
                }
            }
        }
    }
    if(cha.get_location()->has_zone(zone::green))
    {
        if(enemy.hero.get_location()->has_zone(zone::green))
        {
            ch.push_back(&enemy.hero);
        }
        for(auto &s:enemy.sidekicks)
        {
            if(s.get_location()->has_zone(zone::green))
            {
                ch.push_back(&s);
            }
        }
    }
    if(cha.get_location()->has_zone(zone::purple))
    {
        if(enemy.hero.get_location()->has_zone(zone::purple))
        {
            ch.push_back(&enemy.hero);
        }
        for(auto &s:enemy.sidekicks)
        {
            if(s.get_location()->has_zone(zone::purple))
            {
                ch.push_back(&s);
            }
        }
    }
    if(cha.get_location()->has_zone(zone::white))
    {
        if(enemy.hero.get_location()->has_zone(zone::white))
        {
            ch.push_back(&enemy.hero);
        }
        for(auto &s:enemy.sidekicks)
        {
            if(s.get_location()->has_zone(zone::white))
            {
                ch.push_back(&s);
            }
        }
    }
    return ch;
}
void game::education_never_ends(game & enemy)
{
    ui ee;
    ee.showsomthing("Education never ends" ,2);
    cout << "                education never ends" << endl;
    if(damage > 0)
    {
        if(enemy.deck.size() > 0)
        {
            int random = rand()%enemy.deck.size();
            enemy.hand.push_back(enemy.deck[random]);
            enemy.deck.erase(enemy.deck.begin() + random);
        }
        else
        {
            cout << "deck is empty" << endl;
            enemy.hero.set_hp(enemy.hero.get_hp() - 2);
            enemy.hero.set_status();
            enemy.sidekicks[0].set_hp(enemy.hero.get_hp() - 2);
            enemy.sidekicks[0].set_status();
            if(enemy.hero.get_name() == "Dracula")
            {
                enemy.sidekicks[1].set_hp(hero.get_hp() - 2);
                enemy.sidekicks[2].set_hp(hero.get_hp() - 2);
                enemy.sidekicks[1].set_status();
                enemy.sidekicks[2].set_status();
            }
        }
    }
    else
    {
        for(int i = 0 ; i < 2 ; i++)
        {
            if(damage > 0)
            {
                if(enemy.deck.size() > 0)
                {
                    int random = rand()%enemy.deck.size();
                    enemy.hand.push_back(enemy.deck[random]);
                    enemy.deck.erase(enemy.deck.begin() + random);
                }
                else
                {
                    cout << "deck is empty" << endl;
                    enemy.hero.set_hp(enemy.hero.get_hp() - 2);
                    enemy.hero.set_status();
                    enemy.sidekicks[0].set_hp(enemy.hero.get_hp() - 2);
                    enemy.sidekicks[0].set_status();
                    if(enemy.hero.get_name() == "Dracula")
                    {
                        enemy.sidekicks[1].set_hp(hero.get_hp() - 2);
                        enemy.sidekicks[2].set_hp(hero.get_hp() - 2);
                        enemy.sidekicks[1].set_status();
                        enemy.sidekicks[2].set_status();
                    }
                }
            }
        }
    }
}
void game::eliminate_the_impossible(game& enemy , ui ee)
{
    ee.showsomthing("Eliminate the impossible" ,2);
    cout << "               eliminate the impossible" << endl;
    int choice;
    cout << "choose a card you want to discard" << endl;
    
    ee.p("choose a card you want to discard");
    choice = ee.choose_card(enemy.hand);
    enemy.hand.erase(enemy.hand.begin() + choice);
}
void game::fixed_point_in_a_changing_age(game& enemy)
{
    ui ee;
    ee.showsomthing("Fixed point in a changing age" ,2);
    cout << "               fixed point in a changing age" << endl;
    for(auto &s:active_character->get_location()->get_neighbors())
    {
        if(s == hero.get_location())
        {
            active_character->set_hp(active_character->get_hp() + 1);
            hero.set_hp(hero.get_hp() + 1);
        }
    }
}
void game::deduce_strategy(card& ca , card* eca)
{
    ui ee;
    ee.showsomthing("Deduce strategy" ,2);
    cout << "               deduce strategy" << endl;
    if(eca != nullptr)
    {
        eca->set_value(eca->get_boost());
    }
}
vector<space*> game::get_fog()
{
    return fogs;
}
void game::master_of_disguise(game & enemy , map & g , ui ee)
{
    ee.showsomthing("Master of disguise" ,2);
    cout << "               master of disguise" << endl;
    cout << "who is your target?" << endl << "1. Dracula  2. sister1  3. sister2  4. sister3" << endl;
    std::vector <string> d ={"Dracula" , "sister1" , "sister2" , "sister3"};
    int yy;
    
    while (true)
    {
        yy =ee.choose_acharacter("who is your target?" , d) ;
        if(yy == 0)
        {
            if(enemy.hero.get_status())
            {
                target = &enemy.hero;
                break;
            }
            else
            {
                ee.p("this character is dead");
                cout << "this character is dead... please choose another character" << endl;
            }
        }
        else if(yy == 1 || yy == 2 || yy == 3)
        {
            if(enemy.sidekicks[yy-1].get_status())
            {
                target = &enemy.sidekicks[yy-1];
                break;
            }
            else
            {
                ee.p("this character is dead");
                cout << "this character is dead... please choose another character" << endl;
            }
        }
        
    }
    space* z = hero.get_location();
    hero.get_location()->set_thisspacef();
    hero.set_location(target->get_location());
    g.set_location(hero.get_name() , hero.get_location()->get_id());
    target->get_location()->set_thisspacef();
    target->set_location(z);
    g.set_location(target->get_name() , target->get_location()->get_id());
    target->set_hp(target->get_hp() - 1);
}
void game::the_game_is_afoot(map &g , ui tu)
{
    tu.showsomthing("The game is afoot" ,2);
    cout << "                the game is afoot" << endl;
    for(int i = 0 ; i < 3 ; i++)
    {
        g.move(hero.get_name(), hero.get_location()->get_id(), hero , g , tu);
    }
}
void game::study_methods(game & enemy , ui ee)
{
    ee.showsomthing("Study methods", 2);
    cout << "               study methods" << endl;
    if(hero.get_name() == "Sherlock Holmes")
    {
        if(damage > 0)
        {
            ee.show_card(enemy.hand);
            
        }
    }
    else
    {
        if(damage == 0)
        {
            ee.show_card(enemy.hand);
            
        }
    }
    
}
vector <character*> game::get_neighborenemy(character& cha , game& enemy)
{
    vector<character*> neighborenemy;
    if(enemy.hero.get_status())
    {
        for(space* neighbor:cha.get_location()->get_neighbors())
        {
            if(enemy.hero.get_location() == neighbor)
            {
                neighborenemy.push_back(&enemy.hero);
            }
        }
    }
    if(enemy.hero.get_name() != "Invisible Man")
    {
        for(character& sidekick: enemy.sidekicks)
        {
            if(sidekick.get_status())
            {
                for(space* neighbor:cha.get_location()->get_neighbors())
                {
                    if(sidekick.get_location() == neighbor)
                    {
                        neighborenemy.push_back(&sidekick);
                    }
                }
            }
        }
    }
    
    return neighborenemy;
}
void game::attack(game & enemy , map & g , card* ca, ui tu,card* eca )
{
    if(eca == nullptr)
    {
        if(ca->get_time() == timing::beforcombat)
        {
            card_effects(ca , enemy , g , tu);
        }
        else if(ca->get_time() == timing::duringccombat)
        {
            card_effects(ca , enemy , g , tu);
        }
        target->set_hp(target->get_hp() - ca->get_value());
        damage= ca->get_value();
        if(ca->get_time() == timing::aftercombat)
        {
            card_effects(ca , enemy , g , tu);
        }
    }
    else
    {
        if(ca->get_time() == timing::beforcombat)
        {
            card_effects(ca , enemy , g, tu , eca );
        }
        if(eca->get_time() == timing::beforcombat)
        {
            card_effects(eca , enemy , g , tu, ca );
        }
        if(ca->get_time() == timing::duringccombat)
        {
            card_effects(ca , enemy , g , tu, eca );
        }
        if(eca->get_time() == timing::duringccombat)
        {
            card_effects(eca , enemy , g , tu, ca );
        }
        if(target->get_name() == "Invisible Man" && (target->get_location() == enemy.fogs[0] || target->get_location() == enemy.fogs[1] || target->get_location() == enemy.fogs[2]))
        {
            damage = eca->get_value() - (ca->get_value()+1);
            if(damage < 0)
            {
                damage = 0;
            }
        }
        else
        {
            damage = eca->get_value() - ca->get_value();
            if(damage < 0)
            {
                damage = 0;
            }
        }
        target->set_hp(target->get_hp() - damage);
        if(ca->get_time() == timing::aftercombat)
        {
            card_effects(ca , enemy , g , tu, eca );
        }
        if(eca->get_time() == timing::aftercombat)
        {
            card_effects(eca , enemy , g , tu, ca );
        }
    }
    tu.showsomthing("  Damage: " + to_string(damage),3);
    cout <<"damage: " << damage << endl;
}
void game::choose_fighter(game & enemy , map& g , ui e)
{
    
    vector<character*> available_characters;

    if(hero.get_status())
    {
        if(!get_neighborenemy(hero, enemy).empty())
        {
            available_characters.push_back(&hero);
        }
    }
    bool canattack = false;
    if(hero.get_name() != "Invisible Man")
    {
        for(character &c : sidekicks)
        {
            if(c.get_status())
            {
                

                if(c.get_attack_type() == "melee")
                {
                    canattack = !get_neighborenemy(c, enemy).empty();
                }
                else
                {
                    canattack = !get_neighborenemy(c, enemy).empty() || !get_neighborenemyzone(c, enemy).empty();
                }

                if(canattack)
                    available_characters.push_back(&c);
            }    

        
        }
    }
    
    int choice;
    if(available_characters.empty())
    {
        e.p("No fighter can attack");
        throw invalid_argument("No fighter can attack");
    }
    else
    {
        choice = e.choose_aacharacter("Choose your active character", available_characters);
        active_character = available_characters[choice];
    }    
}   
void game::choose_target(game & enemy , ui ee)
{
    cout << "choose your target" << endl;
    if(active_character->get_attack_type() == "melee")
    {
        vector <character*> enemies = get_neighborenemy(*active_character , enemy);
        int i = 1;
        
        int choice;
        while(true)
        {
            choice =ee.choose_aacharacter("choose your target" , enemies);
            if(enemies[choice]->get_status())
            {
                target = enemies[choice];
                break;
            }
            else
            {
                cout << "this character is dead... please choose another character" << endl;
                ee.p("this character is dead");
            }
        }
    }
    else
    {
        vector <character*> enemies = get_neighborenemyzone(*active_character , enemy);
        int i = 1;
        
        int choice;
        while(true)
        {
            choice = ee.choose_aacharacter("choose your target" , enemies);
            if(enemies[choice]->get_status())
            {
                target = enemies[choice];
                break;
            }
            else
            {
                cout << "this character is dead... please choose another character" << endl;
                ee.p("this character is dead");
            }
        }
    }
}
void game::save(string s , game enemy)
{
    ofstream file(s + ".txt");
        file << get_name_player() << endl << get_age() << endl;
        file << enemy.get_name_player() <<endl << enemy.get_age() << endl;
        if(hero.get_name() == "Dracula")
        {
            file << 1 << endl;
        }
        if(hero.get_name() == "Sherlock Holmes")
        {
            file << 2 << endl;
        }
        if(hero.get_name() == "Invisible Man")
        {
            file << 3 << endl;
        }
        file << hero.get_hp() << endl << hero.get_location()->get_id() << endl;
        if(hero.get_name() == "Dracula" || hero.get_name() == "Sherlock Holmes")
        {
            for(auto s:sidekicks)
            {
                file << s.get_location()->get_id() << endl ;
            }
            
            for(auto s:sidekicks)
            {
                file << s.get_status() << endl ;
            }
            
            for(auto s:sidekicks)
            {
                file << s.get_hp() << endl ;
            }
            
        }
        else
        {
            for(auto s:fogs)
            {
                file << s->get_id() << endl ;
            }
    
        }
        file << deck.size() << endl;
        for(auto p:deck)
        {
            file << p.get_name() << endl ;
        }
        file << hand.size() << endl;
        for(auto j:hand)
        {
            file << j.get_name() << endl ;
        }

        if(enemy.hero.get_name() == "Dracula")
        {
            file << 1 << endl;
        }
        if(enemy.hero.get_name() == "Sherlock Holmes")
        {
            file << 2 << endl;
        }
        if(enemy.hero.get_name() == "Invisible Man")
        {
            file << 3 << endl;
        }
        file << enemy.hero.get_hp() << endl << enemy.hero.get_location()->get_id() << endl;
        if(enemy.hero.get_name() == "Dracula" || enemy.hero.get_name() == "Sherlock Holmes")
        {
            for(auto s:enemy.sidekicks)
            {
                file << s.get_location()->get_id() << endl ;
            }
            
            for(auto s:enemy.sidekicks)
            {
                file << s.get_status() << endl ;
            }
    
            for(auto s:enemy.sidekicks)
            {
                file << s.get_hp() << endl ;
            }
            
        }
        else
        {
            for(auto s:enemy.fogs)
            {
                file << s->get_id() << endl ;
            }
            
        }
        file << enemy.deck.size() << endl;
        for(auto p:enemy.deck)
        {
            file << p.get_name() << endl ;
        }
        file << enemy.hand.size() << endl;
        for(auto j:enemy.hand)
        {
            file << j.get_name() << endl ;
        }
    file.close();
}
character game::get_hero()
{
    return hero;
}
int game::get_nhand()
{
    return hand.size();
}
int game::get_ndeck()
{
    return deck.size();
}
void game::load_game(string a , map& g , int l)
{
    string epname;
    string eage;
    string pname;
    string age;
    int heroname;
    int health;
    int loc_id;
    int sid;
    int sid1;
    int sid2;
    bool statuss;
    bool statuss1;
    bool statuss2;
    int shp;
    int shp1;
    int shp2;
    int decksize;
    int handsize;
    int fid;
    int fid1;
    int fid2;
    string d;
    ifstream file(a);
    if(!file)
    {
        cout << "file not found" << endl;
    }
    file >> pname >> age >>epname >> eage ;
    for(int i = 1 ;i <= l ;i++)
    {
       
        
        
        file >> heroname >> health >> loc_id;
        if(heroname == 1)
        {
            file >> sid >> sid1 >> sid2 >> statuss >> statuss1 >> statuss2 >> shp >> shp1 >> shp2 ;
            if(l == i)
            {
                hero = character("Dracula" , health , 2 , "melee");
                sidekicks.push_back(character("sister 1", shp , 2 , "melee"));
                sidekicks.push_back(character("sister 2", shp1 , 2 , "melee"));
                sidekicks.push_back(character("sister 3", shp2 , 2 , "melee"));
                hero.set_location(g.get_space(loc_id));
                g.set_location("Dracula" , loc_id);
                sidekicks[0].set_location(g.get_space(sid));
                g.set_location("sister 1" , sid);
                sidekicks[1].set_location(g.get_space(sid1));
                g.set_location("sister 2" , sid1);
                sidekicks[2].set_location(g.get_space(sid2));
                g.set_location("sister 3" , sid2);
                hero.set_status();
                sidekicks[0].set_status();
                sidekicks[1].set_status();
                sidekicks[2].set_status();
            }
            
        }
        if(heroname == 2)
        {
            file >> sid >> statuss >> shp;
            if(l == i)
            {
                hero = character("Sherlock Holmes", health , 2 , "melee");
                sidekicks.push_back(character("Dr.Watson", shp , 2, "ranged"));
                hero.set_location(g.get_space(loc_id));
                g.set_location("Sherlock Holmes" , loc_id);
                sidekicks[0].set_location(g.get_space(sid));
                g.set_location("Dr.Watson" , sid);
                hero.set_status();
                sidekicks[0].set_status();
            }
        }
        if(heroname == 3)
        {
            file >> fid >> fid1 >> fid2;
            if(l == i)
            {
                hero =character("Invisible Man", health , 2 , "melee");
                hero.set_location(g.get_space(loc_id));
                g.set_location("Invisible Man" , loc_id);
                fogs.push_back(g.get_space(fid));
                g.set_locationf("fog" , fid);
                fogs.push_back(g.get_space(fid1));
                g.set_locationf("fog" , fid1);
                fogs.push_back(g.get_space(fid2));
                g.set_locationf("fog" , fid2);
                hero.set_status();
            }
        }
        file >> decksize;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        for(int ii = 0 ; ii < decksize ; ii++)
        {
            getline(file , d);
            if(i == l)
            {
                if(d == "feeding frenzy")
                    deck.push_back(card("feeding frenzy" ,{cardtype::attack} , {cardowner::hero} , {timing::duringccombat} , 2 , 3 , "feeding-frenzy.png"));
                if(d == "mistform")
                    deck.push_back(card("mistform" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2 , "mistform.png"));
                if(d == "ambush") 
                    deck.push_back(card("ambush" ,{cardtype::attack} , {cardowner::any} , {timing::duringccombat} , 2 , 3 , "ambush.png"));
                if(d == "baptism of blood")
                    deck.push_back(card("baptism of blood" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2 , "baptism-of-blood.png"));
                if(d == "beastform")
                    deck.push_back(card("beastform" ,{cardtype::attack} , {cardowner::hero} , {timing::duringccombat} , 6 , 4 , "beastform.png"));
                if(d == "dash")
                    deck.push_back(card("dash" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 1 , "dash.png"));
                if(d == "exploit")
                    deck.push_back(card("exploit" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 4 , 1 , "exploit.png"));
                if(d == "look into my eyes")
                    deck.push_back(card("look into my eyes" ,{cardtype::defense} , {cardowner::hero} , {timing::duringccombat} , 1 , 2 , "look-into-my-eyes.png"));
                if(d == "pray upon")
                    deck.push_back(card("pray upon" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 4 , "prey-upon.png"));
                if( d == "ravening seduction")
                    deck.push_back(card("ravening seduction" ,{cardtype::scheme} , {cardowner::sidekick} , {timing::none} , 0 , 2 , "ravening-seduction.png"));
                if(d == "thirst for sustenance")
                    deck.push_back(card("thirst for sustenance" ,{cardtype::attack} , {cardowner::sidekick} , {timing::aftercombat} , 3 , 3 , "thirst-for-sustenance.png"));
                if(d == "feint")
                    deck.push_back(card("feint" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 2 , "feint (1).png"));
                if(d == "administer aid")
                    deck.push_back(card("administer aid" ,{cardtype::scheme} , {cardowner::sidekick} , {timing::none} , 0 , 2 , "administer-aid.png"));
                if(d == "counterpunch")
                    deck.push_back(card("counterpunch" ,{cardtype::versatile} , {cardowner::hero} , {timing::aftercombat} , 3 , 1 , "counterpunch.png"));
                if(d == "deduce strategy")
                    deck.push_back(card("deduce strategy" ,{cardtype::versatile} , {cardowner::hero} , {timing::duringccombat} , 3 , 1 , "deduce-strategy.png"));
                if(d == "education never ends")
                    deck.push_back(card("education never ends" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 1 , "education-never-ends.png"));
                if(d == "eliminate the impossible")
                    deck.push_back(card("eliminate the impossible" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2 , "eliminate-the-impossible.png"));
                if(d == "feint_")
                    deck.push_back(card("feint_" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 1 , "feint (2).png"));
                if(d == "fixed point in a changing age")
                    deck.push_back(card("fixed point in a changing age" ,{cardtype::versatile} , {cardowner::sidekick} , {timing::aftercombat} , 3 , 1 , "fixed-point-in-a-changing-age.png"));
                if(d == "master of disguise")
                    deck.push_back(card("master of disguise" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2 , "master-of-disguise.png"));
                if(d == "the game is afoot")
                    deck.push_back(card("the game is afoot" ,{cardtype::attack} , {cardowner::hero} , {timing::aftercombat} , 5 , 2 ,"the-game-is-afoot.png"));
                if(d == "service revolver")
                    deck.push_back(card("service revolver" ,{cardtype::attack} , {cardowner::sidekick} , {timing::none} , 5 , 3 , "service-revolver.png"));
                if(d == "study methodes")
                    deck.push_back(card("study methodes" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 2 , "study-methods.png"));
                if(d == "coded notes" )
                    deck.push_back(card("coded notes" ,{cardtype::defense} , {cardowner::hero} , {timing::aftercombat} , 3 , 2 , "coded-notes.png"));
                if(d == "covert preparation")
                    deck.push_back(card("covert preparation" ,{cardtype::versatile} , {cardowner::hero} , {timing::aftercombat} , 2 , 1 , "covert-preparation.png"));
                if(d == "dreaming of revenge")
                    deck.push_back(card("dreaming of revenge" ,{cardtype::versatile} , {cardowner::hero} , {timing::aftercombat} , 3 , 1 , "dreaming-of-revenge.png"));
                if(d == "emerge from mist")
                    deck.push_back(card("emerge from mist" ,{cardtype::attack} , {cardowner::hero} , {timing::duringccombat} , 3 , 2 , "emerge-from-mist.png"));
                if(d == "impossible yo see")
                    deck.push_back(card("impossible yo see" ,{cardtype::versatile} , {cardowner::hero} , {timing::beforcombat} , 2 , 2 , "impossible-to-see.png"));
                if( d == "into thin air")
                    deck.push_back(card("into thin air" ,{cardtype::defense} , {cardowner::hero} , {timing::aftercombat} , 4 , 1 , "into-thin-air.png"));
                if(d == "lurking")
                    deck.push_back(card("lurking" ,{cardtype::defense} , {cardowner::hero} , {timing::aftercombat} , 2 , 2 , "lurking.png"));
                if(d == "ring of terror")
                    deck.push_back(card("ring of terror" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 1 , "reign-of-terror.png"));
                if(d == "rolling fog")
                    deck.push_back(card("rolling fog" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 1 , "rolling-fog.png"));
                if(d == "slip away")
                    deck.push_back(card("slip away" ,{cardtype::attack} , {cardowner::hero} , {timing::aftercombat} , 3 , 2 , "slip-away.png"));
                if(d == "step lightly")
                    deck.push_back(card("step lightly" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 1 , "step-lightly.png"));
                if(d == "vanish")
                    deck.push_back(card("vanish" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 3 , "vanish.png"));
            }
        }

        file >> handsize;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        for(int ii = 0 ; ii < handsize ; ii++)
        {
            getline(file , d);
            if(i == l)
            {
                 if(d == "feeding frenzy")
                    hand.push_back(card("feeding frenzy" ,{cardtype::attack} , {cardowner::hero} , {timing::duringccombat} , 2 , 3 , "feeding-frenzy.png"));
                if(d == "mistform")
                    hand.push_back(card("mistform" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2 , "mistform.png"));
                if(d == "ambush") 
                    hand.push_back(card("ambush" ,{cardtype::attack} , {cardowner::any} , {timing::duringccombat} , 2 , 3 , "ambush.png"));
                if(d == "baptism of blood")
                    hand.push_back(card("baptism of blood" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2 , "baptism-of-blood.png"));
                if(d == "beastform")
                    hand.push_back(card("beastform" ,{cardtype::attack} , {cardowner::hero} , {timing::duringccombat} , 6 , 4 , "beastform.png"));
                if(d == "dash")
                    hand.push_back(card("dash" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 1 , "dash.png"));
                if(d == "exploit")
                    hand.push_back(card("exploit" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 4 , 1 , "exploit.png"));
                if(d == "look into my eyes")
                    hand.push_back(card("look into my eyes" ,{cardtype::defense} , {cardowner::hero} , {timing::duringccombat} , 1 , 2 , "look-into-my-eyes.png"));
                if(d == "pray upon")
                    hand.push_back(card("pray upon" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 4 , "prey-upon.png"));
                if( d == "ravening seduction")
                    hand.push_back(card("ravening seduction" ,{cardtype::scheme} , {cardowner::sidekick} , {timing::none} , 0 , 2 , "ravening-seduction.png"));
                if(d == "thirst for sustenance")
                    hand.push_back(card("thirst for sustenance" ,{cardtype::attack} , {cardowner::sidekick} , {timing::aftercombat} , 3 , 3 , "thirst-for-sustenance.png"));
                if(d == "feint")
                    hand.push_back(card("feint" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 2 , "feint (1).png"));
                if(d == "administer aid")
                    hand.push_back(card("administer aid" ,{cardtype::scheme} , {cardowner::sidekick} , {timing::none} , 0 , 2 , "administer-aid.png"));
                if(d == "counterpunch")
                    hand.push_back(card("counterpunch" ,{cardtype::versatile} , {cardowner::hero} , {timing::aftercombat} , 3 , 1 , "counterpunch.png"));
                if(d == "deduce strategy")
                    hand.push_back(card("deduce strategy" ,{cardtype::versatile} , {cardowner::hero} , {timing::duringccombat} , 3 , 1 , "deduce-strategy.png"));
                if(d == "education never ends")
                    hand.push_back(card("education never ends" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 1 , "education-never-ends.png"));
                if(d == "eliminate the impossible")
                    hand.push_back(card("eliminate the impossible" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2 , "eliminate-the-impossible.png"));
                if(d == "feint_")
                    hand.push_back(card("feint_" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 1 , "feint (2).png"));
                if(d == "fixed point in a changing age")
                    hand.push_back(card("fixed point in a changing age" ,{cardtype::versatile} , {cardowner::sidekick} , {timing::aftercombat} , 3 , 1 , "fixed-point-in-a-changing-age.png"));
                if(d == "master of disguise")
                    hand.push_back(card("master of disguise" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2 , "master-of-disguise.png"));
                if(d == "the game is afoot")
                    hand.push_back(card("the game is afoot" ,{cardtype::attack} , {cardowner::hero} , {timing::aftercombat} , 5 , 2 ,"the-game-is-afoot.png"));
                if(d == "service revolver")
                    hand.push_back(card("service revolver" ,{cardtype::attack} , {cardowner::sidekick} , {timing::none} , 5 , 3 , "service-revolver.png"));
                if(d == "study methodes")
                    hand.push_back(card("study methodes" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 2 , "study-methods.png"));
                if(d == "coded notes" )
                    hand.push_back(card("coded notes" ,{cardtype::defense} , {cardowner::hero} , {timing::aftercombat} , 3 , 2 , "coded-notes.png"));
                if(d == "covert preparation")
                    hand.push_back(card("covert preparation" ,{cardtype::versatile} , {cardowner::hero} , {timing::aftercombat} , 2 , 1 , "covert-preparation.png"));
                if(d == "dreaming of revenge")
                    hand.push_back(card("dreaming of revenge" ,{cardtype::versatile} , {cardowner::hero} , {timing::aftercombat} , 3 , 1 , "dreaming-of-revenge.png"));
                if(d == "emerge from mist")
                    hand.push_back(card("emerge from mist" ,{cardtype::attack} , {cardowner::hero} , {timing::duringccombat} , 3 , 2 , "emerge-from-mist.png"));
                if(d == "impossible yo see")
                    hand.push_back(card("impossible yo see" ,{cardtype::versatile} , {cardowner::hero} , {timing::beforcombat} , 2 , 2 , "impossible-to-see.png"));
                if( d == "into thin air")
                    hand.push_back(card("into thin air" ,{cardtype::defense} , {cardowner::hero} , {timing::aftercombat} , 4 , 1 , "into-thin-air.png"));
                if(d == "lurking")
                    hand.push_back(card("lurking" ,{cardtype::defense} , {cardowner::hero} , {timing::aftercombat} , 2 , 2 , "lurking.png"));
                if(d == "ring of terror")
                    hand.push_back(card("ring of terror" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 1 , "reign-of-terror.png"));
                if(d == "rolling fog")
                    hand.push_back(card("rolling fog" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 1 , "rolling-fog.png"));
                if(d == "slip away")
                    hand.push_back(card("slip away" ,{cardtype::attack} , {cardowner::hero} , {timing::aftercombat} , 3 , 2 , "slip-away.png"));
                if(d == "step lightly")
                    hand.push_back(card("step lightly" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 1 , "step-lightly.png"));
                if(d == "vanish")
                    hand.push_back(card("vanish" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 3 , "vanish.png"));
            }
        }
    }
    file.close();
}
