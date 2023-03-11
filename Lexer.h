#ifndef LexerH
#define LexerH

#define TT_INT "INT"
#define TT_FLOAT "FLOAT"
#define TT_PLUS "PLUS"
#define TT_MINUS "MINUS"
#define TT_MUL "MUL"
#define TT_DIV "DIV"
#define TT_LPAREN "LPAREN"
#define TT_RPAREN "RPAREN"
#define DIGITS "0123456789"
#define SINTAX "0123456789+-*/()."

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
class TOKENS
{
private:

public:
	int value_int;
	float value_float;
	std::string value, type;
	TOKENS();
	void TOKENS_IN(std::string type_in, int value_in = 0, float value_inf = 0, std::string value_s = "");
	std::string showT();
};  



class Lexer
{
private:

public:
	std::string text;
	int pos;
	char current_char;
	void LEXER(std::string text_in);
	void ADVANCE();
	std::vector<TOKENS> MAKE_TOKENS();
	TOKENS MAKE_NUMBER();
};

/// <summary>
/// NODES
/// </summary>
class Nodes
{
private:
	TOKENS SELF_VALUE;
	TOKENS* RIGHT_NODE, * LEFT_NODE;
public:
	void MAKE_NODE(TOKENS IN_SELF, TOKENS* R_IN, TOKENS* L_IN);
};
#endif