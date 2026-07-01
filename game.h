#ifndef _GAME
#define _GAME
#include <iostream>


class game
{
    private:
        std::string name;
        int younger;
    public:
        game();
        void age(game);

};
#endif