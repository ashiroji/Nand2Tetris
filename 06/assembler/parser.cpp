#include "parser.h"
#include <string>

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

parser::parser(const std::string& inputFile)
{
	this->currentCommand ="";
	fileName = inputFile;
	this->input.open(fileName.c_str());
	if(!(this->input.is_open()))
	{
		std::cout<<"failed to open file"<<std::endl;
	}
}

bool parser::hasMoreCommands()
{
	std::cout<<"good : "<<this->input.good()<<std::endl;
	return (this->input.good());
}

void parser::advance()
{
	this->currentCommand.clear();
	std::string line;
	while(std::getline(this->input, line))
	{
		std::cout<<"line : "<<line<<std::endl;
		std::cout<<"currentCommand before change :"<<this->currentCommand<<std::endl;
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
			std::cout<<"currentCommand : "<<currentCommand<<std::endl;
			break;
		}
		else{
		this ->currentCommand = "";
		std::cout<<"currentCommand : "<<currentCommand<<std::endl;
		}
	}
}

std::string parser::commandType(){
	if(this->currentCommand.empty())
	{
		return("no command");
	}
	if(this -> currentCommand[0] == '\n')
	{
		return("null");
	}
	else if (this->currentCommand[0] == '@')
	{
		return("A_COMMAND");
	}
	else if(this->currentCommand[0] == '(')
	{
		return("L_COMMAND");
	}
	else
	{
	return("C_COMMAND");
	}
}

std::string parser::symbol(std::string command)
{
	std::string result;
	if(command == "A_COMMAND")
	{
		result = this->trim_copy(this->currentCommand,"@");
		result = this->trim_copy(result);
		return(result);
	}
	else if(command == "L_COMMAND")
	{
		result = this->trim_copy(this->currentCommand,"()");
		result = this->trim_copy(result);
		return(result);
	}
	return("");
}

std::string parser::dest()
{
	std::size_t eqPos = this->currentCommand.find("=");
	if(eqPos == std::string::npos)
	{
		return("null");
	}
	std::string result = this->currentCommand.substr(0,eqPos);
	return(result);

}

std::string parser::comp()
{
	std::size_t eqPos = this->currentCommand.find("=");
	if(eqPos == std::string::npos)
	{
		eqPos = 0;
	}
	std::size_t scPos = this->currentCommand.find(";");
	if(scPos == std::string::npos)
	{
		scPos = std::string::npos;
	}	
	std::string result = this->currentCommand.substr(eqPos,scPos);
	result = this->trim_copy(result,"=");
	result = this->trim_copy(result);
	return(result);	
}

std::string parser::jump()
{
	std::size_t jPos = this->currentCommand.find("J");
	if(jPos == std::string::npos)
	{
		return("null");
	}
	std::string result = this->currentCommand.substr(jPos, std::string::npos);
	result = this->trim_copy(result);
	return(result);
}

parser::~parser(){
	this->input.close();
}