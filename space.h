#ifndef _SPACE
#define _SPACE
#include <vector>
#include <string>

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
        std::vector<space*> neighbors;
        std::string thisspace = "e";
        
    public:
        //space();
        space(int , std::vector<zone> , bool);
        int get_id();
        std::vector<zone>& get_zone();
        bool get_secret();
        void add_neighbor(space*);
        std::vector<space*> & get_neighbors();
        void show_space();
        void set_thisspacet(std::string);
        void set_thisspacef();
        
        void show_neighbors();
};
#endif