#include "parser.h"

inline std::string parser::trim_right_copy(
  const std::string& s,
  const std::string& delimiters = " \f\n\r\t\v" )
{
  return s.substr( 0, s.find_last_not_of( delimiters ) + 1 );
}

inline std::string parser::trim_left_copy(
  const std::string& s,
  const std::string& delimiters = " \f\n\r\t\v" )
{
  return s.substr( s.find_first_not_of( delimiters ) );
}

inline std::string parser::trim_copy(
  const std::string& s,
  const std::string& delimiters = " \f\n\r\t\v" )
{
  return trim_left_copy( trim_right_copy( s, delimiters ), delimiters );
}

parser::parser(std::string fileName)
{
	this->currentCommand ="";
	this->fileName = fileName;
	this->input.open(fileName.c_str());
	if(!(this->input.is_open()))
	{
		std::cout<<"Parser : failed to open file"<<std::endl;
		std::cout<<fileName<<std::endl;
	}
	this->cType["add"] = "C_ARITHMETIC";
	this->cType["sub"] = "C_ARITHMETIC";
	this->cType["neg"] = "C_ARITHMETIC";
	this->cType["eq"] = "C_ARITHMETIC";
	this->cType["gt"] = "C_ARITHMETIC";
	this->cType["lt"] = "C_ARITHMETIC";
	this->cType["and"] = "C_ARITHMETIC";
	this->cType["or"] = "C_ARITHMETIC";
	this->cType["not"] = "C_ARITHMETIC";
	this->cType["pop"] = "C_POP";
	this->cType["push"] = "C_PUSH";
	this->cType["label"] = "C_LABEL";
	this->cType["goto"] = "C_GOTO";
	this->cType["if-goto"] = "C_IF";
	this->cType["function"] = "C_FUNCTION";
	this->cType["call"] = "C_CALL";
	this->cType["return"] = "C_RETURN";
}

std::string parser::getFileName()
{
	return (this->fileName.substr(this->fileName.rfind('/')+1));
}

parser::~parser()
{
	this->input.close();
}

bool parser::hasMoreCommands()
{
	return (this->input.good());
}

void parser::advance()
{
	this->currentCommand.clear();
	std::string line;
	while(std::getline(this->input, line))
	{

		if(this->input.eof())
		{
			this->currentCommand="";
			break;
		}
		if((line != "") && (line[0] != '/') && (line.length()>1))
		{
			//erase end of line comments
			if(line.find("/") != std::string::npos)
			{
				line.erase(line.find("/"), std::string::npos);
			}
			//trim white spaces
			this->currentCommand = this->trim_copy(line);
			break;
		}
		else{
		this ->currentCommand = "";
		}
	}
}

std::string parser::commandType()
{
	//std::cout<<"currentCommand ="<<this->currentCommand<<std::endl;

	std::size_t firstDelimeter = this->currentCommand.find(' '); //find first space or npos
	std::string arg = this->currentCommand.substr(0, firstDelimeter);
	//std::cout<<"arg = "<<arg<<std::endl; 
	if(this->cType.find(arg) != this->cType.end())
	{
		return(this->cType[arg]);
	}
	return("");
}

std::string parser::arg1(std::string commandType)
{
	//op [arg1] [arg2]
	if(commandType == "C_ARITHMETIC")
	{
		return(this->currentCommand);
	}
	//find fist space pos
	std::size_t firstDelimeter = this->currentCommand.find(' ');
	
	//find second space pos or npos
	std::size_t secondDelimeter = this->currentCommand.find(' ', firstDelimeter+1);

	//the arg is between the two spaces or space and npos
	std::string result = this->currentCommand.substr(firstDelimeter+1, secondDelimeter- firstDelimeter-1);
	//result = this->trim_copy(result);
	return(result);
}

int parser::arg2()
{	//op arg1 arg2
	//find the last space
	std::size_t firstDelimeter = this->currentCommand.rfind(' ');

	//copy from last space to npos
	std::string result = this->currentCommand.substr(firstDelimeter+1);
	//std::cout<<"result arg2 = "<<result<<std::endl;
	return(std::stoi(result));
}

std::string parser::getCommand()
{
	return(this->currentCommand);
}