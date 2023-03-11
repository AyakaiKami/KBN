#include <iostream>
#include "Lexer.h"

int main()
{
    std::vector<TOKENS> V_TOK = { };
    std::string cuv="11+2-2.3+0";    
    Lexer x;

    x.LEXER(cuv);
    V_TOK = x.MAKE_TOKENS();
    int i;
    for (i = 0; i < V_TOK.size(); i++)
        std::cout << V_TOK.at(i).showT() << std::endl;
    return 0;
}