#include "CompilationEngine.h"

CompilationEngine::CompilationEngine(std::string inputFileName, std::string outputFileName)
{
	this->inputFileName = inputFileName;
	this->tokenizer.init(inputFileName);

	this->outputFileName = outputFileName;
	this->output.open(this->outputFileName.c_str());

	if(!(this->output.is_open()))
	{
		std::cout<<"CompilationEngine : failed to open output file"<<std::endl;
		std::cout<<outputFileName<<std::endl;
	}

}

CompilationEngine::~CompilationEngine()
{
	this->output.close();
}

/*this is the show runner, since everything is inside
**a class*/
void CompilationEngine::compileClass()
{

	this->output<<"<class>"<<std::endl;
	//find a keywod in the start
	if (this->tokenizer.tokenType() == "keyword")
	{
		if (this->keyWord() == "class")
		{
			//write to output
			this->output<<"	<keyword> ";
			this->output<<tokenizer.keyWord();
			this->output<<" </keyword>"<<std::endl;
			
			//advance
			this->tokenizer.advance();
			if (this->tokenizer.tokenType() == "identifier")
			{
				//write identifier to output
				this->output<<"	<identifier> ";
				this->output<<tokenizer.identifier();
				this->output<<" </identifier>"<<std::endl;				
				
				//advance
				this->tokenizer.advance();
				
				if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == "{"))
				{
					//write to output
					tokenizerOutput<<"	<symbol> ";
					tokenizerOutput<<tokenizer.symbol();
					tokenizerOutput<<" </symbol>"<<std::endl;;

					/*from here on treat the symbols as needed by calling 
					**appropriate functions
					loop over the file until no more tokens
					*/
					do{
						this->tokenizer.advance(); //read next command

						if (this->tokenizer.tokenType() == "keyword")
						{

							//classVarDec =>
							if((this->tokenizer.keyWord() == "static") 
								|| (this->tokenizer.keyWord() == "field"))
							{	
								this->compileClassVarDec();
							}
							//subroutineDev
							else if((this->tokenizer.keyWord() == "constructor") 
									|| (this->tokenizer.keyWord() == "function")
									|| (this->tokenizer.keyWord() == "method"))
							{
								this->compileSubroutineDec();
							}
						}
						else if ((this->tokenizer.tokenType() == "symbol") && 
							(this->tokenizer.symbol() == "}"))
						{
							//end of the class }
							tokenizerOutput<<"	<symbol> ";
							tokenizerOutput<<tokenizer.symbol();
							tokenizerOutput<<" </symbol>"<<std::endl;;
						}
					}while(tokenizer.hasMoreTokens());					
				}
				else1
				{
					//abort
					std::cout<<"error didn't find { symbol after class name"<<std::endl;
					return;
				}
			}
			else
			{
				//abort
				std::cout<<"error : didn't find identifier after class keyword"<<std::endl;
				return;
			}
		} 
		else 
		{
			//abort
			std::cout<<"error : found a keyword but it's not class"<<std::endl;
			return;
		}
	}
	else 
	{
		//abort
		std::cout<<"error didn't find class keyword"<<std::endl;
		return;
	}

	//if we get here we compiled the class correctly
	this->output<<"</class>"<<std::endl;;

}
void CompilationEngine::compileClassVarDec()
{
	//static or field variables
	// static | field type varName,* ;
	this->output<<"	<classVarDec> ";
	if (this->tokenizer.tokenType() == "keyword")
	{
		if ((this->tokenizer.keyWord() == "static") || 
			(this->tokenizer.keyWord() == "field"))
		{
			//write to output
			this->output<<"    <keyword> ";
			this->output<<this->tokenizer.keyword();
			this->output<<" </keyword>"<<std::endl;
			
			//advance
			this->tokenizer.advance();

			//type is a known type or class name
			if ((this->tokenizer.tokenType() ==  "keyword") || (this->tokenizer.tokenType() == "identifier"))
			{
				//type in the known types
				if ((this->tokenizer.keyWord() == "int") || 
					(this->tokenizer.keyWord() == "char") ||
					(this->tokenizer.keyWord() == "boolean") ||
					(this->tokenizer.tokenType() == "identifier"))
				{
					//write to output
					if(this->tokenizer.tokenType() == "keyword")
					{
						this->output<<"    <keyword> ";
						this->output<<this->tokenizer.keyword();
						this->output<<" </keyword>"<<std::endl;
					}
					else{
						this->output<<"    <identifier> ";
						this->output<<this->tokenizer.identifier();
						this->output<<" </identifier>"<<std::endl;						
					}
					//advance
					this->tokenizer.advance();

					//var name
					if (this->tokenizer.tokenType() == "identifier")
					{
						//write to output
						this->output<<"    <identifier> ";
						this->output<<this->tokenizer.identifier();
						this->output<<" </identifier>"<<std::endl;

						//advance
						while (curentTokenType == symbol and currentToken == ",")
						{
							//write symbol to output
							//advance
							if currentTokenType == identifier
								//write to output
							else
								//break and abort
						}
						
						if currentTokenType == symbol and currentToken == ;
							//write to output
						
						else
							//abort
					}
					else
					{
						//abort
					}
				}
				else
				{
					//abort
				}
			}
			else
			{
				//abort
			}
		}
		else
		{
			//abort
		}
	}
	else
	{
		//abort
	}
	this->output<<"	</classVarDec> ";
}

void CompilationEngine::compileSubroutineDec();

void CompilationEngine::compileParameterList();

void CompilationEngine::compileSubroutineBody();

void CompilationEngine::compileVarDec();

void CompilationEngine::compileStatements();

void CompilationEngine::compileLet();

void CompilationEngine::compileIf();

void CompilationEngine::compileWhile();

void CompilationEngine::compileDo();

void CompilationEngine::compileReturn();

void CompilationEngine::compileExpression();

void CompilationEngine::compileTerm();

void CompilationEngine::compileExpressionList();