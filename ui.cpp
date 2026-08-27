#include "raylib.h"
#include "space.h"
#include "ui.h"
#include "game.h"
#include "map.h"
#include "character.h"
#include "card.h"
#include <iostream>
using namespace std;

int ui::action_menu()
{
        ClearBackground(Color{25, 25, 35, 255});

        DrawText("CHOOSE ACTION",665,815, 25, WHITE);

        Rectangle maneuver = {50, 850, 170, 40};
        Rectangle scheme   = {250, 850, 170, 40};
        Rectangle attack   = {450, 850, 170, 40};
        Rectangle hand   = {650, 850, 170, 40};
        Rectangle my   = {850, 850, 170, 40};
        Rectangle enemy   = {1050, 850, 170, 40};
        Rectangle save   = {1250, 850, 170, 40};
        if (button(maneuver, "Maneuver"))
        {
            
            return 0;
        }

        if (button(scheme, "Scheme"))
        {
            
            return 1;
        }

        if (button(attack, "Attack"))
        {
            
            return 2;
        }
        if (button(hand, "Show hand"))
        {
            
            return 3;
        }
        if (button(my, "Your status"))
        {
            
            return 4;
        }
        if (button(enemy, "Enemy status"))
        {
            
            return 5;
        }
        if (button(save , "Save and exit"))
        {
            
            return 6;
        }
        
    

    return -1;

}
int ui::agee(std::string a , std::string b)
{
    int selected = -1;

    Rectangle aa = {570, 220, 300, 60};
    Rectangle bb = {570, 300, 300, 60};
    Rectangle same = {570, 380, 300, 60};

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(Color{25, 25, 35, 255});

        DrawText("WHO IS YOUNGER?",550,100,35, WHITE);
        
            if (button(aa, a.c_str()))
            {
                selected = 0;
                break;
            }

            if (button(bb, b.c_str()))
            {
                selected = 1;
                break;
            }

            if (button(same,"same age"))
            {
                selected = 2;
                break;
            }
        

       


        EndDrawing();
    }
    if (selected != -1)
        {
            while (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                BeginDrawing();
                ClearBackground(Color{25 ,25 ,35 ,255});
                EndDrawing();
            }

            return selected;
        }
    

    return -1;
}
void ui::showsomthing(std::string text, int s)
{
    double time = GetTime();

    while (GetTime() - time < s)
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText(text.c_str(),500,300,40,WHITE);

        EndDrawing();
    }
}
void ui::showhelp(std::string text, int s)
{
    double time = GetTime();

    while (GetTime() - time < s)
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText(text.c_str(),400,100,23,WHITE);

        EndDrawing();
    }
}
int ui::choose_character(game p)
{
    int r;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(Color{25, 25, 35, 255});
        DrawText(TextFormat("%s - CHOOSE YOUR HERO" ,  p.get_name_player().c_str()), 550,100,35, WHITE);
        Rectangle dracula = {300, 268,250, 65};
        Rectangle sherlock = {620, 268,250, 65};
        Rectangle invisible = {940, 268,250, 65};
        if (button(dracula, "Dracula"))
        {
            r = 0;
        }

        if (button(sherlock, "Sherlock Holmes"))
        {
            r = 1;
        }

        if (button(invisible, "Invisible Man"))
        { 
            r = 2;
        }
       
        EndDrawing();
        if (r != -1)
        {
            return r;
        }
    }
    return -1;
  
}
int ui::choose_space(map& g , std::string title , std::vector<int> entriess)
{
    int selected = -1;
    Texture2D map = LoadTexture("../a/map.png");
    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(Color{25 , 25 , 35 , 255});

        DrawText( title.c_str(),100,50,30, WHITE);

        for (int i = 0; i < entriess.size(); i++)
        {
            Rectangle bb={150.0f + (i / 5) * 90.0f,100.0f + (i % 5) * 130.0f,100,60};

            string text = to_string(entriess[i]);
            if (button(bb, text.c_str()))
            {
                selected = i;
            }
        }
        Rectangle s = {0, 0,(float)map.width, (float)map.height};
        Rectangle d= {320, 95, 1120, 680};
        DrawTexturePro( map,s, d,Vector2{0, 0}, 0, WHITE );
        EndDrawing();

        if (selected != -1)
            break;
    }
    if (selected != -1)
        {
            while (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                BeginDrawing();
                ClearBackground(Color{25 ,25 ,35 ,255});
                EndDrawing();
            }

            return selected;
        }
        UnloadTexture(map);
    return -1;
   

}
int ui::yesorno(std::string title)
{
    int selected = -1;

    Rectangle yes = {250, 250, 300, 60};
    Rectangle no  = {250, 330, 300, 60};

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(Color{25 ,25 ,35 ,255});

        DrawText(title.c_str(), 200, 120, 30, WHITE);
        if (button(yes , "Yes"))
        {
            selected = 0;
            break;
        }

        if (button(no , "No"))
        {
            selected = 1;
            break;
        }
        EndDrawing();
    }
    if (selected != -1)
        {
            while (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                BeginDrawing();
                ClearBackground(Color{25 ,25 ,35 ,255});
                EndDrawing();
            }

            return selected;
        }
    

    return -1;
    

}
int ui::choose_acharacter(std::string title , std::vector<std::string> entriess)
{
    int selected = -1;

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(Color{25 ,25 ,35 ,255});

        DrawText(title.c_str(),100, 50,30, WHITE);

        for (int i = 0; i < entriess.size(); i++)
        {
            Rectangle bb ={100.0f + (i % 3) * 230.0f,150.0f + (i / 3) * 100.0f, 200,70};
            string text = entriess[i];
            if (button(bb , text.c_str()))
            {
                selected = i;
            }
        }

        EndDrawing();

        if (selected != -1)
            break;
    }
    if (selected != -1)
        {
            while (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                BeginDrawing();
                ClearBackground(Color{25 ,25 ,35 ,255});
                EndDrawing();
            }

            return selected;
        }
    

    return -1;
   

}
int ui::choose_aacharacter(std::string title,std::vector<character*> entriess)
{
    int selected = -1;

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(Color{25 ,25 ,35 ,255});

        DrawText(title.c_str(),100, 50,30,WHITE);

        for (int i = 0; i < entriess.size(); i++)
        {
            Rectangle bb ={100.0f + (i % 3) * 230.0f,150.0f + (i / 3) * 100.0f,200,70 };
            string text = entriess[i]->get_name();
            if (button(bb , text.c_str()))
            {
                selected = i;
            }
        }

        EndDrawing();

        if (selected != -1)
            break;
    }
    if (selected != -1)
        {
            while (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                BeginDrawing();
                ClearBackground(Color{25 ,25 ,35 ,255});
                EndDrawing();
            }

            return selected;
        }
    

    return -1;
   

}
string ui::get_text_input(string title)
{
    string text = "";

    while (IsKeyDown(KEY_ENTER))
    {
        BeginDrawing();
        ClearBackground(Color{25 ,25 ,35 ,255});
        EndDrawing();
    }

    while (!WindowShouldClose())
    {
        int k = GetCharPressed();

        while (k > 0)
        {
            if (k >= 32 && k <= 125)
            {
                text += static_cast<char>(k);
            }

            k = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE) && !text.empty())
        {
            text.pop_back();
        }

        if (IsKeyPressed(KEY_ENTER) && !text.empty())
        {
            return text;
        }

        BeginDrawing();

        ClearBackground(Color{25, 25, 35, 255});

        DrawText(title.c_str(),200,150,30, WHITE);
        DrawRectangle(200,250,400,60,LIGHTGRAY);
        DrawText( text.c_str(),220,268,25, BLACK);
        DrawText("Press ENTER to continue",270, 350,20,WHITE);

        EndDrawing();
    }

    return text;

}
bool ui::button(Rectangle rect,const char* text)
{
    Vector2 mouse = GetMousePosition();

    bool h = CheckCollisionPointRec(mouse, rect);

    DrawRectangle(rect.x, rect.y,rect.width,rect.height,h ? Color{90, 90, 120, 255} : Color{60, 60, 80, 255});

    DrawRectangleLines( rect.x,rect.y, rect.width, rect.height, WHITE);
    int textWidth = MeasureText(text, 18);
    DrawText( text, rect.x + (rect.width - textWidth) / 2, rect.y + 10,18,WHITE);
    return h && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}
int ui::draw_game_screen(game& player1, game& player2, map& g)
{
    Texture2D map = LoadTexture("../a/map.png");
     Texture2D dracula = LoadTexture("../a/dracula.png");
      Texture2D s1 = LoadTexture("../a/sis1.png");
       Texture2D s2 = LoadTexture("../a/sis2.png");
        Texture2D s3 = LoadTexture("../a/sis3.png");
         Texture2D sherlock = LoadTexture("../a/sherlockTran.png");
          Texture2D dr = LoadTexture("../a/drwatson.png");
           Texture2D man = LoadTexture("../a/tranInv.png");
            Texture2D fog = LoadTexture("../a/fog.png");
    bool s = false;
    bool es = false;
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground( Color{25, 25, 35, 255});
        DrawText(player2.get_hero().get_name().c_str(),20, 15, 50, WHITE);
        DrawRectangle(1180, 265,280, 160,Color{45, 45, 60, 255});

        DrawRectangleLines( 1180, 265, 280, 160, WHITE);

        DrawText(player1.get_name_player().c_str(),1200,285,25, WHITE);

        DrawText(player1.get_hero().get_name().c_str(),1200, 325, 22, WHITE);
        DrawText(TextFormat("HP: %d", player1.get_hero().get_hp()),1200,365, 22, WHITE);

        DrawRectangle( 1180, 85, 280, 160,Color{45, 45, 60, 255});

        DrawRectangleLines(1180, 85,280, 160, WHITE);

        DrawText( player2.get_name_player().c_str(), 1200, 105, 25, WHITE);

        DrawText( player2.get_hero().get_name().c_str(), 1200, 145, 22, WHITE);
        DrawText( TextFormat("HP: %d", player2.get_hero().get_hp()), 1200, 185, 22, WHITE);
        DrawRectangle( 20, 85, 1140, 700,Color{35, 35, 45, 255});

        DrawRectangleLines( 20, 85, 1140, 700, WHITE);
        Rectangle ss = {0,0,(float)map.width,(float)map.height};
        Rectangle d = {30,  95, 1120, 680 };
        DrawTexturePro(map, ss,d, Vector2{0, 0}, 0, WHITE);
        DrawText("MAP",585, 97, 30, WHITE);
        DrawRectangle( 20, 800, 1450, 110,Color{40, 40, 55, 255});

        DrawRectangleLines(20, 800, 1450, 110, WHITE);
        Texture2D ht;
        Texture2D st1;
        Texture2D st2;
        Texture2D st3;
        Vector2 p1 = player1.get_hero().get_location()->get();
        Vector2 p2 = player2.get_hero().get_location()->get();
        Vector2 ss1;
        Vector2 ss2;
        Vector2 ss3;
        Vector2 ess1;
        Vector2 ess2;
        Vector2 ess3;
        if(player1.get_hero().get_name() == "Dracula")
        {
            ht = dracula;
            if(player1.get_sidekicks()[0].get_status())
            {
                ss1 = player1.get_sidekicks()[0].get_location()->get();
                st1 = s1;
                DrawTextureEx(st1,{ss1.x - st1.width * 0.5f / 2 ,ss1.y - st1.height * 0.5f / 2} , 0.0f, 0.5f , WHITE);
            }
            if(player1.get_sidekicks()[1].get_status())
            {
                ss2 = player1.get_sidekicks()[1].get_location()->get();
                st2 = s2;
                DrawTextureEx(st2,{ss2.x - st2.width * 0.5f / 2 ,ss2.y - st2.height * 0.5f / 2} , 0.0f, 0.5f , WHITE);
            }
            if(player1.get_sidekicks()[2].get_status())
            {
                ss3 = player1.get_sidekicks()[2].get_location()->get();
                st3 = s3;
                DrawTextureEx(st3,{ss3.x - st3.width * 0.5f / 2 ,ss3.y - st3.height * 0.5f / 2} , 0.0f, 0.5f , WHITE);
            }
        }
        if(player1.get_hero().get_name() == "Sherlock Holmes")
        {
            ht = sherlock;
            if(player1.get_sidekicks()[0].get_status())
            {
                ss1 = player1.get_sidekicks()[0].get_location()->get();
                st1 = dr;
                DrawTextureEx(st1,{ss1.x - st1.width * 0.2f / 2 ,ss1.y - st1.height * 0.2f / 2} , 0.0f, 0.2f , WHITE);
            }
        }
        if(player1.get_hero().get_name() == "Invisible Man")
        {
            st1 = fog;
            st2 = fog;
            st3 = fog;
            ss1 = player1.get_fog()[0]->get();
            ss2 = player1.get_fog()[1]->get();
            ss3 = player1.get_fog()[2]->get();
            ht = man;
            DrawTextureEx(st1,{ss1.x - st1.width * 0.2f / 2 ,ss1.y - st1.height * 0.2f / 2} , 0.0f, 0.2f , WHITE);
            DrawTextureEx(st2,{ss2.x - st2.width * 0.2f / 2 ,ss2.y - st2.height * 0.2f / 2} , 0.0f, 0.2f , WHITE);
            DrawTextureEx(st3,{ss3.x - st3.width * 0.2f / 2 ,ss3.y - st3.height * 0.2f / 2} , 0.0f, 0.2f , WHITE);
        }
        DrawTextureEx(ht,{p1.x - ht.width * 0.2f / 2 ,p1.y - ht.height * 0.2f / 2} , 0.0f, 0.2f , WHITE);
        if(player2.get_hero().get_name() == "Dracula")
        {
            ht = dracula;
            if(player2.get_sidekicks()[0].get_status())
            {
                ess1 = player2.get_sidekicks()[0].get_location()->get();
                st1 = s1;
                DrawTextureEx(st1,{ess1.x - st1.width * 0.5f / 2 ,ess1.y -st1.height * 0.5f / 2} , 0.0f, 0.5f , WHITE);
            }
            if(player2.get_sidekicks()[1].get_status())
            {
                ess2 = player2.get_sidekicks()[1].get_location()->get();
                st2 = s2;
                DrawTextureEx(st2,{ess2.x - st2.width * 0.5f / 2 ,ess2.y - st2.height * 0.5f / 2} , 0.0f, 0.5f , WHITE);
            }
            if(player2.get_sidekicks()[2].get_status())
            {
                ess3 = player2.get_sidekicks()[2].get_location()->get();
                st3 = s3;
                DrawTextureEx(st3,{ess3.x - st3.width * 0.5f / 2 ,ess3.y - st3.height * 0.5f / 2} , 0.0f, 0.5f , WHITE);
            }
        }
        if(player2.get_hero().get_name() == "Sherlock Holmes")
        {
            ht = sherlock;
            if(player2.get_sidekicks()[0].get_status())
            {
                ess1 = player2.get_sidekicks()[0].get_location()->get();
                st1 = dr;
                DrawTextureEx(st1,{ess1.x - st1.width * 0.2f / 2 ,ess1.y - st1.height * 0.2f / 2} , 0.0f, 0.2f , WHITE);
            }
        }
        if(player2.get_hero().get_name() == "Invisible Man")
        {
            st1 = fog;
            st2 = fog;
            st3 = fog;
            ess1 = player2.get_fog()[0]->get();
            ess2 = player2.get_fog()[1]->get();
            ess3 = player2.get_fog()[2]->get();
            ht = man;
            DrawTextureEx(st1,{ess1.x - st1.width * 0.2f / 2 ,ess1.y - st1.height * 0.2f / 2} , 0.0f, 0.2f , WHITE);
            DrawTextureEx(st2,{ess2.x - st2.width * 0.2f / 2 ,ess2.y - st2.height * 0.2f / 2} , 0.0f, 0.2f , WHITE);
            DrawTextureEx(st3,{ess3.x - st3.width * 0.2f / 2 ,ess3.y - st3.height * 0.2f / 2} , 0.0f, 0.2f , WHITE);
            
        }
        DrawTextureEx(ht,{p2.x - ht.width * 0.2f / 2 ,p2.y - ht.height * 0.2f / 2} , 0.0f, 0.2f , WHITE);
        int action = action_menu();
        if(action == 4)
        {
            s = true;
        }
        if(s)
        {
            if(draw_status_window(player2, false))
            {
                s = false;
            }
        }
        if(action == 5)
        {
            es = true;
        }
        if(es)
        {
            if(draw_status_window(player1, true))
            {
                es = false;
            }
        }
        EndDrawing();
        
    
        if(action != -1 && action != 4 && action != 5)
        {
            UnloadTexture(map);
            UnloadTexture(dracula);
            UnloadTexture(sherlock);
            UnloadTexture(fog);
            UnloadTexture(s1);
            UnloadTexture(s2);
            UnloadTexture(s3);
            UnloadTexture(dr);
            return action;
        }
        
    }
    UnloadTexture(map);
    UnloadTexture(dracula);
    UnloadTexture(sherlock);
    UnloadTexture(fog);
    UnloadTexture(s1);
    UnloadTexture(s2);
    UnloadTexture(s3);
    UnloadTexture(dr);
    return -1;
}

bool ui::draw_status_window(game& player, bool enemy)
{
    DrawRectangle(450, 250,570, 380,Color{35, 35, 50, 255});

    DrawRectangleLines(450, 250, 570, 380, WHITE);

    Rectangle c = {(float)(450 + 570 - 45),(float)(250 + 15),30,30};

    DrawRectangle(c.x,c.y,c.width,c.height,RED);

    DrawText("X",c.x + 8,c.y + 4,20, WHITE);

    DrawText( enemy ? "ENEMY STATUS" : "YOUR STATUS", 480, 275,28, WHITE);

    DrawText(player.get_name_player().c_str(), 480, 330,22, WHITE);

    DrawText(player.get_hero().get_name().c_str(), 480, 375, 22, WHITE);

    DrawText(TextFormat("HP: %d",player.get_hero().get_hp()), 480, 420, 22, WHITE);

    DrawText(TextFormat("Hand: %d", player.get_nhand()), 480,465, 22, WHITE);

    DrawText(TextFormat("Deck: %d",player.get_ndeck()), 480,505,22, WHITE);

    if(player.get_hero().get_name() != "Invisible Man")
    {
        if(player.get_hero().get_name() == "Dracula")
        {
            DrawText(TextFormat("sister1(hp): %d",player.get_sidekicks()[0].get_hp()), 480,550,22, WHITE);
            DrawText(TextFormat("sister2(hp): %d",player.get_sidekicks()[1].get_hp()), 670,550,22, WHITE);
            DrawText(TextFormat("sister3(hp): %d",player.get_sidekicks()[2].get_hp()), 860,550,22, WHITE);
        }
        if(player.get_hero().get_name() == "Sherlock Holmes")
        {
            DrawText(TextFormat("Dr.Watson(hp): %d",player.get_sidekicks()[0].get_hp()), 480,550,22, WHITE);
        }
    }

    return CheckCollisionPointRec(GetMousePosition(),c) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}
void ui::p(std::string a)
{
        int x = 450;
        int y = 365;
        int width = 570;
        int height = 150;
        bool close = false;
    while(!close)
    {
        BeginDrawing();
        DrawRectangle(x, y,width, height,Color{35, 35, 50, 255});

        DrawRectangleLines(x, y, width, height,WHITE);

        Rectangle closee = {(float)(x + width - 45), (float)(y + 15), 30,30};

        DrawRectangle(closee.x,closee.y,
            closee.width,
            closee.height,
            RED
        );

        DrawText(
            "X",
            closee.x + 8,
            closee.y + 4,
            20,
            WHITE
        );

        DrawText(
            a.c_str(),
            x + 30,
            y + 55,
            20,
            WHITE
        );
        if (CheckCollisionPointRec(GetMousePosition(),closee) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            close = true;
        }
        EndDrawing();
    }
}
int ui::choose_card(std::vector<card>& cards)
{
    std::vector<Texture2D> textures;

    for (card& card : cards)
    {
        std::string path ="../a/" + card.get_image_path();

        Texture2D texture = LoadTexture(path.c_str());

        textures.push_back(texture);
    }

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(Color{25, 25, 35, 255});

        DrawText("CHOOSE A CARD",550, 80, 30, WHITE);

        Vector2 mouse = GetMousePosition();

        for (int i = 0; i < textures.size(); i++)
        {
            Rectangle cardr = { 100.0f + i * 220.0f, 200.0f, 180.0f, 260.0f};

            Rectangle source = {0,0,(float)textures[i].width,(float)textures[i].height};

            DrawTexturePro(textures[i], source,cardr,Vector2{0, 0}, 0, WHITE);

            bool h =CheckCollisionPointRec(mouse,cardr);

            if (h)
            {
                DrawRectangleLinesEx(cardr, 3, YELLOW);

                if (IsMouseButtonPressed( MOUSE_BUTTON_LEFT))
                {
                    for (Texture2D& texture : textures)
                    {
                        UnloadTexture(texture);
                    }

                    EndDrawing();

                    return i;
                }
            }
        }

        EndDrawing();
    }
    for (Texture2D& texture : textures)
    {
        UnloadTexture(texture);
    }

    return -1;

}
bool ui::show_card(std::vector<card>& cards)
{
    std::vector<Texture2D> textures;

    for (card& card : cards)
    {
        std::string path ="../a/" + card.get_image_path();

        Texture2D texture = LoadTexture(path.c_str());

        textures.push_back(texture);
    }

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(Color{25, 25, 35, 255});

        DrawText( "CARDS", 600,40,35, WHITE);

        for (int i = 0; i < textures.size(); i++)
        {
            Rectangle cardr = {100.0f + i * 220.0f,150.0f,180.0f, 260.0f};

            Rectangle source = {0,0,(float)textures[i].width,(float)textures[i].height};

            DrawTexturePro( textures[i], source, cardr, Vector2{0, 0}, 0, WHITE);
        }

        Rectangle back = { 650,830,190, 55};

        if (button(back, "BACK"))
        {
            for (Texture2D& texture : textures)
            {
                UnloadTexture(texture);
            }

            EndDrawing();

            return true;
        }

        EndDrawing();
    }

    for (Texture2D& texture : textures)
    {
        UnloadTexture(texture);
    }

    return true;

}