#ifndef COMPILATION_ENGINE
#define COMPILATION_ENGINE

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include "Tokenizer.h"

class CompilationEngine
{
public:

	CompilationEngine(std::string inputFileName, std::string outputFileName);
	~CompilationEngine();
	void compileClass();
	void compileClassVarDec();
	void compileSubroutineDec();
	void compileParameterList();
	void compileSubroutineBody();
	void compileVarDec();
	void compileStatements();
	void compileLet();
	void compileIf();
	void compileWhile();
	void compileDo();
	void compileReturn();
	void compileExpression();
	void compileTerm();
	void compileExpressionList();
private:
	std::ifstream input;
	std::string currentToken;
	std::string outputFileName;
	std::ofstream output;
	Tokenizer tokenizer; //use the tokenizer to parse the tokens


		
};

#endif