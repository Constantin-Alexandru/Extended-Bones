#pragma once

enum class Type
{
    OP_CLEAR,
    OP_SET,
    OP_VAR,
    OP_VAL,
    OP_PRINTA,
    OP_COUNTER
};

struct Token
{
    Token(int loc, Type type, char *val, bool block);

    int _loc;
    char *val;
    Type _type;
    bool _block;
    int _jmp_loc;
};

Token *createToken(int loc, Type type, char *val = {}, bool block = false);