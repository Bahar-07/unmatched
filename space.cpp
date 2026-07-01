#include "space.h"
#include <iostream>

space::space(int id , std::vector<zone> zones , bool secret)
{
    this->id = id;
    this->zones = zones;
    this->secret = secret;
}
int space::get_id()
{
    return id;
}
std::vector<zone>& space::get_zone()
{
    return zones;
}
bool space::get_secret()
{
    return secret;
}
void space::add_neighbor(space* neighbor)
{
    neighbors.push_back(neighbor);
}
std::vector<space*> & space::get_neighbors()
{
    return neighbors;
}