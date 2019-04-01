//
//  MazePlayer.cpp
//  mazegame
//
//  Created by Rimsha Maredia on 11/14/18.
//  Copyright © 2018 Rimsha Maredia. All rights reserved.
//

//MazePlayer

#include "MazePlayer.h"
#include "Position.h"

Position MazePlayer::take_turn(string& input)
{
    move_no++; // increase the move #
    
    //notice here the rows and column direction seems to be reversed
    //but this is becuase we are using row then columns
    if(input == "up" || input == "u") {
        return position + Position(-1,0);
    } else if (input == "down" || input == "d") {
        return position + Position(1,0);
    } else if (input == "left" || input == "l") {
        return position + Position(0,-1);
    } else if (input == "right" || input == "r") {
       
        return position + Position(0,1);
    } else { // do not change the current position
        return position;
    }
}

