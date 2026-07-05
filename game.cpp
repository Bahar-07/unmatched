#include "game.h"
#include <iostream>
using namespace std;

game::game()
{
    string player;
    cin >> player;
    name = player;
}

void game::age(game &enemy , map& g)
{
    cout << "Who is younger?    1 . " << name << "    2 . " << enemy.name << endl;
    int a;
    cin >> a;
    if(a == 1)
    {
        yoro = "younger";
        enemy.yoro = "older";
        cout  << name << " please choose one of these characters ... (1.Dracula    2.Sherlock Holmes)" << endl;
    }
    if(a == 2)
    {
        yoro = "older";
        enemy.yoro = "younger";
        cout  << enemy.name << " please choose one of these characters ... (1.Dracula    2.Sherlock Holmes)" << endl;
    }
    if(a > 2 || a < 1)
    {
        throw invalid_argument("please enter 1 or 2");
    }
    choose_character(enemy , g);
}
void game::choose_character(game& enemy , map& g)
{
    int a;
    cin >> a;
    if(a ==1)
    {
        if(yoro == "younger")
        {
            hero = character("Dracula" , 13);

            sidekicks.push_back(character("Sister 1", 1));
            sidekicks.push_back(character("Sister 2", 1));
            sidekicks.push_back(character("Sister 3", 1));
            enemy.hero =character("Sherlock Holmes", 16);
            enemy.sidekicks.push_back(character("Dr. Watson", 7));

        }
        else
        {
            enemy.hero = character("Dracula" , 13);
            enemy.sidekicks.push_back(character("Sister 1", 1));
            enemy.sidekicks.push_back(character("Sister 2", 1));
            enemy.sidekicks.push_back(character("Sister 3", 1));
            hero =character("Sherlock Holmes", 16);
            sidekicks.push_back(character("Dr. Watson", 7));
        }
    }
    else if(a == 2)
    {
        if(yoro == "younger")
        {
            enemy.hero = character("Dracula" , 13);
            enemy.sidekicks.push_back(character("Sister 1", 1));
            enemy.sidekicks.push_back(character("Sister 2", 1));
            enemy.sidekicks.push_back(character("Sister 3", 1));
            hero =character("Sherlock Holmes", 16);
            sidekicks.push_back(character("Dr. Watson", 7));
        }
        else
        {
            hero = character("Dracula" , 13);

            sidekicks.push_back(character("Sister 1", 1));
            sidekicks.push_back(character("Sister 2", 1));
            sidekicks.push_back(character("Sister 3", 1));
            enemy .hero =character("Sherlock Holmes", 16);
            enemy.sidekicks.push_back(character("Dr. Watson", 7));
        }
    }
    else
    {
        cout << "Erorr: please choose one of these characters ... (1.Dracula    2.Sherlock Holmes)";
        choose_character(enemy , g);
    }
    choose_location(enemy , g);

}
void game::choose_location(game& enemy , map& g)
{
    
    int a;
    int r;
    cout << "please choose one of these spaces ... (5 , 25)" << endl;
    
    g.get_space(5)->show_space();
    g.get_space(25)->show_space();    
    cin >> a;
    if(a ==5)
    {
        if(yoro == "younger")
        {
            if(hero.get_name() == "Dracula")
            {
                hero.set_location(g.get_space(5));
                enemy.hero.set_location(g.get_space(25));
                g.set_location("Dracula" , a);
                g.set_location("Sherlock Holmes" , 25);
                cout << name << "please choose 3 spaces for your sisters (1 , 2 , 3 , 4 , 7)" <<endl;
                g.get_space(1)->show_space();
                g.get_space(2)->show_space();
                g.get_space(3)->show_space();
                g.get_space(4)->show_space();
                g.get_space(7)->show_space();
                cin >> r;
                sidekicks[0].set_location(g.get_space(r));
                g.set_location("sister 1" , r);
                cin >> r;
                sidekicks[1].set_location(g.get_space(r));
                g.set_location("sister 2" , r);
                cin >> r;
                sidekicks[2].set_location(g.get_space(r));
                g.set_location("sister 3" , r);
                
                cout << enemy.name << "please choose a spaces for Dr.Watson (14 , 23 , 24 , 26)" <<endl;
                g.get_space(14)->show_space();
                g.get_space(23)->show_space();
                g.get_space(24)->show_space();
                g.get_space(26)->show_space();
                cin >> r;
                enemy.sidekicks[0].set_location(g.get_space(r));
                g.set_location("Dr.Watson" , r);

            }
            else
            {
                hero.set_location(g.get_space(5));
                enemy.hero.set_location(g.get_space(25));
                g.set_location("Sherlock Holmes" , a);
                g.set_location("Dracula" , 25);
                cout << name << " please choose a spaces for Dr.Watson (1 , 2 , 3 , 4 , 7)" <<endl;
                g.get_space(1)->show_space();
                g.get_space(2)->show_space();
                g.get_space(3)->show_space();
                g.get_space(4)->show_space();
                g.get_space(7)->show_space();
                
                cin >> r;
                sidekicks[0].set_location(g.get_space(r));
                g.set_location("Dr.Watson" , r);
                cout << enemy.name << " please choose 3 spaces for your sisters (14 , 23 , 24 , 26)" << endl;
                g.get_space(14)->show_space();
                g.get_space(23)->show_space();
                g.get_space(24)->show_space();
                g.get_space(26)->show_space();
                cin >> r;
                enemy.sidekicks[0].set_location(g.get_space(r));
                g.set_location("sister 1" , r);
                cin >> r;
                enemy.sidekicks[1].set_location(g.get_space(r));
                g.set_location("sister 2" , r);
                cin >> r;
                enemy.sidekicks[2].set_location(g.get_space(r));
                g.set_location("sister 3" , r);
                
            }
        }
        else
        {
            if(enemy.hero.get_name() == "Dracula")
            {
                hero.set_location(g.get_space(25));
                enemy.hero.set_location(g.get_space(5));
                g.set_location("Dracula" , a);
                g.set_location("Sherlock Holmes" , 25);
                cout << enemy.name << " please choose 3 spaces for your sisters (1 , 2 , 3 , 4 , 7)" <<endl;
                g.get_space(1)->show_space();
                g.get_space(2)->show_space();
                g.get_space(3)->show_space();
                g.get_space(4)->show_space();
                g.get_space(7)->show_space();
                cin >> r;
                enemy.sidekicks[0].set_location(g.get_space(r));
                g.set_location("sister 1" , r);
                cin >> r;
                enemy.sidekicks[1].set_location(g.get_space(r));
                g.set_location("sister 2" , r);
                cin >> r;
                enemy.sidekicks[2].set_location(g.get_space(r));
                g.set_location("sister 3" , r);
                cout << name << " please choose a spaces for Dr.Watson (14 , 23 , 24 , 26)" << endl;
                g.get_space(14)->show_space();
                g.get_space(23)->show_space();
                g.get_space(24)->show_space();
                g.get_space(26)->show_space();
                cin >> r;
                sidekicks[0].set_location(g.get_space(r));
                g.set_location("Dr.Watson" , r);

            }
            else
            {
                hero.set_location(g.get_space(25));
                enemy.hero.set_location(g.get_space(5));
                g.set_location("Sherlock Holmes" , a);
                g.set_location("Dracula" , 25);
                cout << enemy.name << " please choose a spaces for Dr.Watson (1 , 2 , 3 , 4 , 7)" << endl;
                g.get_space(1)->show_space();
                g.get_space(2)->show_space();
                g.get_space(3)->show_space();
                g.get_space(4)->show_space();
                g.get_space(7)->show_space();
                
                cin >> r;
                enemy.sidekicks[0].set_location(g.get_space(r));
                g.set_location("Dr.Watson" , r);
                cout << name << " please choose 3 spaces for your sisters (14 , 23 , 24 , 26)" <<endl;
                g.get_space(14)->show_space();
                g.get_space(23)->show_space();
                g.get_space(24)->show_space();
                g.get_space(26)->show_space();
                cin >> r;
                sidekicks[0].set_location(g.get_space(r));
                g.set_location("sister 1" , r);
                cin >> r;
                sidekicks[1].set_location(g.get_space(r));
                g.set_location("sister 2" , r);
                cin >> r;
                sidekicks[2].set_location(g.get_space(r));
                g.set_location("sister 3" , r);
            }
        }
    }
    else if(a == 25)
    {
        if(yoro == "younger")
        {
            if(hero.get_name() == "Dracula")
            {
                hero.set_location(g.get_space(25));
                enemy.hero.set_location(g.get_space(5));
                g.set_location("Dracula" , a);
                g.set_location("Sherlock Holmes" , 5);
                cout << name << "please choose 3 spaces for your sisters (14 , 23 , 24 , 26)" << endl;
                g.get_space(14)->show_space();
                g.get_space(23)->show_space();
                g.get_space(24)->show_space();
                g.get_space(26)->show_space();
                cin >> r;
                sidekicks[0].set_location(g.get_space(r));
                g.set_location("sister 1" , r);
                cin >> r;
                sidekicks[1].set_location(g.get_space(r));
                g.set_location("sister 2" , r);
                cin >> r;
                sidekicks[2].set_location(g.get_space(r));
                g.set_location("sister 3" , r);
                 cout << enemy.name << " please choose a spaces for Dr.Watson (1 , 2 , 3 , 4 , 7)" << endl;
                g.get_space(1)->show_space();
                g.get_space(2)->show_space();
                g.get_space(3)->show_space();
                g.get_space(4)->show_space();
                g.get_space(7)->show_space();
                cin >> r;
                enemy.sidekicks[0].set_location(g.get_space(r));
                g.set_location("Dr.Watson" , r);
            }
            else
            {
                hero.set_location(g.get_space(25));
                enemy.hero.set_location(g.get_space(5));
                g.set_location("Sherlock Holmes" , a);
                g.set_location("Dracula" , 5);
                 cout << name << " please choose a spaces for Dr.Watson (14 , 23 , 24 , 26)" << endl;
                g.get_space(14)->show_space();
                g.get_space(23)->show_space();
                g.get_space(24)->show_space();
                g.get_space(26)->show_space();
                cin >> r;
                sidekicks[0].set_location(g.get_space(r));
                g.set_location("Dr.Watson" , r);
                cout << enemy.name << " please choose 3 spaces for your sisters (1 , 2 , 3 , 4 , 7)" << endl;
                g.get_space(1)->show_space();
                g.get_space(2)->show_space();
                g.get_space(3)->show_space();
                g.get_space(4)->show_space();
                g.get_space(7)->show_space();
                
                cin >> r;
                enemy.sidekicks[0].set_location(g.get_space(r));
                g.set_location("sister 1" , r);
                cin >> r;
                enemy.sidekicks[1].set_location(g.get_space(r));
                g.set_location("sister 2" , r);
                cin >> r;
                enemy.sidekicks[2].set_location(g.get_space(r));
                g.set_location("sister 3" , r);
            }
        }
        else
        {
           if(enemy.hero.get_name() == "Dracula")
            {
                hero.set_location(g.get_space(5));
                enemy.hero.set_location(g.get_space(25));
                g.set_location("Dracula" , a);
                g.set_location("Sherlock Holmes" , 5);
                cout << enemy.name << "please choose 3 spaces for your sisters (14 , 23 , 24 , 26)" << endl;
                g.get_space(14)->show_space();
                g.get_space(23)->show_space();
                g.get_space(24)->show_space();
                g.get_space(26)->show_space();
                cin >> r;
                enemy.sidekicks[0].set_location(g.get_space(r));
                g.set_location("sister 1" , r);
                cin >> r;
                enemy.sidekicks[1].set_location(g.get_space(r));
                g.set_location("sister 2" , r);
                cin >> r;
                enemy.sidekicks[2].set_location(g.get_space(r));
                g.set_location("sister 3" , r);
                 cout << name << " please choose a spaces for Dr.Watson (1 , 2 , 3 , 4 , 7)" << endl;
                g.get_space(1)->show_space();
                g.get_space(2)->show_space();
                g.get_space(3)->show_space();
                g.get_space(4)->show_space();
                g.get_space(7)->show_space();
                cin >> r;
                sidekicks[0].set_location(g.get_space(r));
                g.set_location("Dr.Watson" , r);

            }
            else
            {
                hero.set_location(g.get_space(5));
                enemy.hero.set_location(g.get_space(25));
                g.set_location("Sherlock Holmes" , a);
                g.set_location("Dracula" , 5);
                 cout << enemy.name << " please choose a spaces for Dr.Watson (14 , 23 , 24 , 26)" << endl;
                g.get_space(14)->show_space();
                g.get_space(23)->show_space();
                g.get_space(24)->show_space();
                g.get_space(26)->show_space();
                cin >> r;
                enemy.sidekicks[0].set_location(g.get_space(r));
                g.set_location("Dr.Watson" , r);
                cout << name << " please choose 3 spaces for your sisters (1 , 2 , 3 , 4 , 7)" << endl;
                g.get_space(1)->show_space();
                g.get_space(2)->show_space();
                g.get_space(3)->show_space();
                g.get_space(4)->show_space();
                g.get_space(7)->show_space();
                
                cin >> r;
                sidekicks[0].set_location(g.get_space(r));
                g.set_location("sister 1" , r);
                cin >> r;
                sidekicks[1].set_location(g.get_space(r));
                g.set_location("sister 2" , r);
                cin >> r;
                sidekicks[2].set_location(g.get_space(r));
                g.set_location("sister 3" , r);
                
            }
        }
    }
    else if(a != 5 && a != 25)
    {
        cout << "Erorr:";
        choose_location(enemy , g);
    }
    g.show_map();
}
string game::get_age()
{
    return yoro;
}
std::string game::get_name_player()
{
    return name;
}
bool game::alive()
{
    return alivee;
}
void game::creat_deck()
{
    if(hero.get_name()== "Dracula")
    {
        deck.push_back(card("feeding frenzy" ,{cardtype::attack} , {cardowner::hero} , {timing::duringccombat} , 2 , 3));
        deck.push_back(card("feeding frenzy" ,{cardtype::attack} , {cardowner::hero} , {timing::duringccombat} , 2 , 3));
        deck.push_back(card("mistform" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2));
        deck.push_back(card("mistform" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2));
        deck.push_back(card("ambush" ,{cardtype::attack} , {cardowner::any} , {timing::duringccombat} , 2 , 3));
        deck.push_back(card("ambush" ,{cardtype::attack} , {cardowner::any} , {timing::duringccombat} , 2 , 3));
        deck.push_back(card("baptism of blood" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2));
        deck.push_back(card("baptism of blood" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2));
        deck.push_back(card("beastform" ,{cardtype::attack} , {cardowner::hero} , {timing::duringccombat} , 6 , 4));
        deck.push_back(card("beastform" ,{cardtype::attack} , {cardowner::hero} , {timing::duringccombat} , 6 , 4));
        deck.push_back(card("dash" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 1));
        deck.push_back(card("dash" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 1));
        deck.push_back(card("dash" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 1));
        deck.push_back(card("exploit" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 4 , 1));
        deck.push_back(card("exploit" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 4 , 1));
        deck.push_back(card("exploit" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 4 , 1));
        deck.push_back(card("look into my eyes" ,{cardtype::defense} , {cardowner::hero} , {timing::duringccombat} , 1 , 2));
        deck.push_back(card("look into my eyes" ,{cardtype::defense} , {cardowner::hero} , {timing::duringccombat} , 1 , 2));
        deck.push_back(card("look into my eyes" ,{cardtype::defense} , {cardowner::hero} , {timing::duringccombat} , 1 , 2));
        deck.push_back(card("pray upon" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 4));
        deck.push_back(card("pray upon" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 4));
        deck.push_back(card("ravening seduction" ,{cardtype::scheme} , {cardowner::sidekick} , {timing::none} , 0 , 2));
        deck.push_back(card("ravening seduction" ,{cardtype::scheme} , {cardowner::sidekick} , {timing::none} , 0 , 2));
        deck.push_back(card("ravening seduction" ,{cardtype::scheme} , {cardowner::sidekick} , {timing::none} , 0 , 2));
        deck.push_back(card("thirst for sustenance" ,{cardtype::attack} , {cardowner::sidekick} , {timing::aftercombat} , 3 , 3));
        deck.push_back(card("thirst for sustenance" ,{cardtype::attack} , {cardowner::sidekick} , {timing::aftercombat} , 3 , 3));
        deck.push_back(card("thirst for sustenance" ,{cardtype::attack} , {cardowner::sidekick} , {timing::aftercombat} , 3 , 3));
        deck.push_back(card("feint" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 2));
        deck.push_back(card("feint" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 2));
        deck.push_back(card("feint" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 2));


    }
    if(hero.get_name()== "Sherlock Holmes")
    {
        deck.push_back(card("administer aid" ,{cardtype::scheme} , {cardowner::sidekick} , {timing::none} , 0 , 2));
        deck.push_back(card("administer aid" ,{cardtype::scheme} , {cardowner::sidekick} , {timing::none} , 0 , 2));
        deck.push_back(card("counterpunch" ,{cardtype::versatile} , {cardowner::hero} , {timing::aftercombat} , 3 , 1));
        deck.push_back(card("counterpunch" ,{cardtype::versatile} , {cardowner::hero} , {timing::aftercombat} , 3 , 1));
        deck.push_back(card("counterpunch" ,{cardtype::versatile} , {cardowner::hero} , {timing::aftercombat} , 3 , 1));
        deck.push_back(card("dwduce strategy" ,{cardtype::versatile} , {cardowner::hero} , {timing::duringccombat} , 3 , 1));
        deck.push_back(card("dwduce strategy" ,{cardtype::versatile} , {cardowner::hero} , {timing::duringccombat} , 3 , 1));
        deck.push_back(card("dwduce strategy" ,{cardtype::versatile} , {cardowner::hero} , {timing::duringccombat} , 3 , 1));
        deck.push_back(card("education never ends" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 1));
        deck.push_back(card("education never ends" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 1));
        deck.push_back(card("eliminate the impossible" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2));
        deck.push_back(card("eliminate the impossible" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2));
        deck.push_back(card("feint" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 1));
        deck.push_back(card("feint" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 1));
        deck.push_back(card("feint" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 1));
        deck.push_back(card("fixed point in a changing age" ,{cardtype::versatile} , {cardowner::sidekick} , {timing::aftercombat} , 3 , 1));
        deck.push_back(card("fixed point in a changing age" ,{cardtype::versatile} , {cardowner::sidekick} , {timing::aftercombat} , 3 , 1));
        deck.push_back(card("mater of disguise" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2));
        deck.push_back(card("mater of disguise" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2));
        deck.push_back(card("the game is afoot" ,{cardtype::attack} , {cardowner::hero} , {timing::aftercombat} , 5 , 2));
        deck.push_back(card("the game is afoot" ,{cardtype::attack} , {cardowner::hero} , {timing::aftercombat} , 5 , 2));
        deck.push_back(card("service revolver" ,{cardtype::attack} , {cardowner::sidekick} , {timing::none} , 5 , 3));
        deck.push_back(card("service revolver" ,{cardtype::attack} , {cardowner::sidekick} , {timing::none} , 5 , 3));
        deck.push_back(card("study methodes" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 2));
        deck.push_back(card("study methodes" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 2));


    }
}
void game::start_game(game & enemy , map & g)
{
    int z;
    cout << name << " please choose an action" << endl << "1. Manueuver     2. Scheme     3. Attack" << endl;
    cin >> z;
    if(z ==1)
    {
        g.move(hero.get_name(), hero.get_location()->get_id(), hero);
    }
    else if(z == 2)
    {

    }
    else if(z == 3)
    {

    }
    else
    {
        cout << "Erorr:(enter 1 , 2 , 3 , 4)     ";
        start_game(enemy, g);
    }
    
}