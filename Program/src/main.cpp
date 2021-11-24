#include "./includes/main.h"

int main(int argc, char **argv)
{
    if (argc < 1)
    {
        std::cout << "ERROR: Missing command line arguments";
        exit(-1);
    }

    std::string filePath = argv[1];

    std::cout << filePath << '\n';

    if (!filePath.ends_with(".eb"))
    {
        std::cout << "ERROR: Invalid file passed as argument (incorrect extension)";
        exit(-1);
    }

    std::ifstream f(filePath);

    if (!f.good())
    {
        std::cout << "ERROR: Invalid file passed as argument";
        exit(-1);
    }

    std::string row;
    std::vector<std::string> program;

    while (std::getline(f, row))
    {

        program.push_back(row);
    }

    f.close();

    std::vector<eb::lexer::Token> tokens = eb::lexer::generateTokens(program, filePath);

    for (int i = 0; i < tokens.size(); i++)
    {
        std::cout << tokens[i] << '\n';
    }

    exit(0);
}