#include "Tile.h"

// output a tile character
ostream & operator << (ostream &out, const Tile &t)
{
    out << t.tile_char;
    return out;
}

// *& is a reference to a pointer
// here t is a reference to Tile*
// read in a tile character, and return in t a Tile object
istream & operator >> (istream &in,  Tile *&t)
{
    
    char x;
    in>>x;
    if(x =='X'){
        t = new EmptyTile();
    }
    else if(x == 'E'){
        t = new EndingTile();
    }
    else if (x == 'W'){
        t = new WallTile();
    }
    else if(x == 'S'){
        t = new StartingTile();
    }
    
    // implement this function
    return in;
}
