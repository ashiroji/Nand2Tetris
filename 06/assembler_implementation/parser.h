#ifndef PARSER
#define PARSER

#include <fstream>
#include <iostream>

class parser
{
public:
	parser(const std::string& inputFile);
	void advance();
	bool hasMoreCommands();
	std::string commandType();
	std::string symbol(std::string command);
	std::string dest();
	std::string comp();
	std::string jump(); 
	inline std::string trim_copy(const std::string& s, const std::string& delimiters);
	inline std::string trim_left_copy(const std::string& s, const std::string& delimiters);
	inline std::string trim_right_copy(const std::string& s, const std::string& delimiters);
	~parser();

private:
	std::ifstream input;
	std::string fileName;
	std::string currentCommand;
	
};

#endif