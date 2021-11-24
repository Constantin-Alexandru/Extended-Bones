#pragma once

#include <string>
#include <iostream>

namespace eb
{
    struct Location
    {
        std::string file;
        int row;
        int column;

        Location(std::string _file = "", int _row = 0, int _column = 0);

        Location(const Location &other) = default;

        eb::Location &operator=(const eb::Location &other);

        friend std::ostream &operator<<(std::ostream &out, const eb::Location &loc);
    };
}
