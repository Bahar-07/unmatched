#include "game.h"
#include <iostream>

using namespace std;

game::game()
{
    string player;
    cin >> player;
    name = player;
    alivee = true;
    action = 2;
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
            hero = character("Dracula" , 13 , 2);

            sidekicks.push_back(character("Sister 1", 1 , 2));
            sidekicks.push_back(character("Sister 2", 1 , 2));
            sidekicks.push_back(character("Sister 3", 1 , 2));
            enemy.hero =character("Sherlock Holmes", 16 , 2);
            enemy.sidekicks.push_back(character("Dr. Watson", 8 , 2));

        }
        else
        {
            enemy.hero = character("Dracula" , 13  , 2);
            enemy.sidekicks.push_back(character("Sister 1", 1 , 2));
            enemy.sidekicks.push_back(character("Sister 2", 1 , 2));
            enemy.sidekicks.push_back(character("Sister 3", 1 , 2));
            hero =character("Sherlock Holmes", 16 , 2);
            sidekicks.push_back(character("Dr. Watson", 8 , 2));
        }
    }
    else if(a == 2)
    {
        if(yoro == "younger")
        {
            enemy.hero = character("Dracula" , 13 , 2);
            enemy.sidekicks.push_back(character("Sister 1", 1 , 2));
            enemy.sidekicks.push_back(character("Sister 2", 1 , 2));
            enemy.sidekicks.push_back(character("Sister 3", 1 , 2));
            hero =character("Sherlock Holmes", 16 , 2);
            sidekicks.push_back(character("Dr. Watson", 8 , 2));
        }
        else
        {
            hero = character("Dracula" , 13 , 2);
            sidekicks.push_back(character("Sister 1", 1 , 2));
            sidekicks.push_back(character("Sister 2", 1 , 2));
            sidekicks.push_back(character("Sister 3", 1 , 2));
            enemy .hero =character("Sherlock Holmes", 16 , 2);
            enemy.sidekicks.push_back(character("Dr. Watson", 8 , 2));
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
   // g.show_map();
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
        deck.push_back(card("deduce strategy" ,{cardtype::versatile} , {cardowner::hero} , {timing::duringccombat} , 3 , 1));
        deck.push_back(card("deduce strategy" ,{cardtype::versatile} , {cardowner::hero} , {timing::duringccombat} , 3 , 1));
        deck.push_back(card("deduce strategy" ,{cardtype::versatile} , {cardowner::hero} , {timing::duringccombat} , 3 , 1));
        deck.push_back(card("education never ends" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 1));
        deck.push_back(card("education never ends" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 1));
        deck.push_back(card("eliminate the impossible" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2));
        deck.push_back(card("eliminate the impossible" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2));
        deck.push_back(card("feint_" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 1));
        deck.push_back(card("feint_" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 1));
        deck.push_back(card("feint_" ,{cardtype::versatile} , {cardowner::any} , {timing::beforcombat} , 2 , 1));
        deck.push_back(card("fixed point in a changing age" ,{cardtype::versatile} , {cardowner::sidekick} , {timing::aftercombat} , 3 , 1));
        deck.push_back(card("fixed point in a changing age" ,{cardtype::versatile} , {cardowner::sidekick} , {timing::aftercombat} , 3 , 1));
        deck.push_back(card("master of disguise" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2));
        deck.push_back(card("master of disguise" ,{cardtype::scheme} , {cardowner::hero} , {timing::none} , 0 , 2));
        deck.push_back(card("the game is afoot" ,{cardtype::attack} , {cardowner::hero} , {timing::aftercombat} , 5 , 2));
        deck.push_back(card("the game is afoot" ,{cardtype::attack} , {cardowner::hero} , {timing::aftercombat} , 5 , 2));
        deck.push_back(card("service revolver" ,{cardtype::attack} , {cardowner::sidekick} , {timing::none} , 5 , 3));
        deck.push_back(card("service revolver" ,{cardtype::attack} , {cardowner::sidekick} , {timing::none} , 5 , 3));
        deck.push_back(card("study methodes" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 2));
        deck.push_back(card("study methodes" ,{cardtype::versatile} , {cardowner::any} , {timing::aftercombat} , 3 , 2));


    }
}
void game::pick_card(game & enemy)
{
    
    int random;
    if(hero.get_name() == "Dracula")
    {
        random = rand()%30;
        hand.push_back(deck[random]);
        deck.erase(deck.begin() + random);
        random = rand()%29;
        hand.push_back(deck[random]);
        deck.erase(deck.begin() + random);
        random = rand()%28;
        hand.push_back(deck[random]);
        deck.erase(deck.begin() + random);
        random = rand()%27;
        hand.push_back(deck[random]);
        deck.erase(deck.begin() + random);
        random = rand()%26;
        hand.push_back(deck[random]);
        deck.erase(deck.begin() + random);


        random = rand()%25;
        enemy.hand.push_back(enemy.deck[random]);
        enemy.deck.erase(enemy.deck.begin() + random);
        random = rand()%24;
        enemy.hand.push_back(enemy.deck[random]);
        enemy.deck.erase(enemy.deck.begin() + random);
        random = rand()%23;
        enemy.hand.push_back(enemy.deck[random]);
        enemy.deck.erase(enemy.deck.begin() + random);
        random = rand()%22;
        enemy.hand.push_back(enemy.deck[random]);
        enemy.deck.erase(enemy.deck.begin() + random);
        random = rand()%21;
        enemy.hand.push_back(enemy.deck[random]);
        enemy.deck.erase(enemy.deck.begin() + random);
    }
    if(enemy.hero.get_name() == "Dracula")
    {
        
        random = rand()%25;
        hand.push_back(deck[random]);
        deck.erase(deck.begin() + random);
        random = rand()%24;
        hand.push_back(deck[random]);
        deck.erase(deck.begin() + random);
        random = rand()%23;
        hand.push_back(deck[random]);
        deck.erase(deck.begin() + random);
        random = rand()%22;
        hand.push_back(deck[random]);
        deck.erase(deck.begin() + random);
        random = rand()%21;
        hand.push_back(deck[random]);
        deck.erase(deck.begin() + random);


        random = rand()%30;
        enemy.hand.push_back(enemy.deck[random]);
        enemy.deck.erase(enemy.deck.begin() + random);
        random = rand()%29;
        enemy.hand.push_back(enemy.deck[random]);
        enemy.deck.erase(enemy.deck.begin() + random);
        random = rand()%28;
        enemy.hand.push_back(enemy.deck[random]);
        enemy.deck.erase(enemy.deck.begin() + random);
        random = rand()%27;
        enemy.hand.push_back(enemy.deck[random]);
        enemy.deck.erase(enemy.deck.begin() + random);
        random = rand()%26;
        enemy.hand.push_back(enemy.deck[random]);
        enemy.deck.erase(enemy.deck.begin() + random);
    }
    
}
void game::start_game(game & enemy , map & g)
{
    cout << hero.get_name() << " turn" << endl;
    int z;
    while(action > 0)
    {
        b.clear();
            c.clear();
            enemy.b.clear();
            enemy.c.clear();
        cout << name << " please choose an action" << endl << "1. Manueuver     2. Scheme     3. Attack" << endl;
        cin >> z;
        if(z ==1)
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
            cout << "Do you want to move your character? (1. yes     2. no)" << endl;
            int h;
            
            while(true)
            {
                cin >> h;
                if(h == 1)
                {
                    cout << "do you want to discard a card and use the boost?(1. yes  2.no)" << endl;
                    int v;
                    cin >> v;
                    if(v == 2)
                    {
                        if(hero.get_name() == "Dracula")
                        {
                            cout << "choose a caracter to move (1. "  << hero.get_name() << " , 2. " << sidekicks[0].get_name() << " , 3. " << sidekicks[1].get_name() << " , 4. " << sidekicks[2].get_name() << ")" << endl;
                            int yy;
                            
                            while(true)
                            {
                                cin >> yy;
                                if(yy == 1)
                                {
                                    cout << "how many spaces do you want to move?(1 , 2)" << endl;
                                    int tt;
                                    
                                    while(true)
                                    {
                                        cin >> tt;
                                        if(tt == 1 || tt == 2 )
                                        {
                                            while(tt > 0)
                                            {
                                                g.move(hero.get_name(), hero.get_location()->get_id(), hero);
                                                tt--;
                                            }
                                            break;
                                        }
                                        else
                                        {
                                            cout << "please choose(1 , 2)" << endl;
                                        }

                                    }
                                    break;
                                    
                                }
                                if(yy == 2)
                                {
                                    if(sidekicks[0].get_status())
                                    {
                                        cout << "how many spaces do you want to move?(1 , 2)" << endl;
                                        int tt; 
                                        while(true)
                                        {
                                            cin >> tt;
                                            if(tt == 1 || tt == 2 )
                                            {
                                                while(tt > 0)
                                                {
                                                    g.move(sidekicks[0].get_name(), sidekicks[0].get_location()->get_id(), sidekicks[0]);
                                                    tt--;
                                                }
                                                break;
                                            }
                                            else
                                            {
                                                cout << "please choose(1 , 2)" << endl;
                                            }

                                        }
                                        break;
                                    }
                                    else
                                    {
                                        cout << "this caracter is dead... please choose another character" << endl;
                                    }
                                    
                                    
                                }
                                if(yy == 3)
                                {
                                    if(sidekicks[1].get_status())
                                    {
                                        cout << "how many spaces do you want to move?(1 , 2)" << endl;
                                        int tt;
                                        
                                        while(true)
                                        {
                                            cin >> tt;
                                            if(tt == 1 || tt == 2 )
                                            {
                                                while(tt > 0)
                                                {
                                                    g.move(sidekicks[1].get_name(), sidekicks[1].get_location()->get_id(), sidekicks[1]);
                                                    tt--;
                                                }
                                                break;
                                            }
                                            else
                                            {
                                                cout << "please choose(1 , 2)" << endl;
                                            }

                                        }
                                        break;
                                    }
                                    else
                                    {
                                        cout << "this caracter is dead... please choose another character" << endl;
                                    }
                                    
                                }
                                if(yy == 4)
                                {
                                    if(sidekicks[2].get_status())
                                    {
                                        cout << "how many spaces do you want to move?(1 , 2)" << endl;
                                        int tt;
                                        
                                        while(true)
                                        {
                                            cin >> tt;
                                            if(tt == 1 || tt == 2 )
                                            {
                                                while(tt > 0)
                                                {
                                                    g.move(sidekicks[2].get_name(), sidekicks[2].get_location()->get_id(), sidekicks[2]);
                                                    tt--;
                                                }
                                                break;
                                            }
                                            else
                                            {
                                                cout << "please choose(1 , 2)" << endl;
                                            }

                                        }
                                        break;
                                    }
                                    else
                                    {
                                        cout << "this caracter is dead... please choose another character" << endl;
                                    }
                                }
                                if(yy != 1 && yy != 2 && yy != 3 && yy != 4)
                                {
                                    cout << "please choose (1 , 2 , 3 , 4)" << endl;
                                }
                            }
                        }

                        if(hero.get_name() == "Sherlock Holmes")
                    {
                        cout << "choose a caracter to move (1. "  << hero.get_name() << " , 2. " << sidekicks[0].get_name() << ")" << endl;
                        int yy;
                        
                        while(true)
                        {
                            cin >> yy;
                            if(yy == 1)
                            {
                                cout << "how many spaces do you want to move?(1 , 2)" << endl;
                                int tt;
                               
                                while(true)
                                {
                                    cin >> tt;
                                    if(tt == 1 || tt == 2 )
                                    {
                                        while(tt > 0)
                                        {
                                            g.move(hero.get_name(), hero.get_location()->get_id(), hero);
                                            tt--;
                                        }
                                        break;
                                    }
                                    else
                                    {
                                        cout << "please choose(1 , 2)" << endl;
                                    }

                                }
                                break;
                            }
                            if(yy == 2)
                            {
                                if(sidekicks[0].get_status())
                                {
                                    cout << "how many spaces do you want to move?(1 , 2)" << endl;
                                    int tt;
                                    
                                    while(true)
                                    {
                                        cin >> tt;
                                        if(tt == 1 || tt == 2 )
                                        {
                                            while(tt > 0)
                                            {
                                                g.move(sidekicks[0].get_name(), sidekicks[0].get_location()->get_id(), sidekicks[0]);
                                                tt--;
                                            }
                                            break;
                                        }
                                        else
                                        {
                                            cout << "please choose(1 , 2)" << endl;
                                        }

                                    }
                                    break;
                                }
                                else
                                {
                                    cout << "this caracter is dead... please choose another character" << endl;
                                }
                               
                            }
                            if(yy != 1 && yy != 2)
                            {
                                cout << "please choose (1 , 2)" << endl;
                            }
                        }
                    }
                    break;
                    }
                    if(v == 1)
                    {
                        int move;
                        cout << "which one do you want to discard?" << endl;
                        for(int i = 1 ; i <= hand.size() ; i++)
                        {
                            cout << i << ". " ;
                            hand[i - 1].show_card();
                        }
                        int yy;
                        
                        while ((true))
                        {
                            cin >> yy;
                            if(yy<= 0 || yy > hand.size())
                            {
                                cout << "please choose (1 -" << hand.size() << ")" << endl;
                            }
                            else
                            {
                                move = hand[yy-1].get_boost() + 2;
                                hand.erase(hand.begin() + yy - 1);
                                break;
                            }
                        }
                        if(hero.get_name() == "Dracula")
                        {
                            cout << "choose a caracter to move (1. "  << hero.get_name() << " , 2. " << sidekicks[0].get_name() << " , 3. " << sidekicks[1].get_name() << " , 4. " << sidekicks[2].get_name() << ")" << endl;
                            
                            
                            while(true)
                            {
                                cin >> yy;
                                if(yy == 1)
                                {
                                    cout << "how many spaces do you want to move?(1 - "<< move << ")" << endl;
                                    int tt;
                                    
                                    while(true)
                                    {
                                        cin >> tt;
                                        if(tt <= move && tt >= 1)
                                        {
                                            while(tt > 0)
                                            {
                                                g.move(hero.get_name(), hero.get_location()->get_id(), hero);
                                                tt--;
                                            }
                                            break;
                                        }
                                        else
                                        {
                                            cout << "invalid number" << endl;
                                        }

                                    }
                                    break;
                                    
                                }
                                if(yy == 2)
                                {
                                    if(sidekicks[0].get_status())
                                    {
                                        cout << "how many spaces do you want to move?(1 - "<< move << ")"  << endl;
                                        int tt; 
                                        while(true)
                                        {
                                            cin >> tt;
                                            if(tt <= move && tt >= 1)
                                            {
                                                while(tt > 0)
                                                {
                                                    g.move(sidekicks[0].get_name(), sidekicks[0].get_location()->get_id(), sidekicks[0]);
                                                    tt--;
                                                }
                                                break;
                                            }
                                            else
                                            {
                                                cout << "invalid number" << endl;
                                            }

                                        }
                                        break;
                                    }
                                    else
                                    {
                                        cout << "this caracter is dead... please choose another character" << endl;
                                    }
                                    
                                    
                                }
                                if(yy == 3)
                                {
                                    if(sidekicks[1].get_status())
                                    {
                                        cout << "how many spaces do you want to move?(1 - "<< move << ")" << endl;
                                        int tt;
                                        
                                        while(true)
                                        {
                                            cin >> tt;
                                            if(tt <= move && tt >= 1)
                                            {
                                                while(tt > 0)
                                                {
                                                    g.move(sidekicks[1].get_name(), sidekicks[1].get_location()->get_id(), sidekicks[1]);
                                                    tt--;
                                                }
                                                break;
                                            }
                                            else
                                            {
                                                cout << "invalid number" << endl;
                                            }

                                        }
                                        break;
                                    }
                                    else
                                    {
                                        cout << "this caracter is dead... please choose another character" << endl;
                                    }
                                    
                                }
                                if(yy == 4)
                                {
                                    if(sidekicks[2].get_status())
                                    {
                                        cout << "how many spaces do you want to move?(1 - "<< move << ")"  << endl;
                                        int tt;
                                        
                                        while(true)
                                        {
                                            cin >> tt;
                                            if(tt <= move && tt >= 1)
                                            {
                                                while(tt > 0)
                                                {
                                                    g.move(sidekicks[2].get_name(), sidekicks[2].get_location()->get_id(), sidekicks[2]);
                                                    tt--;
                                                }
                                                break;
                                            }
                                            else
                                            {
                                                cout << "invalid number" << endl;
                                            }

                                        }
                                        break;
                                    }
                                    else
                                    {
                                        cout << "this caracter is dead... please choose another character" << endl;
                                    }
                                }
                                if(yy != 1 && yy != 2 && yy != 3 && yy != 4)
                                {
                                    cout << "please choose (1 , 2 , 3 , 4)" << endl;
                                }
                            }
                        }

                        if(hero.get_name() == "Sherlock Holmes")
                        {
                            cout << "choose a caracter to move (1. "  << hero.get_name() << " , 2. " << sidekicks[0].get_name() << ")" << endl;
                            
                            
                            while(true)
                            {
                                cin >> yy;
                                if(yy == 1)
                                {
                                    cout << "how many spaces do you want to move?(1 - "<< move << ")"  << endl;
                                    int tt;
                                
                                    while(true)
                                    {
                                        cin >> tt;
                                        if(tt <=move && tt >= 1)
                                        {
                                            while(tt > 0)
                                            {
                                                g.move(hero.get_name(), hero.get_location()->get_id(), hero);
                                                tt--;
                                            }
                                            break;
                                        }
                                        else
                                        {
                                            cout << "invalid number" << endl;
                                        }

                                    }
                                    break;
                                }
                                if(yy == 2)
                                {
                                    if(sidekicks[0].get_status())
                                    {
                                        cout << "how many spaces do you want to move?(1 - "<< move << ")"  << endl;
                                        int tt;
                                        
                                        while(true)
                                        {
                                            cin >> tt;
                                            if(tt <= move && tt >= 1)
                                            {
                                                while(tt > 0)
                                                {
                                                    g.move(sidekicks[0].get_name(), sidekicks[0].get_location()->get_id(), sidekicks[0]);
                                                    tt--;
                                                }
                                                break;
                                            }
                                            else
                                            {
                                                cout << "invalid number" << endl;
                                            }

                                        }
                                        break;
                                    }
                                    else
                                    {
                                        cout << "this character is dead... please choose another character" << endl;
                                    }
                                
                                }
                                if(yy != 1 && yy != 2)
                                {
                                    cout << "please choose (1 , 2)" << endl;
                                }
                            }
                        }
                    break;
                    }
                   
                }
                else if(h == 2)
                {
                    break;
                }
                else if(h != 2 && h !=1)
                {
                    cout << "please choose (1 or 2)" << endl;
                }
            }
            
                    
        }
        else if(z == 2)
        {
            int q=0;
            
            for(card & s:hand)
            {
                q++;
                if(s.get_type() == cardtype::scheme )
                {
                    c.push_back(hand[q - 1]);
                }
            }
            if(q == 0)
            {
                cout << "you dont have any scheme card please choose another action" << endl;
                start_game(enemy , g);
            }
            cout << "Choose a card " << endl ;
            for(int i = 1 ; i <= c.size() ; i++)
            {
                cout << i << ". " ;
                c[i - 1].show_card();
            }
            int yy;
            
            while ((true))
            {
                cin >> yy;
                if(yy<= 0 || yy > c.size())
                {
                    cout << "please choose (1 -" << c.size() << ")" << endl;
                }
                else
                {
                    effects(c[yy-1],enemy , g);
                    hand.erase(hand.begin() + q - 1);
                    break;
                }
            }
            c.clear();
            
        }
        else if(z == 3)
        {
            int q= 0;
            for(card & s:hand)
            {
                q++;
                if(s.get_type() == cardtype::attack || s.get_type() == cardtype::versatile)
                {
                    c.push_back(hand[q - 1]);
                }
            }
            if(q == 0)
            {
                cout << "you dont have any attack card please choose another action" << endl;
                start_game(enemy , g);
            }
            while (true)
            {
                try
                {
                    choose_fighter(enemy , g);
                    break;
                }
                catch(const std::invalid_argument & e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            while (true)
            {
                try
                {
                    choose_target(enemy);
                    break;
                }
                catch(const std::invalid_argument & e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            q = 0;
            int r = 0;
            if(active_character.get_name() == hero.get_name())
            {
                for(card & s:c)
                {
                    q++;
                    if(s.get_owner() == cardowner::hero || s.get_owner() == cardowner::any)
                    {
                        r++;
                        b.push_back(c[q - 1]);
                    }
                }
            }
            if(hero.get_name() == "Dracula")
            {
                if(active_character.get_name() == sidekicks[0].get_name() || active_character.get_name() == sidekicks[1].get_name() || active_character.get_name() == sidekicks[2].get_name())
                {
                    for(card & s:c)
                    {
                        q++;
                        if(s.get_owner() == cardowner::sidekick || s.get_owner() == cardowner::any)
                        {
                            r++;
                            b.push_back(c[q - 1]);
                        }
                    }
                }
            }
            if(hero.get_name() == "Sherlock Holmes")
            {
                if(active_character.get_name() == sidekicks[0].get_name())
                {
                    for(card & s:c)
                    {
                        q++;
                        if(s.get_owner() == cardowner::sidekick || s.get_owner() == cardowner::any)
                        {
                            r++;
                            b.push_back(c[q - 1]);
                        }
                    }
                }
            }
            if(r == 0)
            {
                cout << "you dont have any attack card for this character... please choose another action or another character" << endl;
                start_game(enemy , g);

            }
            cout << "Choose a card " << endl ;
            for(int i = 1 ; i <= b.size() ; i++)
            {
                cout << i << ". " ;
                b[i - 1].show_card();
            }
            int jj;
            int j;
            int m = 0;
            while(true)
            {
                cin >> jj;
                if(jj<= 0 || jj > b.size())
                {
                    cout << "please choose (1 -" << b.size() << ")" << endl;
                }
                else
                {
                    int o;
                    cout << target.get_name() << " do you want to choose a card?(1. yes , 2. no)" << endl;
                    while(true)
                    {
                        cin >> o;
                        if(o == 1)
                        {
                            q= 0;
                            r = 0;
                            for(card & s:enemy.hand)
                            {
                                q++;
                                if(s.get_type() == cardtype::defense || s.get_type() == cardtype::versatile)
                                {
                                    r++;
                                    c.push_back(enemy.hand[q - 1]);
                                }
                            }
                            if(r == 0)
                            {
                                cout << "you dont have any defense card" << endl;
                                break;
                            }
                            q = 0;
                            r =0;
                            if(target.get_name() == enemy.hero.get_name())
                            {
                                for(card & s:enemy.c)
                                {
                                    q++;
                                    if(s.get_owner() == cardowner::hero || s.get_owner() == cardowner::any)
                                    {
                                        r++;
                                        enemy.b.push_back(enemy.c[q - 1]);
                                    }
                                }
                            }
                            if(enemy.hero.get_name() == "Dracula")
                            {
                                if(target.get_name() == enemy.sidekicks[0].get_name() || target.get_name() == enemy.sidekicks[1].get_name() || target.get_name() == enemy.sidekicks[2].get_name())
                                {
                                    for(card & s:enemy.c)
                                    {
                                        q++;
                                        if(s.get_owner() == cardowner::sidekick || s.get_owner() == cardowner::any)
                                        {
                                            r++;
                                            enemy.b.push_back(enemy.c[q - 1]);
                                        }
                                    }
                                }
                            }
                            if(enemy.hero.get_name() == "Sherlock Holmes")
                            {
                                if(target.get_name() == enemy.sidekicks[0].get_name())
                                {
                                    for(card & s:enemy.c)
                                    {
                                        q++;
                                        if(s.get_owner() == cardowner::sidekick || s.get_owner() == cardowner::any)
                                        {
                                            r++;
                                            enemy.b.push_back(enemy.c[q - 1]);
                                        }
                                    }
                                }
                            }
                            if(r == 0)
                            {
                                cout << target.get_name() <<" there isn't any defense card for you" << endl;
                                break;
                            }
                            else
                            {
                                cout << "Choose a card " << endl ;
                                for(int i = 1 ; i <= enemy.b.size() ; i++)
                                {
                                    cout << i << ". " ;
                                    enemy.b[i - 1].show_card();
                                }
                                while (true)
                                {
                                    cin >> j;
                                    if(j<= 0 || j > enemy.b.size())
                                    {
                                        cout << "please choose (1 -" << enemy.b.size() << ")" << endl;
                                    }
                                    else
                                    {
                                        m++;
                                        effects(enemy.b[j - 1] , enemy , g , &b[jj - 1]);
                                        effects(b[jj-1],enemy , g , &enemy.b[j - 1]);
                                        for(auto it = enemy.hand.begin() ; it != enemy.hand.end() ; it++)
                                        {
                                            if(enemy.b[j-1].get_name() == it->get_name())
                                            {
                                                enemy.hand.erase(it);
                                            }
                                        }
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        else if(o == 2)
                        {
                            break;
                        }
                        else if(o != 1 && o != 2)
                        {
                            cout << "please enter (1 , 2)" << endl;
                        }
                    }
                    if( m == 0)
                    {
                        effects(b[jj-1],enemy , g );
                        for(auto it = hand.begin() ; it != hand.end() ; it++)
                        {
                            if(b[jj-1].get_name() == it->get_name())
                            {
                                hand.erase(it);
                            }
                        }
                    }
                    
                    
                    break;
                }
            }
           
            
        }
        
        else
        {
            cout << "Erorr:(enter 1 , 2 , 3 , 4)     ";
            start_game(enemy, g);
        }
         
        action--;
    }
    action = 2;
}
void game::effects(card& ca , game & enemy , map & g , card * eca)
{
    if(ca.get_name() == "feeding frenzy")
    {
        feeding_frenzy(ca);
    }
    if(ca.get_name() == "mistform")
    {

    }
    if(ca.get_name() == "ambush")
    {

    }
    if(ca.get_name() == "baptism of blood")
    {

    }
    if(ca.get_name() == "beastform")
    {

    }
    if(ca.get_name() == "dash")
    {

    }
    if(ca.get_name() == "exploit")
    {

    }
    if(ca.get_name() == "look into my eyes")
    {

    }
    if(ca.get_name() == "pray upon")
    {

    }
    if(ca.get_name() == "feeding frenzy")
    {

    }
    if(ca.get_name() == "ravening seduction")
    {

    }
    if(ca.get_name() == "thirst for sustenance")
    {

    }
    if(ca.get_name() == "feint")
    {

    }
    if(ca.get_name() == "administer aid")
    {

    }
    if(ca.get_name() == "counterpunch")
    {

    }
    if(ca.get_name() == "deduce strategy")
    {

    }
    if(ca.get_name() == "education never ends")
    {

    }
    if(ca.get_name() == "eliminate the impossible")
    {

    }
    if(ca.get_name() == "feint_")
    {

    }
    if(ca.get_name() == "fixed point in a changing age")
    {

    }
    if(ca.get_name() == "master of disguise")
    {

    }
    if(ca.get_name() == "the game is afoot")
    {

    }
    if(ca.get_name() == "service revolver")
    {

    }
    if(ca.get_name() == "study methodes")
    {

    }
}
void game::feeding_frenzy(card & ca)
{
    int t = 0;
    for(auto &sister: sidekicks)
    {
        int i = target.get_location()->get_zone().size();
        int j = sister.get_location()->get_zone().size();
        for(int z= 0 ; z < i ; z++)
        {
            for(int m = 0 ; m < j ; m++)
            {
                if(target.get_location()->get_zone()[i] == sister.get_location()->get_zone()[j])
                {
                    t+=1;
                }
            }
        }
        
    } 
    ca.set_value(t+2);
}
void game::mistform(map & g)
{
    while(true)
    {

        try
        {
            g.move2(hero);
            break;
        }
        catch(const std::invalid_argument& e)
        {
            std::cerr << e.what() << '\n';
        }
    }  
    action++;
}
void game::ambush(card& ca ,game & enemy)
{
    int random = rand() % enemy.hand.size();
    ca.set_value(enemy.hand[random].get_boost());
    enemy.hand.erase(enemy.hand.begin() + random);
}
void game::baptism_of_blood(map & g)
{
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
                g.move3(hero , sidekicks[0] , g);
                break;
            }
            catch(const std::invalid_argument& e)
            {
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
                g.move3(hero , sidekicks[1] ,g);
                break;
            }
            catch(const std::invalid_argument& e)
            {
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
                g.move3(hero , sidekicks[2] , g);
                break;
            }
            catch(const std::invalid_argument& e)
            {
                std::cerr << e.what() << '\n';
            }
        }  
    }
}
void game::beastform(card& ca)
{
    int q = 0;
    cout << "choose the cards you want to discard (enter 0 to end)" << endl;
    for(auto &h:hand)
    {
        q++;
        cout << q << ". ";
        h.show_card();
    }
    int qq = 1;
    int counter = 0;
    for(;qq != 0 ;)
    {
        counter++;
        cin >> qq;
        if(qq > q || qq < 1)
        {
            cout << "Error: invalid number" << endl;
            counter--;
        }
        else
        {
            hand.erase(hand.begin() + qq - 1);
        }
    }
    ca.set_value(counter +6);
}
void game::dash(map & g)
{
    for(int i = 0 ; i < 3 ; i++)
    {
        g.move(active_character.get_name() , active_character.get_location()->get_id() , active_character);
    }
}
void game::expolit()
{
    int random;
    random = rand()% deck.size();
    hand.push_back(deck[random]);
    deck.erase(deck.begin() + random);
}
void game::look_into_my_eyes(game & enemy , card & ca , card & eca)
{
    ca.set_value(1 + eca.get_boost());
}
void game::prey_upon(map & g , game & enemy)
{
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

void game::choose_fighter(game & enemy , map& g)
{
    cout << "Choose your active caracter (1. " << hero.get_name() << " 2. " << sidekicks[0].get_name() ;
    if(hero.get_name() == "Dracula")
    {
        cout << sidekicks[0].get_name() << " 3. " << sidekicks[1].get_name() << " 4. " << sidekicks[2].get_name() << endl;
        int y;
        cin >> y;
        if(y != 1 && y != 2 && y != 3 && y != 4)
        {
            throw invalid_argument("Error: invalid number");
        }
        
        while (true)
        {
            if(y == 1)
            {
                if(hero.get_status())
                {
                    if(g.get_draculaandsisters_neighbors(hero))
                    {
                        active_character = hero;
                        break;
                    }
                    else
                    {
                        cout << "choose another fighter... or enter 0 to choose another action" << endl;
                        cin >>  y;
                    }
                    
                }
                else
                {
                    cout << "this caracter is dead... please choose another character or enter 0 to choose another action" << endl;
                    cin >> y;
                }
                if(y == 0)
                {
                    start_game(enemy , g);
                }
            }
            if(y == 2)
            {
                if(sidekicks[0].get_status())
                {
                    if(g.get_draculaandsisters_neighbors(sidekicks[0]))
                    {
                        active_character = sidekicks[0];
                        break;
                    }
                    else
                    {
                        cout << "choose another fighter... or enter 0 to choose another action" << endl;
                        cin >> y;
                    }
                }
                else
                {
                    cout << "this caracter is dead... please choose another character or enter 0 to choose another action" << endl;
                    cin >> y;
                }
                if(y == 0)
                {
                    start_game(enemy , g);
                }
            }
            if(y == 3)
            {
                if(sidekicks[1].get_status())
                {
                    if(g.get_draculaandsisters_neighbors(sidekicks[1]))
                    {
                        active_character = sidekicks[1];
                        break;
                    }
                    else
                    {
                        cout << "choose another fighter... or enter 0 to choose another action" << endl;
                        cin >> y;
                    }
                }
                else
                {
                    cout << "this caracter is dead... please choose another character or enter 0 to choose another action" << endl;
                    cin >> y;
                }
                if(y == 0)
                {
                    start_game(enemy , g);
                }
            }
            if(y == 4)
            {
                if(sidekicks[2].get_status())
                {
                    if(g.get_draculaandsisters_neighbors(sidekicks[2]))
                    {
                        active_character = sidekicks[2];
                        break;
                    }
                    else
                    {
                        cout << "choose another fighter... or enter 0 to choose another action" << endl;
                        cin >> y;
                    }
                    
                }
                else
                {
                    cout << "this caracter is dead... please choose another character or enter 0 to choose another action" << endl;
                    cin >> y;
                }
                if(y == 0)
                {
                    start_game(enemy , g);
                }
            }
        }
        
        
    }
    else
    {
        cout << sidekicks[0].get_name() <<endl;
        int y;
        
        cin >> y;
        if(y != 1 && y != 2 )
        {
            throw invalid_argument("Error: invalid number");
        }
        
        while (true)
        {
            if(y == 1)
            {
                if(hero.get_status())
                {
                    if(g.get_sherlock_neighbors(hero))
                    {
                        active_character = hero;
                        break;
                    }
                    else
                    {
                        cout << "choose another fighter... or enter 0 to choose another action" << endl;
                        cin >> y;
                    }
                }
                else
                {
                    cout << "this caracter is dead... please choose another character or enter 0 to choose another action" << endl;
                    cin >> y;
                }
                if(y == 0)
                {
                    start_game(enemy , g);
                }
            }
            if(y == 2)
            {
                if(sidekicks[0].get_status())
                {
                    
                    active_character = sidekicks[0];
                    break;
                        
                }
                else
                {
                    cout << "this caracter is dead... please choose another character or enter 0 to choose another action" << endl;
                    cin >> y;
                }
                if(y == 0)
                {
                    start_game(enemy , g);
                }
            }
        }
    }
}   
void game::choose_target(game & enemy)
{
    cout << "Choose your target (1. " << enemy.hero.get_name() << " 2. ";
    if(enemy.hero.get_name() == "Dracula")
    {
        cout << enemy.sidekicks[0].get_name() << " 3. " << enemy.sidekicks[1].get_name() << " 4. " << enemy.sidekicks[2].get_name() << endl;
        int yy;
        cin >> yy;
        if(yy != 1 && yy != 2 && yy != 3 && yy != 4)
        {
            throw invalid_argument("Error: invalid number");
        }
        while (true)
        {
            if(yy == 1)
            {
                if(enemy.hero.get_status())
                {
                    target = enemy.hero;
                    break;
                }
                else
                {
                    cout << "this caracter is dead... please choose another character" << endl;
                    cin >> yy;
                }
            }
            if(yy == 2)
            {
                if(enemy.sidekicks[0].get_status())
                {
                    target = enemy.sidekicks[0];
                    break;
                }
                else
                {
                    cout << "this caracter is dead... please choose another character" << endl;
                    cin >> yy;
                }
            }
            if(yy == 3)
            {
                if(enemy.sidekicks[1].get_status())
                {
                    target = enemy.sidekicks[1];
                    break;
                }
                else
                {
                    cout << "this caracter is dead... please choose another character" << endl;
                    cin >> yy;
                }
            }
            if(yy == 4)
            {
                if(enemy.sidekicks[2].get_status())
                {
                    target = enemy.sidekicks[2];
                    break;
                }
                else
                {
                    cout << "this caracter is dead... please choose another character" << endl;
                    cin >> yy;
                }
            }
        }
    }
    else
    {
        cout << enemy.sidekicks[0].get_name() <<endl;
        int yy;
        cin >> yy;
        if(yy != 1 && yy != 2 )
        {
            throw invalid_argument("Error: invalid number");
        } 
        while (true)
        {
            if(yy == 1)
            {
                if(enemy.hero.get_status())
                {
                    target = enemy.hero;
                    break;
                }
                else
                {
                    cout << "this caracter is dead... please choose another character" << endl;
                    cin >> yy;
                }
            }
            if(yy == 2)
            {
                if(enemy.sidekicks[0].get_status())
                {
                    target = enemy.sidekicks[0];
                    break;
                }
                else
                {
                    cout << "this caracter is dead... please choose another character" << endl;
                    cin >> yy;
                }
            }
        }
    }
}