#ifndef _SPACE
#define _SPACE
#include <vector>

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
        bool secret;
        std::vector<space*> neighbors;
    public:
        space(int , std::vector<zone> , bool);
        int get_id();
        std::vector<zone>& get_zone();
        bool get_secret();
        void add_neighbor(space*);
        std::vector<space*> & get_neighbors();
};
#endif