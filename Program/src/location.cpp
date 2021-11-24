#include "./includes/location.h"

eb::Location::Location(std::string _file, int _row, int _column)
{
    file = _file;
    row = _row;
    column = _column;
}

eb::Location &eb::Location::operator=(const eb::Location &other)
{
    file = other.file;
    row = other.row;
    column = other.column;

    return *this;
}

namespace eb
{
    std::ostream &operator<<(std::ostream &out, const eb::Location &loc)
    {

        out << loc.file << ":" << loc.row << ":" << loc.column;
        return out;
    }
}