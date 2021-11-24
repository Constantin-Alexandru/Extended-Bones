#include "./includes/lexer.h"

eb::lexer::Token::Token(eb::lexer::TokenType _type, std::string _value, eb::Location _loc)
{
    type = _type;
    value = _value;
    loc = _loc;
}

namespace eb
{
    namespace lexer
    {

        std::ostream &operator<<(std::ostream &out, const eb::lexer::Token &token)
        {
            out << "[ ";

            static_assert((int)eb::lexer::TokenType::Count == 4, "Unhandled Token Types inside Token Op Overloading");

            switch (token.type)
            {
            case eb::lexer::TokenType::Keyword:
                out << "Keyword , ";
                break;
            case eb::lexer::TokenType::Operator:
                out << "Operator , ";
                break;
            case eb::lexer::TokenType::Literal:
                out << "Literal , ";
                break;
            case eb::lexer::TokenType::Reference:
                out << "Reference , ";
                break;
            default:
                std::cout << " Default case should never be hit inside Token operator '<<' overloading ";
                break;
            }

            out << token.value << " , " << token.loc << " ]";

            return out;
        }
    }
}

std::vector<eb::lexer::Token> eb::lexer::generateTokens(std::vector<std::string> program, std::string filePath)
{
    std::vector<eb::lexer::Token> tokens;

    //Search strings
    std::string eol = ";";
    std::string whitespace = " ";

    Location loc = Location(filePath, 0, 0);

    for (int i = 0; i < program.size(); i++)
    {
        std::string row = program[i];

        loc.row = i + 1;

        if (row.size() > 0)
        {
            if (row[row.size() - 1] != eol[0])
            {
                loc.column = row.size();
                std::cout << loc << ": Missing \';\' at the end of the line: " << program[i];
                exit(-1);
            }

            //Removing the ';' at the end
            row.pop_back();

            int currLine = 0;

            for (int j = 0; j < row.size();)
            {
                if (row[j] != whitespace[0])
                {
                    int pos = row.find(whitespace);

                    if (pos == std::string::npos)
                    {
                        pos = row.size();
                    }

                    std::string word = row.substr(0, pos);
                    row = row.erase(0, pos + 1);

                    loc.column = currLine;

                    currLine += pos + 1;

                    static_assert((int)eb::lexer::TokenType::Count == 4, "Unhandled Token Types inside Lexer");

                    if (std::find(keywords.begin(), keywords.end(), word) != keywords.end())
                    {
                        eb::lexer::Token token = eb::lexer::Token(eb::lexer::TokenType::Keyword, word, loc);
                        tokens.push_back(token);
                    }
                    if (std::find(operators.begin(), operators.end(), word) != operators.end())
                    {
                        eb::lexer::Token token = eb::lexer::Token(eb::lexer::TokenType::Operator, word, loc);
                        tokens.push_back(token);
                    }
                    else if (eb::utils::isNumber(word))
                    {
                        eb::lexer::Token token = eb::lexer::Token(eb::lexer::TokenType::Literal, word, loc);
                        tokens.push_back(token);
                    }
                    else
                    {
                        eb::lexer::Token token = eb::lexer::Token(eb::lexer::TokenType::Reference, word, loc);
                        tokens.push_back(token);
                    }

                    j = 0;
                }
                else
                {
                    currLine++;
                    j++;
                }
            }
        }
    }

    return tokens;
}