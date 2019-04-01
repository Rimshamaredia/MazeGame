#ifndef TILE_H
#define TILE_H

#include <iostream>

using namespace std;

class Tile
{
public:
    char tile_char = '_';
    
public:
    virtual bool try_walk()
    {
        return false;
    }
    
    virtual bool is_start()
    {
        return false;
    }
    
    virtual bool is_end()
    {
        return false;
    }
};

class WallTile : public Tile
{
public:
    WallTile() { tile_char = 'W'; }
public:
    
   
    // implement this class
    
};

class EmptyTile : public Tile
{
public:
    EmptyTile() { tile_char = 'X'; }
public:
    bool try_walk() override{
        return true;
    }
   
    
    // implement this class
};

class StartingTile : public EmptyTile
{
public:
    StartingTile() {tile_char = 'S';}
public:
    
   
     bool is_start()override{
        return true;
    }
   
    
    // implement this class
};

class EndingTile : public EmptyTile
{
public:
    EndingTile() {tile_char = 'E';}
public:
    
   bool is_end() override{
        return true;
    }
   
    // implement this class
};

ostream & operator << (ostream &out, const Tile &t);
istream & operator >> (istream &in,  Tile *&t);

#endif
