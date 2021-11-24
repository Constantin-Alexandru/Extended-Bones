#include "./includes/utils.h"

bool eb::utils::isNumber(std::string str)
{
    int i = 0;

    for (; str[i] == '-'; i++)
        ;

    if (i >= str.size())
        return false;

    for (; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}