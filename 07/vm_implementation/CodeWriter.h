#ifndef VM_CODEWRITER
#define VM_CODEWRITER

#include <fstream>
#include <iostream>

class CodeWriter
{
public:
	
	CodeWriter(std::string outputFileName);
	~CodeWriter();
	void setFileName(std::string name);
	void writeArithmetic(std::string command);
	void writePushPop(std::string command, std::string segment, std::string fileName, int index);
	void closeFile();	
	void writeInit();
	void writeLabel(std::string label);
	void writeGoto(std::string label);
	void writeIf(std::string label);
	void writeCall(std::string functionName, int numArgs);
	void writeReturn();
	void writeFunction(std::string functionName, int numLocals);
	std::string getFileName();
private:
	std::ofstream output;
	std::string fileName;
	
};
#endif