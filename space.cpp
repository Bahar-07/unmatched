#include "space.h"
#include <iostream>
#include <iomanip>
using namespace std;


space::space(int id , std::vector<zone> zones , bool secret, Vector2 s)
{
    this->id = id;
    this->zones = zones;
    this->secret = secret;
    ss = s;
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
    cout << "neighbors: " ;
    for(space* n : get_neighbors())
    {
        
        cout << n->get_id() << " " ;
    }
    t =0;
    if(get_secret())
    {
        
        cout << right <<setw(45) <<"secret passage ";
        t +=1;
    }
    if(thisspace != "e")
    {
        if(thisspace == "Dracula")
        {
            if(t == 1)
            {
                
                cout <<  right << setw(30) <<"Dracula" << endl ;
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
                
                cout <<  right << setw(75) <<"sister 3"<< endl ;
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
                
                cout <<  right << setw(75) <<"Sherlock Holmes" << endl ;
            }
        }
        if(thisspace == "Dr.Watson")
        {
            if(t == 1)
            {
                
                cout <<  right << setw(30) <<"Dr.Watson" << endl ;
            }
            if(t == 0)
            {
                
                cout <<  right << setw(75) <<"Dr.Watson" << endl ;
            }
        }
        if(thisspace == "Invisible Man")
        {
            if(t == 1)
            {
                
                cout <<  right << setw(30) <<"Invisisble Man" << endl;
            }
            if(t == 0)
            {
                
                cout <<  right << setw(75) <<"Invisisble Man" << endl;
            }
        }
        if(fogg == "fog")
        {
            cout <<  right << setw(30) <<"fog" << endl;
        }
    }
    else
    {
        if(fogg == "fog")
        {
            cout <<  right << setw(30) <<"fog" << endl;
        }
        else
        {
            cout << endl;
        }
        
    }
}
void space::set_fogt(string b)
{
    fogg = b;
}
void space::set_fogf()
{
    fogg = "e";
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
int space::show_neighbors( map& g , std::string a)
{
    ui e;
    int ch;
    int counter = 0;
    std::vector<space*> available; 
    std::vector<int> aaa;
    for(space *s:neighbors)
    {
        if(s->get_thisspace() == "e")
        {
            counter++;
            available.push_back(s);
            aaa.push_back(s->get_id());
            cout << counter << ". " << s->get_id() <<endl;
        }
    }
     if(!available.empty())
    {
        ch= e.choose_space(g ,a, aaa);
        return available[ch]->get_id();
    }
    else
    {
        e.p("you cant move...there isnt any empty space");
        cout << " you cant move ...    there isnt any empty space " << endl;
        return 400;
    }
}
int space::show_neighbors_fog( map& g , std::string a)
{
    ui e;
    int ch;
    int counter = 0;
    std::vector<space*> available; 
    std::vector<int> aaa;
    for(space *s:neighbors)
    {
        if(s->fogg == "e")
        {
            counter++;
            available.push_back(s);
            aaa.push_back(s->get_id());
            cout << counter << ". " << s->get_id() <<endl;
        }
    }
     if(!available.empty())
    {
        set_fogf();
        ch= e.choose_space(g ,a, aaa);
        available[ch]->set_fogt("fog");
        return available[ch]->get_id();
    }
    else
    {
        e.p("you cant move...there isnt any empty space");
        cout << " you cant move ...    there isnt any empty space " << endl;
        return 400;
    }
}
int space::show_neighbors_for_move(ui t , map & g)
{
    int ch;
    int counter = 0;
    std::vector<space*> available; 
    std::vector<int> aaa;
    for(space *s:neighbors)
    {
        if(s->get_thisspace() == "e")
        {
            counter++;
            available.push_back(s);
            aaa.push_back(s->get_id());
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
                aaa.push_back(a->get_id());
                cout << counter << ". " << a->get_id() <<endl;
            }
        }
    }
    if(!available.empty())
    {
        ch = t.choose_space(g , "where do you want to go?" , aaa);
        //cin >> ch;
        return available[ch]->get_id();
    }
    else
    {
        t.p( " you cant move...there isnt any empty space ");
        cout << " you cant move ...    there isnt any empty space " << endl;
        return 400;
    }
}
int space::move_invisible(game& p , ui t , map & g)
{
    int ch;
    int counter = 0;
    std::vector<space*> available; 
    std::vector<int> aaa;
    for(space *s:neighbors)
    {
        if(s->get_thisspace() == "e")
        {
            counter++;
            available.push_back(s);
            aaa.push_back(s->get_id());
            cout << counter << ". " << s->get_id() <<endl;
        }
    }
    if(get_secret())
    {
        for(auto *a:secret_passagee)
        {
            if(a->get_thisspace() == "e" || a->get_thisspace() == "fog")
            {
                counter++;
                available.push_back(a);
                aaa.push_back(a->get_id());
                cout << counter << ". " << a->get_id() <<endl;
            }
        }
    }
    if(fogg == "fog")
    {
        for(space* fog: p.get_fog())
        {
            if(fog != this)
            {
                available.push_back(fog);
                aaa.push_back(fog->get_id());
            }
        }
        counter = counter + 2;
    }
    if(!available.empty())
    {
        ch = t.choose_space(g , "where do you want to go?" , aaa);
        return available[ch]->get_id();
    }
    else
    {
        cout << " you cant move ...    there isnt any empty space " << endl;
        return 400;
    }
}
Vector2 space::get()
{
    return ss;
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