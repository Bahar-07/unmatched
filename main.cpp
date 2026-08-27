#include "raylib.h"
#include "space.h"
#include "ui.h"
#include "map.h"
#include "game.h"
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <filesystem>
#include <vector>

using namespace std;
namespace fs = filesystem;
vector<string> get_save_files()
{
    vector<string> files;

    for (const auto& entry : fs::directory_iterator("."))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".txt" && entry.path().filename().string() != "CMakeCache.txt")
        {
            files.push_back(entry.path().filename().string());
        }
    }

    return files;
}
vector<string> load_name(string a , int f)
{
    if(f == 1)
    {
        string pname;
        string age;
        vector <string> n;
        ifstream file(a);
        if(!file)
        {
            cout << "file not found" << endl;
        }
        file >> pname >> age;
        n.push_back(pname);
        n.push_back(age);
        return n;
    }
    if(f == 2)
    {
        string pname;
        string age;
        string epname;
        string eage;
        vector <string> n;
        ifstream file(a);
        if(!file)
        {
            cout << "file not found" << endl;
        }
        file >> pname >> age >> epname >> eage;
        n.push_back(epname);
        n.push_back(eage);
        return n;

    }
    
}
int main()
{   
    
    InitWindow(1490, 930, "Unmatched");
    SetTargetFPS(60);
    int choice = -1;
    Rectangle start = {550, 250,300, 70};

    Rectangle load = {550, 350, 300, 70};

     Rectangle help = {550, 450, 300, 70};

    Rectangle exitt = {550, 550,300, 70 };

    while (!WindowShouldClose())
    {
        Vector2 mouse = GetMousePosition();

        bool mouses = CheckCollisionPointRec(mouse, start);

        bool mousel =CheckCollisionPointRec(mouse, load);

        bool mouseh =CheckCollisionPointRec(mouse, help);

        bool mousex = CheckCollisionPointRec(mouse, exitt);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (mouses)
            {
               choice = 0;
               break;
            }

            if (mousel)
            {
                choice = 1;
                break;
            }
            if (mouseh)
            {
                choice = 2;
                break;
            }
            if (mousex)
            {
                choice = 3;
                break;
            }
        }

        BeginDrawing();

        ClearBackground(Color{25, 25, 35, 255});


        DrawText("UNMATCHED",550,100, 50, WHITE);

        if (mouses)
        {
            DrawRectangleRec(start,Color{60, 60, 80, 255} );
        }
        else
        {
            DrawRectangleRec(start,BLACK);
        }

        DrawText("START GAME", 620,272, 25,WHITE);

        if (mousel)
        {
            DrawRectangleRec(load,Color{60, 60, 80, 255});
        }
        else
        {
            DrawRectangleRec(load,BLACK);
        }

        DrawText("LOAD GAME",625,372,25,WHITE );

        if (mouseh)
        {
            DrawRectangleRec(help,Color{60, 60, 80, 255});
        }
        else
        {
            DrawRectangleRec(help,BLACK);
        }

        DrawText("HELP",675,472,25,WHITE );

        if (mousex)
        {
            DrawRectangleRec(exitt, RED);
        }
        else
        {
            DrawRectangleRec(exitt,BLACK);
        }

        DrawText("EXIT", 675, 572,25, WHITE );

        EndDrawing();
    }

    srand(time(NULL));
    ui t;
        if(choice == 0)
        {
            map g;
            string n = t.get_text_input("Player1 please enter your name");
            game player1(n);
            string nn = t.get_text_input("Player2 please enter your name");
            game player2(nn);
       

            player1.age(player2 , g , t);
                    
            
            
            if(player1.get_age() == "younger")
            {
                player1.choose_character(player2, g , t);
                player2.choose_character(player1, g , t);
                player1.choose_location(player2, g , t);
                player2.choose_location(player1, g , t);
                player1.creat_deck();
                player2.creat_deck();
                player1.pick_card(player2);
                player2.pick_card(player1);
                t.showsomthing(player1.get_name_player() + " start the game!!!" , 3);
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
                    t.showsomthing(player1.get_name_player() + " WIN!!!" , 6);
                    cout << player1.get_name_player() << " WIN!!!" << endl;
                }
                else if(!player1.alive() && player2.alive())
                {
                    t.showsomthing(player2.get_name_player() + " WIN!!!" , 6);
                    cout << player2.get_name_player() << " WIN!!!" << endl;
                }
            }
            else
            {
                player2.choose_character(player2, g , t);
                player1.choose_character(player1, g , t);
                player2.choose_location(player2, g , t);
                player1.choose_location(player1, g , t);
                player2.creat_deck();
                player1.creat_deck();
                player2.pick_card(player2);
                player1.pick_card(player1);
                t.showsomthing(player2.get_name_player() + " start the game!!!" , 3);
                cout << player2.get_name_player() << " start the game!!!" << endl;
                while(player1.alive() && player2.alive())
                {
                   
                    //t.draw_game_screen( player1, player2, g);
                    player2.start_game(player1 , g , t);
                    if(!player1.alive() || !player2.alive())
                        break;
                    player1.start_game(player2 , g , t);
                }
                if(player1.alive() && !player2.alive())
                {
                     t.showsomthing(player1.get_name_player() + " WIN!!!" , 6);
                    cout << player1.get_name_player() << " WIN!!!" << endl;
                }
                else if(!player1.alive() && player2.alive())
                {
                     t.showsomthing(player2.get_name_player() + " WIN!!!" , 6);
                    cout << player2.get_name_player() << " WIN!!!" << endl;
                }
            }
            CloseWindow();
            
        }
        if(choice == 1)
        {
            vector<string> s = get_save_files();
            if(s.empty())
            {
                t.p("You dont have any save game");
                cout << "You dont have any save game" << endl;
                
                return 0;
            }
            else
            {
                ui r;
                int v = r.choose_acharacter("Choose a game" , s);
                vector <string> m = load_name(s[v] , 1);
                game player1(m[0] , m[1]);
                vector <string> l = load_name(s[v] , 2);
                game player2(l[0] , l[1]);
                map g;
                player1.load_game(s[v] , g , 1);
                player2.load_game(s[v] , g , 2);
                if(player1.get_age() == "younger")
                {
                
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

            }
        }
        if(choice == 2)
        {
            t.showhelp( "================ HELP ================ \n"
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
        if(choice == 3)
        {
            cout << "Game Exited" << endl;
            exit(0);
        }
    
}