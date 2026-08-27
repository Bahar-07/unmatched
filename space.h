#ifndef _SPACE
#define _SPACE
#include "game.h"
#include "ui.h"
#include "map.h"
#include <vector>
#include <string>

class game;
enum class zone
{
    blue,
    green,
    broun,
    ice,
    gray,
    purple,
    white
};
class space
{
    private:
        int id;
        std::vector<zone> zones;
        bool secret = false;
        std::vector<space*> secret_passagee;
        std::vector<space*> neighbors;
        std::string thisspace = "e";
        std::string fogg = "e";
        Vector2 ss;
        
    public:
        space(int , std::vector<zone> , bool, Vector2);
        int get_id();
        std::vector<zone>& get_zone();
        bool get_secret();
        void add_neighbor(space*);
        void add_secret_passage(space*);
        std::vector<space*> & get_neighbors();
        void show_space();
        void set_thisspacet(std::string);
        void set_thisspacef();
        std::string get_thisspace();
        int show_neighbors(map & , std::string);
        int show_neighbors_fog(map & , std::string);
        int show_neighbors_for_move(ui , map&);
        int prey_uponn();
        bool has_zone(zone);
        int move_invisible(game& ,ui , map &);
        void set_fogt(std::string);
        void set_fogf();
        Vector2 get();
};
#endif