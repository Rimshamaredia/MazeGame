#include "Position.h"

Position Position::operator+(const Position& other) const
{
    Position result;
    result.col = col + other.col;
    result.row = row + other.row;
    return result;
}

ostream& operator << (ostream &out, const Position &p)
{
    out << "(" << p.row << ", "
    << p.col << ")";
    return out;
}

