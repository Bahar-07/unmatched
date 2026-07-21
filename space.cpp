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
void space::add_secret_passage(space* secrett)
{
    secret_passagee.push_back(secrett);
}
std::vector<space*> & space::get_neighbors()
{
    return neighbors;
}
bool space::has_zone(zone zoneee)
{
    for(zone z:zones)
    {
        if(z == zoneee)
        {
            return true;
        }
    }
    return false;
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
   /* cout << "neighbors: " ;
    for(space* n : get_neighbors())
    {
        
        cout << n->get_id() << " " ;
    }*/
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
std::string space::get_thisspace()
{
    return thisspace;
}
int space::show_neighbors()
{
int ch;
int counter = 0;
std::vector<space*> available; 
    for(space *s:neighbors)
    {
        if(s->get_thisspace() == "e")
        {
            counter++;
            available.push_back(s);
            cout << counter << ". " << s->get_id() <<endl;
        }
    }
    cin >> ch;
    if(ch > counter || ch <= 0)
    {
        throw invalid_argument("invalid number");
    }
    return available[ch - 1]->get_id();
}
int space::show_neighbors_for_move()
{
    int ch;
    int counter = 0;
    std::vector<space*> available; 
    for(space *s:neighbors)
    {
        if(s->get_thisspace() == "e")
        {
            counter++;
            available.push_back(s);
            cout << counter << ". " << s->get_id() <<endl;
        }
    }
    if(get_secret())
    {
        for(auto *a:secret_passagee)
        {
            if(a->get_thisspace() == "e")
            {
                counter++;
                available.push_back(a);
                cout << counter << ". " << a->get_id() <<endl;
            }
        }
    }
    if(!available.empty())
    {
        cin >> ch;
        if(ch > counter || ch <= 0)
        {
            throw invalid_argument("invalid number");
        }
        return available[ch - 1]->get_id();
    }
    else
    {
        cout << " you cant move ...    there isnt any empty space " << endl;
        return 400;
    }
}
bool space::show_full_neighbors()
{
    int e = 0;
    for(space *s:neighbors)
    {
        if(s->get_thisspace() != "e")
        {
            cout << s->get_id() << ". " << s->get_thisspace() << endl ;
           e++; 
        }
    }
    if(e != 0)
    {
        return true;
    }
    return false;
}

int space::prey_uponn()
{
    int sh = 0;
    int dr = 0; 
    for(space *s:neighbors)
    {
        if(s->get_thisspace() == "Sherlock Holmes")
        {
            sh++;
        }
        if(s->get_thisspace() == "Dr.Watson")
        {
            dr++;
        } 
        
    }
    if( dr == 1 && sh == 1)
    {
        return  3;
    }
    if(sh == 1)
    {
        return 2;
    }
    if(dr == 1)
    {
        return 1;
    }
    if(dr == 0 && sh == 0)
    {
        return 0; 
    }
}