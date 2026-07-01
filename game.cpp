#include "game.h"
#include <iostream>
using namespace std;

game::game()
{
    string player;
    cin >> player;
    name = player;
}
void game::age(game enemy)
{
    cout << "Who is younger?    1 . " << name << "    2 . " << enemy.name << endl;
    int a;
    cin >> a;
    younger = a;
    enemy.younger =a;
    if(a > 2 || a < 1)
    {
        throw invalid_argument("please enter 1 or 2");
    }
}