#include "game.h"
#include "tui.h"
#include <iostream>
#include <vector>

using namespace std;

game::game()
{
    string player;
    cin >> player;
    name = player;
    alivee = true;
    action = 2;
}
void game::age(game &enemy , map& g , tui t)
{
    
    int a;
    a = t.agee(name , enemy.name);
    if(a == 0)
    {
        yoro = "younger";
        enemy.yoro = "older";
        cout  << name << " please choose one of these characters" << endl;
    }
    if(a == 1)
    {
        yoro = "older";
        enemy.yoro = "younger";
        cout  << enemy.name << " please choose one of these characters" << endl;
    }
}
void game::choose_character(game& enemy , map& g , tui t)
{
    int a = t.choose_character();
    if(a ==0)
    {
        hero = character("Dracula" , 13 , 2 , "melee");

        sidekicks.push_back(character("sister 1", 1 , 2 , "melee"));
        sidekicks.push_back(character("sister 2", 1 , 2 , "melee"));
        sidekicks.push_back(character("sister 3", 1 , 2 , "melee"));
        enemy.hero =character("Sherlock Holmes", 16 , 2 , "melee");
        enemy.sidekicks.push_back(character("Dr.Watson", 8 , 2 , "ranged"));
    }
    else if(a == 1)
    {
        enemy.hero = character("Dracula" , 13 , 2 , "melee");
        enemy.sidekicks.push_back(character("sister 1", 1 , 2 , "melee"));
        enemy.sidekicks.push_back(character("sister 2", 1 , 2, "melee"));
        enemy.sidekicks.push_back(character("sister 3", 1 , 2, "melee"));
        hero =character("Sherlock Holmes", 16 , 2 , "melee");
        sidekicks.push_back(character("Dr.Watson", 8 , 2, "ranged"));
    }
    choose_location(enemy , g , t);

}
void game::choose_location(game& enemy , map& g , tui tt)
{ 
    int a;
    int r;
    int s;
    int t;
    g.show_map();
    a = tt.choose_space(g, "please choose one of these spaces" , {5 ,25});
    if(a == 0)
    {
        if(hero.get_name() == "Dracula")
        {
            vector<int> spaces ={1 , 2 , 3 , 4 , 7};
            hero.set_location(g.get_space(5));
            enemy.hero.set_location(g.get_space(25));
            g.set_location("Dracula" , 5);
            g.set_location("Sherlock Holmes" , 25);
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
                    cout << "invalid number ... please choose another space" << endl;
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
                    cout << "invalid number ... please choose another space" << endl;
                }
            }
            spaces.clear();
            vector<int> spacess ={14 , 23 , 24 , 26};
            index = tt.choose_space(g ,enemy.name + " please choose a spaces for Dr.Watson" , {14 , 23 , 24 , 26});
            r = spacess[index];
            if(r ==14 || r == 23 || r == 24 || r == 26)
            {
                enemy.sidekicks[0].set_location(g.get_space(r));
                g.set_location("Dr.Watson" , r);
            }
            spacess.clear();
        }
        else
        {
            hero.set_location(g.get_space(5));
            enemy.hero.set_location(g.get_space(25));
            g.set_location("Sherlock Holmes" , 5);
            g.set_location("Dracula" , 25);
            vector<int> spaces ={1 , 2 , 3 , 4 , 7};
            int index = tt.choose_space(g ,name + " please choose a spaces for Dr.Watson" , {1 , 2 , 3 , 4 , 7});
            r = spaces[index];
           
            if(r ==1 || r == 2 || r == 3 || r == 4 || r == 7)
            {
                sidekicks[0].set_location(g.get_space(r));
                g.set_location("Dr.Watson" , r);
            
            }
            spaces.clear();
            vector<int> spacess ={14 , 23 , 24 , 26};
            index = tt.choose_space(g ,enemy.name + " please choose 3 spaces for your sisters " , {14 , 23 , 24 , 26});
            r = spacess[index];
            
            if(r ==14 || r == 23 || r == 24 || r == 26 )
            {
                enemy.sidekicks[0].set_location(g.get_space(r));
                g.set_location("sister 1" , r);
            }
               
            while (true)
            {
                index = tt.choose_space(g ,enemy.name + " please choose 3 spaces for your sisters " , {14 , 23 , 24 , 26});
                s = spacess[index];
                if((s ==14 || s == 23 || s == 24 || s == 26 ) && s != r)
                {
                    enemy.sidekicks[1].set_location(g.get_space(s));
                    g.set_location("sister 2" , s);
                    break;
                }
                else
                {
                    cout << "invalid number ... please choose another space" << endl;
                }
            }
            while (true)
            {
                index = tt.choose_space(g ,enemy.name + " please choose 3 spaces for your sisters " , {14 , 23 , 24 , 26});
                t = spacess[index];
                if((t ==14 || t == 23 || t == 24 || t == 26 ) && t != r && t != s)
                {
                    enemy.sidekicks[2].set_location(g.get_space(t));
                    g.set_location("sister 3" , t);
                    break;
                }
                else
                {
                    cout << "invalid number ... please choose another space" << endl;
                }
            }
            spacess.clear();
        }
    }
    else if(a == 1)
    {
        if(hero.get_name() == "Dracula")
        {
            hero.set_location(g.get_space(25));
            enemy.hero.set_location(g.get_space(5));
            g.set_location("Dracula" , 25);
            g.set_location("Sherlock Holmes" , 5);
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
                    cout << "invalid number ... please choose another space" << endl;
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
                    cout << "invalid number ... please choose another space" << endl;
                }
            }
            spaces.clear();
            vector<int> spacess ={1 , 2 , 3 , 4 , 7};
            index = tt.choose_space(g ,enemy.name + " please choose a spaces for Dr.Watson " , {1, 2, 3, 4 , 7});
            r = spacess[index];
            
            if(r ==1 || r == 2 || r == 3 || r == 4 || r == 7)
            {
                enemy.sidekicks[0].set_location(g.get_space(r));
                g.set_location("Dr.Watson" , r);
            
            }
            spacess.clear();
        }
        else
        {
            hero.set_location(g.get_space(25));
            enemy.hero.set_location(g.get_space(5));
            g.set_location("Sherlock Holmes" , 25);
            g.set_location("Dracula" , 5);
            vector<int> spaces ={14 , 23 , 24 , 26};
            int index = tt.choose_space(g ,name + " please choose a spaces for Dr.Watson " , {14 , 23 , 24 , 26});
            r = spaces[index];
            if(r ==14 || r == 23 || r == 24 || r == 26)
            {
                sidekicks[0].set_location(g.get_space(r));
                g.set_location("Dr.Watson" , r);
            }
            spaces.clear();
             vector<int> spacess ={1 , 2 , 3 , 4 , 7};
            index = tt.choose_space(g ,enemy.name + " please choose 3 spaces for your sisters " , {1 , 2 , 3 , 4 , 7});
            r = spacess[index];
           
            if(r == 1 || r == 2 || r == 3 || r == 4 || r == 7)
            {
                enemy.sidekicks[0].set_location(g.get_space(r));
                g.set_location("sister 1" , r);
            }
            while (true)
            {
                index = tt.choose_space(g ,enemy.name + " please choose 3 spaces for your sisters " , {1 , 2 , 3 , 4 , 7});
                s = spacess[index];
                if((s == 1 || s == 2 || s == 3 || s == 4 || s == 7 ) && s != r)
                {
                    enemy.sidekicks[1].set_location(g.get_space(s));
                    g.set_location("sister 2" , s);
                    break;
                }
                else
                {
                    cout << "invalid number ... please choose another space" << endl;
                }
            }
            while (true)
            {

                index = tt.choose_space(g ,enemy.name + " please choose 3 spaces for your sisters " , {1 , 2 , 3 , 4 , 7});
                t = spacess[index];
                if((t == 1 || t == 2 || t == 3 || t == 4 || t == 7) && t != r && t != s)
                {
                    enemy.sidekicks[2].set_location(g.get_space(t));
                    g.set_location("sister 3" , t);
                    break;
                }
                else
                {
                    cout << "invalid number ... please choose another space" << endl;
                }
            }
            spacess.clear();
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
void game::start_game(game & enemy , map & g , tui tu)
{
    if(enemy.hand.size() > 7)
    {
        cout << "You have more than 7 cards ... Please choose card to discard" << endl;
        for(int i = 1  ; i <= enemy.hand.size() ; i++)
        {
            cout << i << ". ";
            enemy.hand[i - 1].show_card();
        }
        int hh; 
        
        while (enemy.hand.size() > 7)
        {
            cin >> hh;
            if(hh > enemy.hand.size() || hh < 1)
            {
                cout << "Invalid number" << endl;
            }
            else
            {
                enemy.hand.erase(enemy.hand.begin() + hh - 1);
            }
        }
    }
    cout << hero.get_name() << " turn" << endl;
    while(action > 0)
    {
        b.clear();
        c.clear();
        enemy.b.clear();
        enemy.c.clear();
        int z = tu.action_menu();        
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
                                        g.move(hero.get_name(), hero.get_location()->get_id(), hero , g);
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
                                            g.move(sidekicks[0].get_name(), sidekicks[0].get_location()->get_id(), sidekicks[0] , g);
                                            tt--;
                                        }
                                            
                                        break;
                                    }
                                    else
                                    {
                                        cout << "this character is dead... please choose another character" << endl;
                                    }
                                    
                                    
                                }
                                if(yy == 2)
                                {
                                    if(sidekicks[1].get_status())
                                    {
                                        int tt = tu.choose_acharacter("How many spaces do you want to move?" , {"1" , "2" });;
                                        while(tt+1 > 0)
                                        {
                                            g.move(sidekicks[1].get_name(), sidekicks[1].get_location()->get_id(), sidekicks[1] , g);
                                            tt--;
                                        }
                                        break;
                                           
                                    }
                                    else
                                    {
                                        cout << "this character is dead... please choose another character" << endl;
                                    }
                                    
                                }
                                if(yy == 3)
                                {
                                    if(sidekicks[1].get_status())
                                    {
                                        int tt = tu.choose_acharacter("How many spaces do you want to move?" , {"1" , "2" });;
                                        while(tt+1 > 0)
                                        {
                                            g.move(sidekicks[2].get_name(), sidekicks[2].get_location()->get_id(), sidekicks[2] , g);
                                            tt--;
                                        }
                                        break;
                                           
                                    }
                                    else
                                    {
                                        cout << "this character is dead... please choose another character" << endl;
                                    }
                                }
                            }
                        }

                        if(hero.get_name() == "Sherlock Holmes")
                        {
                           
                            while(true)
                            {
                                int yy = yy = tu.choose_acharacter("Choose a character to move" , { hero.get_name() , sidekicks[0].get_name()});
                               
                                if(yy == 0)
                                {
                                     int tt = tu.choose_acharacter("How many spaces do you want to move?" , {"1" , "2" });
                                    while(tt+1 > 0)
                                    {
                                        g.move(hero.get_name(), hero.get_location()->get_id(), hero , g);
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
                                            g.move(sidekicks[0].get_name(), sidekicks[0].get_location()->get_id(), sidekicks[0] , g);
                                            tt--;
                                        }
                                            
                                        break;
                                    }
                                    else
                                    {
                                        cout << "this character is dead... please choose another character" << endl;
                                    }
                                
                                }
                            }
                        }
                    
                    }
                    if(v == 0)
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
                            
                            while(true)
                            {
                                int yy = tu.choose_acharacter("Choose a character to move" , { hero.get_name() , sidekicks[0].get_name() , sidekicks[1].get_name() , sidekicks[2].get_name() });
                                
                                if(yy == 0)
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
                                                g.move(hero.get_name(), hero.get_location()->get_id(), hero , g);
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
                                if(yy == 1)
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
                                                    g.move(sidekicks[0].get_name(), sidekicks[0].get_location()->get_id(), sidekicks[0] , g);
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
                                if(yy == 2)
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
                                                    g.move(sidekicks[1].get_name(), sidekicks[1].get_location()->get_id(), sidekicks[1] , g);
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
                                                    g.move(sidekicks[2].get_name(), sidekicks[2].get_location()->get_id(), sidekicks[2] , g);
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
                               
                            }
                        }

                        if(hero.get_name() == "Sherlock Holmes")
                        {
                           
                            while(true)
                            {
                                int yy = tu.choose_acharacter("Choose a character to move" , { hero.get_name() , sidekicks[0].get_name() });
                                
                                if(yy == 0)
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
                                                g.move(hero.get_name(), hero.get_location()->get_id(), hero , g);
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
                                if(yy == 1)
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
                                                    g.move(sidekicks[0].get_name(), sidekicks[0].get_location()->get_id(), sidekicks[0] , g);
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
                                  
                            }
                        }
                    
                    }
                   
                }
                else if(h == 1)
                {
                }
             action--;
            hero.set_status();
            enemy.hero.get_status();
            for(auto &s:sidekicks)
            {
                s.get_status();
            }
            for(auto &s:enemy.sidekicks)
            {
                s.get_status();
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
                cout << "you dont have any scheme card please choose another action" << endl;
                start_game(enemy , g , tu);
                return;
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
                    card_effects(c[yy-1],enemy , g);
                    hand.erase(hand.begin() + index[yy-1]);
                    break;
                }
            }
            c.clear();
            action--;
            hero.set_status();
            enemy.hero.get_status();
            for(auto &s:sidekicks)
            {
                s.get_status();
            }
            for(auto &s:enemy.sidekicks)
            {
                s.get_status();
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
                cout << "you dont have any attack card please choose another action" << endl;
                start_game(enemy , g , tu);
                return;
            }
            try
            {
                choose_fighter(enemy , g);
            }
            catch(const std::invalid_argument & e)
            {
                std::cerr << e.what() << '\n';
                cout << "please choose another action ..." << endl;
                start_game(enemy , g , tu);
                return;
            }
            choose_target(enemy);
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
                cout << "you dont have any attack card for this character... please choose another action or another character" << endl;
                start_game(enemy , g , tu);
                return;

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
                    cout << target->get_name() << " do you want to choose a card?(1. yes , 2. no)" << endl;
                    while(true)
                    {
                        cin >> o;
                        if(o == 1)
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
                                cout << "you dont have any defense card" << endl;
                                break;
                            }
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
                                cout << target->get_name() <<" there isn't any defense card for you" << endl;
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
                                        attack(enemy , g , b[j - 1] , &b[jj - 1]);
                                        for(auto it = enemy.hand.begin() ; it != enemy.hand.end() ; it++)
                                        {
                                            if(enemy.b[j-1].get_name() == it->get_name())
                                            {
                                                enemy.hand.erase(it);
                                            }
                                        }
                                        for(auto it = hand.begin() ; it != hand.end() ; it++)
                                        {
                                            if(b[jj-1].get_name() == it->get_name())
                                            {
                                                hand.erase(it);
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
                    if(m == 0)
                    {
                        attack(enemy , g , b[jj - 1]);
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
             action--;
             hero.set_status();
            enemy.hero.get_status();
            for(auto &s:sidekicks)
            {
                s.get_status();
            }
            for(auto &s:enemy.sidekicks)
            {
                s.get_status();
            }
        }
        else if(z == 3)
        {
            g.show_map();
        }
        else if(z == 4)
        {
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
           else
           {
                if(sidekicks[0].get_status())
                {
                    cout << "Dr.Watson    " << "Health: " << sidekicks[0].get_hp() << " Space: " << sidekicks[0].get_location()->get_id() << endl;
                }
           }
           
        }
        else if(z == 5)
        {
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
           else
           {
                if(enemy.sidekicks[0].get_status())
                {
                    cout << "Dr.Watson    " << "Health: " << enemy.sidekicks[0].get_hp() << " Space: " << enemy.sidekicks[0].get_location()->get_id() << endl;
                }
           }
        }
        else if(z == 6)
        {
            int ttt=tu.main_menu();
            while(true)
            {
                if(ttt == 0)
                {
                    break;
                }
                if(ttt == 1)
                {
                    cout << "================ HELP ================" << endl;
                    cout << "Objective:" << endl;
                    cout << "Defeat the enemy Hero by reducing their Health to 0" << endl << endl;

                    cout << "Actions:" << endl;
                    cout << "- Maneuver: Move your fighter and draw one card" << endl;
                    cout << "- Attack: Attack an adjacent enemy" << endl;
                    cout << "- Scheme: Play a special card effect" << endl << endl;

                    cout << "Card Types:" << endl;
                    cout << "- Attack" << endl;
                    cout << "- Defense" << endl;
                    cout << "- Versatile" << endl;
                    cout << "- Scheme" << endl << endl;
                    cout << "Good luck and have fun!" << endl;
                    cout << "======================================" << endl;

                    cout << "Enter 0 to back to main menu" << endl;
                    int q;
                    while (true)
                    {
                        cin >> q;
                        if(q == 0)
                        {
                            ttt = tu.main_menu();
                            break;
                        }
                        else
                        {
                            cout << "Invalid number" << endl;
                        }
                    }
                }
                if(ttt == 2)
                {
                    cout << "Game Exited" << endl;
                    exit(0);
                }
            }

        }
        alive();
        enemy.alive();
        if(!hero.get_status() || !enemy.hero.get_status())
        {
            break;
        }
    }
    action = 2;
}
void game::card_effects(card& ca , game & enemy , map & g , card * eca)
{
    if(ca.get_name() == "feeding frenzy")
    {
        feeding_frenzy(ca);
    }
    if(ca.get_name() == "mistform")
    {
        mistform(g);
    }
    if(ca.get_name() == "ambush")
    {
        ambush(ca ,enemy);
    }
    if(ca.get_name() == "baptism of blood")
    {
        baptism_of_blood( g);
    }
    if(ca.get_name() == "beastform")
    {
        beastform(ca);
    }
    if(ca.get_name() == "dash")
    {
        dash(g);
    }
    if(ca.get_name() == "exploit")
    {
        expolit();
    }
    if(ca.get_name() == "look into my eyes")
    {
        look_into_my_eyes( enemy , ca , eca);
    }
    if(ca.get_name() == "pray upon")
    {
        prey_upon( g ,enemy);
    }
    if(ca.get_name() == "ravening seduction")
    {

    }
    if(ca.get_name() == "thirst for sustenance")
    {
        thirst_for_sustenance(g);
    }
    if(ca.get_name() == "feint")
    {

    }
    if(ca.get_name() == "administer aid")
    {
        administer_aid( g);
    }
    if(ca.get_name() == "counterpunch")
    {
        counterpunch( g , enemy);
    }
    if(ca.get_name() == "deduce strategy")
    {
        deduce_strategy( ca , eca);
    }
    if(ca.get_name() == "education never ends")
    {
        education_never_ends(enemy);
    }
    if(ca.get_name() == "eliminate the impossible")
    {
        eliminate_the_impossible(enemy);
    }
    if(ca.get_name() == "feint_")
    {

    }
    if(ca.get_name() == "fixed point in a changing age")
    {
        fixed_point_in_a_changing_age(enemy);
    }
    if(ca.get_name() == "master of disguise")
    {
        while (true)
        {
            try
            {
                master_of_disguise(enemy ,g);
                break;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }
    }
    if(ca.get_name() == "the game is afoot")
    {
        the_game_is_afoot(g);
    }
    if(ca.get_name() == "service revolver")
    {
        
    }
    if(ca.get_name() == "study methodes")
    {
        study_methods(enemy);
    }
}
void game::feeding_frenzy(card & ca)
{
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
                if(target->get_location()->get_zone()[i] == sister.get_location()->get_zone()[j])
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
    cout << "               mistform" << endl;
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
    cout << "               ambush" << endl;
    int random = rand() % enemy.hand.size();
    ca.set_value(enemy.hand[random].get_boost());
    enemy.hand.erase(enemy.hand.begin() + random);
}
void game::baptism_of_blood(map & g)
{
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
    cout << "               beastform" << endl;
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
        cin >> qq;
        if(qq > q || qq < 1)
        {
            if(qq == 0)
            {
                break;
            }
            else
            {
                cout << "Error: invalid number" << endl;
            }
        }
        else
        {
            counter++;
            hand.erase(hand.begin() + qq - 1);
        }
    }
    ca.set_value(counter +6);
}
void game::dash(map & g)
{
    cout << "               dash" << endl;
    for(int i = 0 ; i < 3 ; i++)
    {
        g.move(active_character->get_name() , active_character->get_location()->get_id() ,* active_character , g);
    }
}
void game::expolit()
{
    cout << "                expolit" << endl;
    int random;
    random = rand()% deck.size();
    hand.push_back(deck[random]);
    deck.erase(deck.begin() + random);
}
void game::look_into_my_eyes(game & enemy , card & ca , card * eca)
{
    cout << "               look into my eyes" << endl;
    if(eca != nullptr)
    {
        ca.set_value(1 + eca->get_boost());
    }
}
void game::prey_upon(map & g , game & enemy)
{
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
void game::administer_aid(map& g)
{
    cout << "                administer aid" << endl;
    int ch;
    cout << "where do you want to place Dr.Watson?" << endl;
    while (true)
    {
        try
        {
            ch = hero.get_location()->show_neighbors();
            break;
        }
        catch(const std::invalid_argument& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
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
void game::counterpunch(map & g , game& enemy)
{
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
        cout << "there isnt any enemies next to you ..." << endl;
    }
}
void game::thirst_for_sustenance(map & g)
{
    cout << "               thirst for sustenance" << endl;
    if(damage> 0)
    {
        int s;
        cout << "where do you want to place Dracula?" << endl;
        while (true)
        {
            try
            {
                s = target->get_location()->show_neighbors();
                break;
            }
            catch(const std::invalid_argument& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        hero.get_location()->set_thisspacef();
        hero.set_location(g.get_space(s));
        g.set_location("Dracula" ,s);
    }
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
        for(auto &s:enemy.sidekicks)
        {
            if(s.get_location()->has_zone(zone::ice))
            {
                ch.push_back(&s);
            }
        }
    }
    if(cha.get_location()->has_zone(zone::blue))
    {
        if(enemy.hero.get_location()->has_zone(zone::blue))
        {
            ch.push_back(&enemy.hero);
        }
        for(auto &s:enemy.sidekicks)
        {
            if(s.get_location()->has_zone(zone::blue))
            {
                ch.push_back(&s);
            }
        }
    }
    if(cha.get_location()->has_zone(zone::broun))
    {
        if(enemy.hero.get_location()->has_zone(zone::broun))
        {
            ch.push_back(&enemy.hero);
        }
        for(auto &s:enemy.sidekicks)
        {
            if(s.get_location()->has_zone(zone::broun))
            {
                ch.push_back(&s);
            }
        }
    }
    if(cha.get_location()->has_zone(zone::gray))
    {
        if(enemy.hero.get_location()->has_zone(zone::gray))
        {
            ch.push_back(&enemy.hero);
        }
        for(auto &s:enemy.sidekicks)
        {
            if(s.get_location()->has_zone(zone::gray))
            {
                ch.push_back(&s);
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
void game::eliminate_the_impossible(game& enemy)
{
    cout << "               eliminate the impossible" << endl;
    int choice;
    cout << "choose a card you want to discard" << endl;
    for(int i = 1 ; i <= enemy.hand.size() ; i++)
    {
        cout << i << ". ";
        enemy.hand[i-1].show_card();
    }
    while(true)
    {
        cin >> choice;
        if(choice > enemy.hand.size() || choice <= 0)
        {
            cout << "invalid number" << endl;
        }
        else
        {
            enemy.hand.erase(enemy.hand.begin() + choice - 1);
            break;
        }
    }
} 
void game::fixed_point_in_a_changing_age(game& enemy)
{
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
    cout << "               deduce strategy" << endl;
    if(eca != nullptr)
    {
        eca->set_value(eca->get_boost());
    }
}

void game::master_of_disguise(game & enemy , map & g)
{
    cout << "               master of disguise" << endl;
    cout << "who is your target?" << endl << "1. Dracula  2. sister1  3. sister2  4. sister3" << endl;
    
    int yy;
    
    while (true)
    {
        cin >> yy;
        if(yy == 1)
        {
            if(enemy.hero.get_status())
            {
                target = &enemy.hero;
                break;
            }
            else
            {
                cout << "this character is dead... please choose another character" << endl;
            }
        }
        else if(yy == 2 || yy == 3 || yy == 4)
        {
            if(enemy.sidekicks[yy-2].get_status())
            {
                target = &enemy.sidekicks[yy-2];
                break;
            }
            else
            {
                cout << "this character is dead... please choose another character" << endl;
            }
        }
        else
        {
            throw invalid_argument("Error: invalid number");
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
void game::the_game_is_afoot(map &g)
{
    cout << "                the game is afoot" << endl;
    for(int i = 0 ; i < 3 ; i++)
    {
        g.move(hero.get_name(), hero.get_location()->get_id(), hero , g);
    }
}
void game::study_methods(game & enemy)
{
    cout << "               study methods" << endl;
    if(damage > 0)
    {
        cout << "your enemy hand ..." << endl;
        for(int i = 1 ; i <= enemy.hand.size() ; i++)
        {
            cout << i << ". ";
            enemy.hand[i-1].show_card();
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
    return neighborenemy;
}
void game::attack(game & enemy , map & g , card& ca , card* eca)
{
    if(eca == nullptr)
    {
        if(ca.get_time() == timing::beforcombat)
        {
            card_effects(ca , enemy , g);
        }
        else if(ca.get_time() == timing::duringccombat)
        {
            card_effects(ca , enemy , g);
        }
        target->set_hp(target->get_hp() - ca.get_value());
        damage= ca.get_value();
        if(ca.get_time() == timing::aftercombat)
        {
            card_effects(ca , enemy , g);
        }
    }
    else
    {
        if(ca.get_time() == timing::beforcombat)
        {
            card_effects(ca , enemy , g , eca);
        }
        if(eca->get_time() == timing::beforcombat)
        {
            card_effects(ca , enemy , g , eca);
        }
        if(ca.get_time() == timing::duringccombat)
        {
            card_effects(ca , enemy , g , eca);
        }
        if(eca->get_time() == timing::duringccombat)
        {
            card_effects(ca , enemy , g , eca);
        }
        damage = eca->get_value() - ca.get_value();
        if(damage < 0)
        {
            damage = 0;
        }
        target->set_hp(target->get_hp() - damage);
        if(ca.get_time() == timing::aftercombat)
        {
            card_effects(ca , enemy , g , eca);
        }
        if(eca->get_time() == timing::aftercombat)
        {
            card_effects(ca , enemy , g , eca);
        }
    }
    cout <<"damage: " << damage << endl;
}
void game::choose_fighter(game & enemy , map& g)
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
    int choice;
    if(available_characters.empty())
    {
        throw invalid_argument("No fighter can attack");
    }
    else
    {
        cout << "Choose your active character" << endl;

        for(int i = 1 ; i <= available_characters.size() ; i++)
        {
            cout << i << ". " << available_characters[i-1]->get_name() << endl;
        }
        while(true)
        {
            cin >> choice;
            if(choice <= 0 || choice > available_characters.size())
            {

            }
            else
            {
                active_character = available_characters[choice - 1];
                break;
            }
        }

    }    
}   
void game::choose_target(game & enemy)
{
    cout << "choose your target" << endl;
    if(active_character->get_attack_type() != "melee")
    {
        vector <character*> enemies = get_neighborenemy(*active_character , enemy);
        int i = 1;
        for(; i <= enemies.size() ; i++)
        {
            cout << i << ". " << enemies[i-1]->get_name() << endl;
        }
        int choice;
        while(true)
        {
            cin >> choice;

            if(choice <= i && choice >=1 )
            {
                if(enemies[choice - 1]->get_status())
                {
                    target = enemies[choice-1];
                    break;
                }
                else
                {
                    cout << "this character is dead... please choose another character" << endl;
                    
                }
            }
            else
            {
                cout << "invalid number... please choose (1 - " << i << ")" << endl;
            }
        }
    }
    else
    {
        vector <character*> enemies = get_neighborenemyzone(*active_character , enemy);
        int i = 1;
        for(; i <= enemies.size() ; i++)
        {
            cout << i << ". " << enemies[i-1]->get_name() << endl;
        }
        int choice;
        while(true)
        {
            cin >> choice;

            if(choice <= enemies.size() && choice >=1 )
            {
                if(enemies[choice - 1]->get_status())
                {
                    target = enemies[choice-1];
                    break;
                }
                else
                {
                    cout << "this character is dead... please choose another character" << endl;
                    
                }
            }
            else
            {
                cout << "invalid number... please choose (1 - " << enemies.size() << ")" << endl;
            }
        }
    }
}