#pragma once

#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "location.h"
#include "utils.h"

namespace eb
{
    namespace lexer
    {
        enum class TokenType
        {
            Keyword,
            Operator,
            Literal,
            Reference,
            Count
        };

        struct Token
        {
            TokenType type;
            std::string value;
            eb::Location loc;

            Token(TokenType _type = TokenType::Count, std::string _value = "", eb::Location _loc = eb::Location());

            friend std::ostream &operator<<(std::ostream &out, const Token &token);
        };

        const static std::vector<std::string> operators = {"clear", "set", "printa"};
        const static std::vector<std::string> keywords = {"if", "while", "do", "end"};

        std::vector<Token> generateTokens(std::vector<std::string> program, std::string filePath);

    }
}
