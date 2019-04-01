// implementation of MazeGame functions

#include "MazeGame.h"
using namespace std;
MazeGame::MazeGame(string filename)
{
    save_out.open(out_name);
    ifstream in;
    in.open(filename);
    if (!in) {
        cerr << "Wrong maze tiles file: " + filename << endl;
        throw IncorrectFile();
    }
    save_out << "Maze tiles file: " << filename << endl << endl;
    in >> maze;
}

MazeGame::~MazeGame()
{
    save_out.close();
}

void MazeGame::start_game(istream& is)
{
    
    auto rows = maze.get_tiles();
    for(int i = 0; i<rows.size() ;i++){
        for(int j = 0; j < rows[i].size(); j++){
            if(rows[i][j]->tile_char == 'S') {
                players.push_back(new MazePlayer(Position(i,j)));
            }
        }
    }
    print_maze();
    // implement this function
    update_loop(is);
}

// Important: if you use cout << something
// do the same with save_out << something
// Otherwise, the file output.txt would be incorrect
void MazeGame::update_loop(istream& is)
{
   
    
    int pnum = 0; // player's number
    string in;
    for(auto player : players) {
       
        pnum++;
        cout<<"move #"<<player->move_number()<<"----------"<<endl;
        save_out<<"move #"<<player->move_number()<<"----------"<<endl;
        cout<<"Player "<<pnum<<" Position: "<<player->get_position()<<endl;
        save_out<<"Player "<<pnum<<" Position: "<<player->get_position()<<endl;
        
        is>>in;
        Position newp;
        newp = player->take_turn(in);
        if(maze.can_move_to_tile(newp)){
            player->set_position(newp);
            print_maze();
        }
        else{
            cout<<"Invalid Move "<<endl;
            save_out<<"Invalid Move "<<endl;
            
            print_maze();
            update_loop(is);
            return;
        }
        if(maze.is_tile_end(player->get_position())){
            cout<<"Player "<<pnum<<" won the game!"<<endl;
            save_out<<"Player "<<pnum<<" won the game! "<<endl;
            return;
        }
    }
        update_loop(is);
        /*player->set_position(newp);
        
       
        if(maze.can_move_to_tile(newp) == true){
             player->set_position(newp);
            if(maze.is_tile_end(newp)== true){
                cout<<"Player "<<pnum<< "Won"<<endl;
                save_out<<"Player "<<pnum<<"won"<<endl;
                return;
            
           
        }
        }*/
      
        //print_maze();
        }
        
        // implement code here
        //print_maze();
    
    


void MazeGame::print_maze()
{
    vector<string> grid;
    for(auto row : maze.get_tiles()) {
        string tiles = "";
        for(auto t : row)
            tiles += t->tile_char;
        
        grid.push_back(tiles);
    }
    
    for(auto player : players)
        grid[player->get_position().row][player->get_position().col] = 'P';
    
    cout << " ";
    save_out << " ";
    
    for(int i = 0; i < grid[0].size(); i++) {
        cout << i;
        save_out << i;
    }
    
    cout << endl;
    save_out << endl;
    
    for(int i = 0; i < grid.size(); i++) {
        cout << i << grid[i] << endl;
        save_out << i << grid[i] << endl;
    }
}


