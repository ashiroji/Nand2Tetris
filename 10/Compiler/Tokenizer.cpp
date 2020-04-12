#include "Tokenizer.h"

inline std::string Tokenizer::trim_right_copy(
  const std::string& s,
  const std::string& delimiters = " \f\n\r\t\v" )
{
  return s.substr( 0, s.find_last_not_of( delimiters ) + 1 );
}

Tokenizer::Tokenizer(std::string fileName)
{
	this->fileName = fileName;
	this->input.open(this->fileName.c_str());

	if(!(this->input.is_open()))
	{
		std::cout<<"Tokenizer : failed to open file"<<std::endl;
		std::cout<<fileName<<std::endl;
	}
}

Tokenizer::Tokenizer()
{
	this->fileName = "";
}

Tokenizer::~Tokenizer()
{
	this->input.close();
}

void init(std::string fileName)
{
	this->fileName = fileName;
	this->input.open(this->fileName.c_str());

	if(!(this->input.is_open()))
	{
		std::cout<<"Tokenizer : failed to open file"<<std::endl;
		std::cout<<fileName<<std::endl;
	}
}

bool Tokenizer::hasMoreTokens()
{
	return (this->input.good());
}


void Tokenizer::advance()
{
	this->currentToken.clear();
	std::string word;
	std::string line;

	if (this->nextToken != "")
	{
		std::cout<<"nextToken7 = "<<this->nextToken<<std::endl;
		if (this->nextToken.length()>1)
		{
			/*possibilites : () => symbol symbol
							 .bar() => symbol identifier symbol symbol
							 ; => symbol
							 (){ => symbol symbol symbol
							 [i] => symbol identifier symbol
			*/
			if(!isalpha(this->nextToken[0]))
			{
				//"string constant" => string constant 
	        	if('\"'== this->nextToken[0])//start of string constant
	        	{
	        		//read line
	        		std::getline(this->input, line);
	        		//find the end of the string constant : "
	        		int endPos = line.rfind('\"');
	        		this->currentToken = this->nextToken + line.substr(0, endPos+1);
	        		std::cout<<"string constant 2 = "<<this->currentToken<<std::endl;
	        		this->nextToken = line.substr(endPos+1);
		                this->nextToken = trim_right_copy(this->nextToken);
	        	}			            	
	        
		        else
		        {
		        	this->currentToken = this->nextToken[0];
					this->nextToken = this->nextToken.substr(1);
		        }
			}
			else
			{
				int i=0;
				while(isalpha(this->nextToken[i]))
				{
					std::cout<<"copying"<<std::endl;
					this->currentToken.push_back(this->nextToken[i]);
					std::cout<<"currentToken5 = "<<this->currentToken<<std::endl;
					i++;
				}
				
				if (i == this->nextToken.length())
				{
					std::cout<<"currentToken4 = "<<this->currentToken<<std::endl;
					std::cout<<"nextToken4 = "<<this->nextToken<<std::endl;	
					this->nextToken.clear();
				}
				else
				{
					this->nextToken = this->nextToken.substr(i);
				}
			}
			std::cout<<"currentToken1 = "<<this->currentToken<<std::endl;
			std::cout<<"nextToken1 = "<<this->nextToken<<std::endl;			
			return;
		}
		this->currentToken = this->nextToken;
		std::cout<<"currentToken2 = "<<this->currentToken<<std::endl;
		std::cout<<"nextToken2 = "<<this->nextToken<<std::endl;		
		this->nextToken.clear();
		return;
	}
	while(this->input >> word) 
	{
		std::cout<<"current word : "<<word<<std::endl;
		//if single line comment => skip to next line
		if(('/' == word[0]) && ('/' == word[1]))
		{
			std::getline(this->input, line);
			word.clear();
			break;
		}
		//if multiple lines comment => skip to next valid line
		else if(('/' == word[0]) && ('*' == word[1]))
		{
			while(std::getline(this->input, line))
			{
				if (line.rfind("*/") != std::string::npos)
				{	
					//we found the last commented line so break
					word.clear();
					break; 
				}
			}
			break;
		}
		//if not comment or string constant, parse the word and process it 
		else
		{
			for (int i=0; i< word.length(); i++)
			{	
				/*if word contains symbols, possibilites : foo() => identifier symbol symbol
														   Foo.bar() => identifier symbol identifier symbol symbol
														   foo; => identifier symbol
														   foo(){ => identifier symbol symbol symbol
														   foo[i] => identifier symbol identifier symbol
														   foo, foo => identifier symbol identifier
														   (foo) => symbol identifier symbol
				*/
				if(!isalpha(word[i]))
	         	{
		            if (word.find('.') != std::string::npos)
		            {
		               size_t pos = (word.find('.')> 0)? word.find('.'):1;	
		               this->currentToken = word.substr(0, pos);
		               this->nextToken = word.substr(pos);
		               break;
		            } 
		            else if (word.find('(') != std::string::npos)
		            {
		               size_t pos = (word.find('(')> 0)? word.find('('):1;	
		               this->currentToken = word.substr(0, pos);
		               this->nextToken = word.substr(pos);
		               break;
		            }
		            else if (word.find(')') != std::string::npos)
		            {
		               size_t pos = (word.find(')')> 0)? word.find(')'):1;	
		               this->currentToken = word.substr(0, pos);
		               this->nextToken = word.substr(pos);
		               break;
		            }
		            else if (word.find('[') != std::string::npos)
		            {
		               size_t pos = (word.find('[')> 0)? word.find('['):1;	
		               this->currentToken = word.substr(0, pos);
		               this->nextToken = word.substr(pos);
		               break;
		            }
		            else if (word.find(']') != std::string::npos)
		            {
		               size_t pos = (word.find(']')> 0)? word.find(']'):1;	
		               this->currentToken = word.substr(0, pos);
		               this->nextToken = word.substr(pos);
		               break;
		            }
		            else if (word.find(',') != std::string::npos)
		            {
		               size_t pos = (word.find(',')> 0)? word.find(','):1;	
		               this->currentToken = word.substr(0, pos);
		               this->nextToken = word.substr(pos);
		               break;		            	
		            }
					//"string constant" => string constant 
					else if (word.find('\"') != std::string::npos)
			        {	
			        	if('\"'== word[0])//start of string constant
			        	{
			        		//read line
			        		std::getline(this->input, line);
			        		//find the end of the string constant : "
			        		int endPos = line.rfind('\"');
			        		this->currentToken = word + line.substr(0, endPos+1);
			        		std::cout<<"string constant = "<<this->currentToken<<std::endl;
			        		this->nextToken = line.substr(endPos+1);
	 		                this->nextToken = trim_right_copy(this->nextToken);
			        	}	
						break;		            	
			        }		            
		            else if (word.find(';') != std::string::npos)
		            {
		               size_t pos = (word.find(';')> 0)? word.find(';'):1;	
		               this->currentToken = word.substr(0, pos);
		               this->nextToken = word.substr(pos);
		               break;		            	
		            }
	        	}
	        }
 	        if (this->currentToken != "")
	        {
	        	std::cout<<"currentToken6 = "<<this->currentToken<<std::endl;
				std::cout<<"nextToken6 = "<<this->nextToken<<std::endl;	
	        	break;
	        }
	        else
	        {
				//else word is to be processed as is
				this->currentToken = word;
				break;
	        }
        }
	}
}


std::string Tokenizer::tokenType()
{

	if (this->currentToken.length() != 0)
	{	
		/*Keywords*/
		if ((this->currentToken == "class") or (this->currentToken == "constructor") 
			or (this->currentToken == "function"))
		{
			return ("keyword");
		}

		if ((this->currentToken == "method") or (this->currentToken == "field") 
			or (this->currentToken == "static"))
		{
		  	return ("keyword");
		}

		if ((this->currentToken == "var") or (this->currentToken == "int")
			or (this->currentToken == "char"))
		{
		  	return ("keyword");
		}

		if ((this->currentToken == "boolean") or (this->currentToken == "void")
			or (this->currentToken == "true"))
		{
		  	return ("keyword");
		}

		if ((this->currentToken == "false") or (this->currentToken == "null")
			or (this->currentToken == "this"))
		{
		  	return ("keyword");
		}

		if ((this->currentToken == "let") or (this->currentToken == "do") 
			or (this->currentToken == "if"))
		{
		  	return ("keyword");
		}

		if ((this->currentToken == "else") or (this->currentToken == "while")
			or (this->currentToken == "return"))
		{
		  	return ("keyword");
		}   


		/* Symbols*/
		if ((this->currentToken == "{") or (this->currentToken == "}") 
			or (this->currentToken == "("))
		{
		  	return ("symbol");
		}

		if ((this->currentToken == ")") or (this->currentToken == "[") 
			or (this->currentToken == "]"))
		{
		  	return ("symbol");
		}

		if ((this->currentToken == ".") or (this->currentToken == ",") or (this->currentToken == ";"))
		{
		  	return ("symbol");
		}

		if ((this->currentToken == "+") or (this->currentToken == "-") 
			or (this->currentToken == "*"))
		{
		  	return ("symbol");
		}

		if ((this->currentToken == "/") or (this->currentToken == "&")
			or (this->currentToken == "|"))
		{
		  	return ("symbol");
		}

		if ((this->currentToken == ">") or (this->currentToken == "<")
			or (this->currentToken == "="))
		{
		  	return ("symbol");
		}

		if (this->currentToken == "~")
		{
		  	return ("symbol");
		}

		/* integer*/
		int len = 0;
		for (auto c : this->currentToken)
		{
			if(isdigit(c))
				{
					std::cout<<"c = "<<c<<std::endl;
					len++;	
				}
		}
		if (len == this->currentToken.length())
		{
			return ("int");
		}
		/* string */
		if ((this->currentToken.find('\"') != std::string::npos))
		{
			return("string");
		}

		//if we arrive here it's an identifier
		return("identifier");
	}
	return("no_token");
}

std::string Tokenizer::keyWord()
{
	return this->currentToken;
}

char Tokenizer::symbol()
{
	return this->currentToken[0];
}

std::string Tokenizer::identifier()
{
	return this->currentToken;
}

int Tokenizer::intVal()
{
	return atoi(this->currentToken.c_str());
}

std::string Tokenizer::stringVal()
{
	return this->currentToken.substr(1, this->currentToken.length()-2);
}

std::string Tokenizer::getCurrentToken()
{
	return this->currentToken;
}