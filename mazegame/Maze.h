

#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include "Tile.h"
#include "Position.h"
#include <string>
#include <iostream>

using namespace std;

class Maze
{
private:
    vector<vector<Tile*>> tiles;
public:
    vector<vector<Tile *>>& get_tiles() { return tiles; }
    bool can_move_to_tile(Position pos);
    bool is_tile_end(Position pos);
   
   
};

ostream & operator << (ostream &out, Maze &m);
istream & operator >> (istream &in,  Maze &m);

#endif
