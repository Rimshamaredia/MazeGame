//
//  MazeGame.hpp
//  mazegame
//
//  Created by Rimsha Maredia on 11/14/18.
//  Copyright © 2018 Rimsha Maredia. All rights reserved.
//

#ifndef MAZEGAME_H
#define MAZEGAME_H

#include <iostream>
#include <fstream>
#include <vector>

#include "Maze.h"
#include "MazePlayer.h"
#include "Position.h"

// the exception class used in openining a maze file
class IncorrectFile { };

class MazeGame
{
private:
    Maze maze;
    vector<MazePlayer*> players;
    ofstream save_out;
    string out_name{"output.txt"};
    
public:
    MazeGame(string filename);
    ~MazeGame();
    void start_game(istream& is);
    
   
   
    
protected:
    void update_loop(istream& is);
    void print_maze();
};

#endif
