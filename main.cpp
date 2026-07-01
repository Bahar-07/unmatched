#include <iostream>
#include "space.h"
#include "map.h"
#include "game.h"
#include <stdlib.h>
using namespace std;

int welcome()
{
    int a;
    
    cout << "          main menu          " <<endl;
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
    cout << "          UNMATCHED          " <<endl;
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
        cout << "Enter your name..." << endl << "player 1. " ;
        game player1;
        cout << "Enter your name..." << endl << "player 2. " ;
        game player2;
        while(true)
        {
            try
            {
                player1.age(player2);
                break;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
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
        exit;
    }
    return 0;
}