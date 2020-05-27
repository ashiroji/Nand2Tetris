#ifndef TOKENIZER
#define TOKENIZER

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <cctype>

class Tokenizer
{
public:

	Tokenizer(std::string fileName);
	Tokenizer();
	~Tokenizer();
	void init(std::string fileName);
	bool hasMoreTokens();
	void advance();
	std::string tokenType();
	std::string keyWord();
	char symbol();
	std::string identifier();
	int intVal();
	std::string stringVal();
	std::string getCurrentToken();
private:
	std::ifstream input;
	std::string currentToken;
	std::string nextToken;
	std::string fileName;
	std::string __keyword;
	std::string __identifier;
	std::string __stringConstant;
	char __symbol;
	int __intConstant;

	inline std::string trim_right_copy(const std::string& s, const std::string& delimiters);		
};

#endif