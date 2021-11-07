#include "./includes/token.h"

Token::Token(int loc, Type type, char *val, bool block)
{
    _loc = loc;
    _type = type;
    _block = block;
    _jmp_loc = -1;
}

Token *createToken(int loc, Type type, char *val, bool block)
{
    return new Token(loc, type, val, block);
}