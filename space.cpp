#include "space.h"
#include <iostream>
#include <iomanip>
using namespace std;


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
void space::show_space()
{
    int t = 0;
    
    cout << setw(10) << left <<get_id() << "[";
    for(zone z : get_zone())
    {
        if(z == zone::blue)
        {
            
            cout << "blue ";
            t+=1;
        }
        if(z == zone::white)
        {
            
            cout << "white ";
            t+=1;
        }
        if(z == zone::purple)
        {
            
            cout << "purple ";
            t+=1;
        }
        if(z == zone::broun)
        {
            
            cout << "broun ";
            t+=1;
        }
        if(z == zone::gray)
        {
            
            cout << "gray ";
            t+=1;
        }
        if(z == zone::green)
        {
            
            cout << "green ";
            t+=1;
        }
        if(z == zone::ice)
        {
            
            cout << "ice ";
            t+=1;
        }
    }
    
    if(t ==1)
    {
        cout << setw(30) << "]";
    }
     if(t ==2)
    {
        cout << setw(25) << "]";
    }
    if(t ==3 )
    {
        cout << setw(20) << "]";
    }
    for(space* n : get_neighbors())
    {
        
        cout << n->get_id() << " " ;
    }
    t =0;
    if(get_secret())
    {
        
        cout << right <<setw(45) <<"secret passage " ;
        t +=1;
    }
    if(thisspace != "e")
    {
        if(thisspace == "Dracula")
        {
            if(t == 1)
            {
                
                cout <<  right << setw(30) <<"Dracula" << endl;
            }
            if(t == 0)
            {
                
                cout <<  right << setw(75) <<"Dracula" << endl;
            }
        }
        if(thisspace == "sister 1")
        {
            if(t == 1)
            {
                
                cout <<  right << setw(30) <<"sister 1" << endl;
            }
            if(t == 0)
            {
                
                cout <<  right << setw(75) <<"sister 1" << endl;
            }
        }
        if(thisspace == "sister 2")
        {
            if(t == 1)
            {
                
                cout <<  right << setw(30) <<"sister 2" << endl;
            }
            if(t == 0)
            {
                
                cout <<  right << setw(75) <<"sister 2" << endl;
            }
        }
        if(thisspace == "sister 3")
        {
            if(t == 1)
            {
                
                cout <<  right << setw(30) <<"sister 3" << endl;
            }
            if(t == 0)
            {
                
                cout <<  right << setw(75) <<"sister 3" << endl;
            }
        }
        if(thisspace == "Sherlock Holmes")
        {
            if(t == 1)
            {
                
                cout << right << setw(30) <<"Sherlock Holmes" << endl;
            }
            if(t == 0)
            {
                
                cout <<  right << setw(75) <<"Sherlock Holmes" << endl;
            }
        }
        if(thisspace == "Dr.Watson")
        {
            if(t == 1)
            {
                
                cout <<  right << setw(30) <<"Dr.Watson" << endl;
            }
            if(t == 0)
            {
                
                cout <<  right << setw(75) <<"Dr.Watson" << endl;
            }
        }
    }
        
    else
    {
        
        cout << endl;
    }
}
void space::set_thisspacet(string b)
{
    thisspace = b;
}
void space::set_thisspacef()
{
    thisspace = "e";
}

void space::show_neighbors()
{
    for(space *s:neighbors)
    {
        cout << s->get_id() <<endl;
    }
    
}