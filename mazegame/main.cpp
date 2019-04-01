// main function
// c++ -std=c++11 *.cpp -o maze
// ./maze Maze.txt

#include <iostream>
#include <fstream>
#include <string>

#include "MazeGame.h"
#include "MazePlayer.h"
using namespace std;
int main(int argc, const char* argv[])
{
    // get a maze file name
    string maze_tiles;
    if (argc > 1) {
        maze_tiles = argv[1];
    } else {
        cout << "Enter your maze file name: ";
        cin >> maze_tiles;
        if (!cin) {
            cout << "Wrong file name. Maze.txt is used instead.\n";
            maze_tiles = "Maze.txt";
        }
    }
    cout << "Maze tiles file: "
    << maze_tiles << endl << endl;
    
    // start the game
    try {
        MazeGame game(maze_tiles);
        game.start_game(cin);
        
    }
    catch(IncorrectFile) {
        cerr << "Incorrect file\n";
        return 1;
    }
    
    return 0;
}

