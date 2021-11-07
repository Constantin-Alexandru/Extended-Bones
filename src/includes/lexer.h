#pragma once

#include "token.h"
#include "utils.h"

#include <map>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <cstdlib>

class Lexer
{
public:
    void lex(char *program);
    std::vector<Token *> getTokens();

private:
    std::vector<Token *> tokens;

    bool isValid(const char *chrs);

    bool isNum(const char *chrs);

    Token *interpretToken(const char *tkn, int loc);
};