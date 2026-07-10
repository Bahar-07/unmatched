
#include "space.h"
#include "map.h"
#include "game.h"
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int welcome()
{
    int a;
    
    cout << "                    main menu                    " <<endl;
    cout <<"1 . Play" <<endl << "2 . Help" << endl << "3 . Exit" << endl;
    cin >> a;
    if(a > 3 || a < 1)
    {
        throw invalid_argument("please choose 1 to 3");
    }
    return a;
}

int main()
{   
    srand(time(NULL));
    cout << "                    UNMATCHED                    " <<endl;
    int test;
    while(true)
    {
        try
        {
            test = welcome();
            break;
        }
        catch(invalid_argument & e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
    if( test == 1)
    {
        map g;
        cout << "Enter your name..." << endl << "player 1. " ;
        game player1;
        cout << "Enter your name..." << endl << "player 2. " ;
        game player2;
        while(true)
        {
            try
            {
                player1.age(player2 , g);
                break;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }
        player1.creat_deck();
        player2.creat_deck();
        if(player1.get_age() == "younger")
        {
            player1.pick_card(player2);
            cout <<player1.get_name_player() << " start the game!!!" << endl;
            while(player1.alive() && player2.alive())
            {
                player1.start_game(player2 , g);
                if(!player1.alive() || !player2.alive())
                    break;
                player2.start_game(player1 , g);
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
            player2.pick_card(player1);
            cout << player2.get_name_player() << " start the game!!!" << endl;
             while(player1.alive() && player2.alive())
            {
                player2.start_game(player1 , g);
                if(!player1.alive() || !player2.alive())
                    break;
                player1.start_game(player2 , g);
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
    }
    
    if(test == 2)
    {
        while(true)
        {
            try
            {
                test = welcome();
                break;
            }
            catch(invalid_argument & e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
    if(test == 3)
    {
        cout << "Game Exited" << endl;
        exit(0);
    }
    return 0;
}