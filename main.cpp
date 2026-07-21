#include "space.h"
#include "tui.h"
#include "map.h"
#include "game.h"
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



int main()
{   
    srand(time(NULL));
    tui t;
    int choice = t.main_menu();
    while(true)
    {
        if(choice == 0)
        {
            map g;
            cout << "Enter your name..." << endl << "player 1. " ;
            game player1;
            cout << "Enter your name..." << endl << "player 2. " ;
            game player2;
        
            player1.age(player2 , g , t);
                    
            
            
            if(player1.get_age() == "younger")
            {
                player1.choose_character(player2, g , t);
                player1.creat_deck();
                player2.creat_deck();
                player1.pick_card(player2);
                cout <<player1.get_name_player() << " start the game!!!" << endl;
                while(player1.alive() && player2.alive())
                {
                    player1.start_game(player2 , g ,t);
                    if(!player1.alive() || !player2.alive())
                        break;
                    player2.start_game(player1 , g , t);
                }
                if(player1.alive() && !player2.alive())
                {
                    cout << player1.get_name_player() << " WIN!!!" << endl;
                }
                else if(!player1.alive() && player2.alive())
                {
                    cout << player2.get_name_player() << " WIN!!!" << endl;
                }
            }
            else
            {
                player2.choose_character(player1, g , t);
                player1.creat_deck();
                player2.creat_deck();
                player2.pick_card(player1);
                cout << player2.get_name_player() << " start the game!!!" << endl;
                while(player1.alive() && player2.alive())
                {
                    player2.start_game(player1 , g , t);
                    if(!player1.alive() || !player2.alive())
                        break;
                    player1.start_game(player2 , g , t);
                }
                if(player1.alive() && !player2.alive())
                {
                    cout << player1.get_name_player() << " WIN!!!" << endl;
                }
                else if(!player1.alive() && player2.alive())
                {
                    cout << player2.get_name_player() << " WIN!!!" << endl;
                }
            }
            break;
        }
        if(choice == 1)
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
                    choice = t.main_menu();
                    break;
                }
                else
                {
                    cout << "Invalid number" << endl;
                }
            }
            
        
        }
        if(choice == 2)
        {
            cout << "Game Exited" << endl;
            exit(0);
        }
    }
}