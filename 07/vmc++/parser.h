#ifndef VM_PARSER
#define VM_PARSER

#include <fstream>
#include <iostream>
#include <string>
#include <map>

class parser
{
public:

	parser(std::string fileName);
	~parser();
	bool hasMoreCommands();
	void advance();
	std::string commandType();
	std::string arg1(std::string commandType);
	int arg2();
	std::string getCommand();
	std::string getFileName();
private:
	std::ifstream input;
	std::string currentCommand;
	std::map<std::string, std::string> cType;
	std::string fileName;
	inline std::string trim_copy(const std::string& s, const std::string& delimiters);
	inline std::string trim_left_copy(const std::string& s, const std::string& delimiters);
	inline std::string trim_right_copy(const std::string& s, const std::string& delimiters);
		
};

#endif