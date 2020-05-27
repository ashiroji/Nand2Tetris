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
	void compileStatements(int indentLevel);
	void compileLet(int indentLevel);
	void compileIf(int indentLevel);
	void compileWhile(int indentLevel);
	void compileDo(int indentLevel);
	void compileReturn(int indentLevel);
	void compileExpression(int indentLevel);
	void compileTerm(int indentLevel);
	void compileExpressionList(int indentLevel);

private:

	void compileVarDecLL(int indentLevel);
	void compileSubroutineCall(int indentLevel);
	void compileOp(int indentLevel);
	void writeOpenMK(std::string type, int indentLevel);
	void writeCloseMK(std::string type, int indentLevel);
	
	template<typename T>
	void writeMKToFile(T variable, std::string type, int indentLevel);
	
	void advance();
		
	std::ifstream input;
	std::string currentToken;
	std::string outputFileName;
	std::string inputFileName;
	std::ofstream output;
	Tokenizer tokenizer; //use the tokenizer to parse the tokens


		
};

#endif