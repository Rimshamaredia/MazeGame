#ifndef POSITION_H
#define POSITION_H

#include <iostream>

using namespace std;

struct Position{
    int row;
    int col;
    Position() : row(0), col(0) {}
    Position(int r, int c) : row(r), col(c) {}
    Position operator+(const Position&) const;
};

ostream & operator << (ostream &out, const Position &p);

#endif
