#ifndef MAZEPLAYER_H
#define MAZEPLAYER_H

#include "Position.h"
#include <iostream>

using namespace std;

class MazePlayer
{
private:
    int move_no; // move number for each player
    Position position;
    
public:
    MazePlayer(Position pos) : position(pos), move_no(1) { }
    Position& get_position() { return position; }
    void set_position(Position pos) { position = pos; }
    int move_number() { return move_no; }
    Position take_turn(string& s);
};

#endif

