#include "./includes/lexer.h"

#include "./includes/testlibs.h"

void Lexer::lex(char *program)
{
    printf("Entering lexer\n");

    std::stringstream ss(program);

    int loc = 1;

    std::string stmt;

    if (program != NULL)
    {
        while (std::getline(ss, stmt, '\n'))
        {
            std::stringstream tkns(stmt);

            std::string tkn;

            while (tkns >> tkn)
            {
                tkn = String::trim(tkn);
                tokens.push_back(interpretToken(tkn.c_str(), loc));
            }

            loc++;
        }
    }

    for (auto token : tokens)
    {
        printf("%d - %d\n", token->_type, token->_loc);
    }

    printf("Exiting lexer\n");
}

Token *Lexer::interpretToken(const char *tkn, int loc)
{

    static_assert(static_cast<int>(Type::OP_COUNTER) == 5, "Unhandled operations");

    if (tkn != NULL)
    {
        if (std::strcmp(tkn, "clear") == 0)
            return createToken(loc, Type::OP_CLEAR);
        else if (std::strcmp(tkn, "set") == 0)
            return createToken(loc, Type::OP_SET);
        else if (std::strcmp(tkn, "printa") == 0)
            return createToken(loc, Type::OP_PRINTA);
        else if (isValid(tkn))
        {
            int size = std::strlen(tkn);

            char *var = new char[size];

            std::strcpy(var, tkn);
            if (tkn[size - 1] == ';')
            {
                var[size - 1] = '\n';
            }

            if (isNum(var))
            {
                printf("VALUE\n");
                return createToken(loc, Type::OP_VAL);
            }
            else
            {
                return createToken(loc, Type::OP_VAR);
            }

            delete var;
        }
        else
        {
            printf("INVALID_TOKEN\n");
            return NULL;
        }
    }
}

bool Lexer::isValid(const char *chrs)
{
    for (int i = 0; chrs[i] != '\0'; i++)
    {
        std::string ch(1, chrs[i]);

        const char *c = ch.c_str();
        if (!isalnum(chrs[i]) && (std::strcmp(c, "_") != 0) && std::strcmp(c, ";") != 0)
        {
            return false;
        }
    }

    return true;
}

bool Lexer::isNum(const char *chrs)
{
    int i = 0;

    while (chrs[i] == '-')
    {
        i++;
    }

    if (chrs[i] == '\n')
    {
        printf("%c - %s\n", chrs[i], chrs);
        return false;
    }

    for (; chrs[i] != '\n'; i++)
    {
        if (!isdigit(chrs[i]))
        {
            printf("%c - %s\n", chrs[i], chrs);
            return false;
        }
    }

    return true;
}