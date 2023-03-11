#include "Lexer.h"







/// TOKENS
TOKENS::TOKENS() {};
void TOKENS::TOKENS_IN(std::string type_in, int value_in, float value_inf,std::string value_s)
{
	type = type_in;
	value_int = value_in;
	value_float = value_inf;
	value = value_s;
}

std::string TOKENS::showT()
{
	if (value != "")
		return  type + " : " + value ;
	else
		return type;
}

void Lexer::LEXER(std::string text_in)
{
	text = text_in;
	pos = -1;
	current_char = 0;
	ADVANCE();
}
void Lexer::ADVANCE()
{
	pos++;
	current_char = text[pos];
}
std::vector<TOKENS> Lexer::MAKE_TOKENS()
{
	std::vector<TOKENS>V_TOK = { };
	while (current_char!=0 && current_char!=3)
	{
		
		if(current_char==' ' || current_char=='\t')
		{
		  ADVANCE();
		}
		else
			if (strchr(DIGITS, current_char))
			{
				TOKENS x = MAKE_NUMBER();
				V_TOK.emplace(V_TOK.end(), x);
				pos--;
				current_char = text[pos];
		    }
		else
		    if(current_char=='+')
			{
				TOKENS x;
				x.TOKENS_IN(TT_PLUS);
				V_TOK.emplace(V_TOK.end(), x);
			}
		else
			if (current_char == '-')
			{
				TOKENS x;
       			x.TOKENS_IN(TT_MINUS);
				V_TOK.emplace(V_TOK.end(), x);
			}
		else
			if (current_char == '*')
			{
				TOKENS x;
				x.TOKENS_IN(TT_MUL);
				V_TOK.emplace(V_TOK.end(), x);
			}
		else
			if (current_char == '/')
			{
				TOKENS x;
				x.TOKENS_IN(TT_DIV);
				V_TOK.emplace(V_TOK.end(),x);
			}
		else
			if (current_char == '(')
			{
				TOKENS x;
				x.TOKENS_IN(TT_LPAREN);
				V_TOK.emplace(V_TOK.end(), x);
			}
		else
			if (current_char == ')')
			{
				TOKENS x;
				x.TOKENS_IN(TT_RPAREN);
				V_TOK.emplace(V_TOK.end(), x);
			}
			else
			{
			    printf("Eroare sintaxa \n");
				break;
			}
		ADVANCE();
	}
	return V_TOK;
}
TOKENS Lexer::MAKE_NUMBER()
{
	TOKENS x;
	std::string number = "";
	int dot_count = 0;
	while (current_char && (strchr(DIGITS, current_char) || current_char == '.') && current_char!=3 && current_char!=0)
	{
		if (current_char == '.')
		{
			if (number == "") break;
			dot_count++;
			number = number + ".";

		}
		else
			number = number + current_char;
		ADVANCE();
	}
	if (dot_count == 0)
	{
		x.type = TT_INT;
		x.value = number;
		x.value_int = std::stoi(number);
	}
	if (dot_count == 1)
	{
		x.type = TT_FLOAT;
		x.value = number;
		x.value_float = std::stof(number);
	}

	return x;
}
