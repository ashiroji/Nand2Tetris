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
	if (this->tokenizer.tokenType() != "keyword")
	{
		//abort
		std::cout<<"error didn't find class keyword"<<std::endl;
		return;
	}

	// the keyword must be class
	if (this->keyWord() == "class")
	{
		//write to output
		this->output<<"	<keyword> ";
		this->output<<tokenizer.keyWord();
		this->output<<" </keyword>"<<std::endl;
	} 
	else 
	{
		//abort
		std::cout<<"error : found a keyword but it's not class"<<std::endl;
		return;
	}	
	//advance
	this->tokenizer.advance();

	//next find the class name which is an identifier
	if (this->tokenizer.tokenType() == "identifier")
	{
		//write identifier to output
		this->output<<"	<identifier> ";
		this->output<<tokenizer.identifier();
		this->output<<" </identifier>"<<std::endl;				
	}
	else
	{
		//abort
		std::cout<<"error : didn't find identifier after class keyword"<<std::endl;
		return;
	}		

	//advance
	this->tokenizer.advance();
	
	//next we must find the opening {	
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == '{'))
	{
		//write to output
		tokenizerOutput<<"	<symbol> ";
		tokenizerOutput<<tokenizer.symbol();
		tokenizerOutput<<" </symbol>"<<std::endl;;
	}		
	else
	{
		//abort
		std::cout<<"error didn't find { symbol after class name"<<std::endl;
		return;
	}

	/*from here on treat the symbols as needed by calling 
	**appropriate functions
	loop over the file until no more tokens
	we can find classVarDeclarations or methods or nothing at all
	but in the end we must find the }
	*/
	do{
		this->tokenizer.advance(); //read next token

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
			(this->tokenizer.symbol() == '}'))
		{
			//end of the class }
			tokenizerOutput<<"	<symbol> ";
			tokenizerOutput<<tokenizer.symbol();
			tokenizerOutput<<" </symbol>"<<std::endl;
		}
		else
		{
			//abort
			std::cout<<"error found nothing after the opening { not even the closing }"<<std::endl;
			return;			
		}

	}while(tokenizer.hasMoreTokens());					

	//if we get here we compiled the class correctly
	this->output<<"</class>"<<std::endl;;

}

void CompilationEngine::compileClassVarDec()
{
	//static or field variables
	// static | field type varName,* ;
	this->output<<"	<classVarDec> ";
	
	//we must find a keyword
	if (this->tokenizer.tokenType() != "keyword")
	{
				//abort
		std::cout<<"error expecting a keyword here"<<std::endl;
		return;	
	}

	//we must find one the following keywords
	if ((this->tokenizer.keyWord() == "static") || 
		(this->tokenizer.keyWord() == "field"))
	{
		//write to output
		this->output<<"    <keyword> ";
		this->output<<this->tokenizer.keyword();
		this->output<<" </keyword>"<<std::endl;
	}
	else
	{
		std::cout<<"error, found a keyword but it's not static nor field"<<std::endl;
		return;
	}	
	//advance
	this->tokenizer.advance();

	//must find a keyword or an identifier
	if ((this->tokenizer.tokenType() !=  "keyword") && (this->tokenizer.tokenType() != "identifier"))
	{
		std::cout<<"error, found a token but it's not keyword nor identifier"<<std::endl;
		return;
	}
	
	// type must be  int or char or boolean or className(identifier)
	if ((this->tokenizer.keyWord() != "int") && 
		(this->tokenizer.keyWord() != "char") &&
		(this->tokenizer.keyWord() != "boolean") &
		(this->tokenizer.tokenType() != "identifier"))
	{
		std::cout<<"error, found a token but it's not a type"<<std::endl;
		return;		
	}
	//the Type is a known type
	if(this->tokenizer.tokenType() == "keyword")
	{
		this->output<<"    <keyword> ";
		this->output<<this->tokenizer.keyword();
		this->output<<" </keyword>"<<std::endl;
	}
	//the type is a className
	else{
		this->output<<"    <identifier> ";
		this->output<<this->tokenizer.identifier();
		this->output<<" </identifier>"<<std::endl;						
	}
	//advance
	this->tokenizer.advance();

	//must find an identifier => VarName
	if (this->tokenizer.tokenType() == "identifier")
	{
		//write to output
		this->output<<"    <identifier> ";
		this->output<<this->tokenizer.identifier();
		this->output<<" </identifier>"<<std::endl;
	}
	else
	{
		std::cout<<"error, found a token but it's not an identifier varName"<<std::endl;
		return;		
	}
	
	//advance
	this->tokenizer.advance();

	//now looking for (, VarName)* construct
	while ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == ','))
	{
		//write symbol to output
		tokenizerOutput<<"	<symbol> ";
		tokenizerOutput<<tokenizer.symbol();
		tokenizerOutput<<" </symbol>"<<std::endl;
		
		//advance
		this->tokenizer.advance();

		//must find a varName now
		if (this->tokenizer.tokenType() == "identifier")
		{
			tokenizerOutput<<"	<identifier> ";
			tokenizerOutput<<tokenizer.identifier();
			tokenizerOutput<<" </identifier>"<<std::endl;	
		}
		else
		{
			std::cout<<"error: found a , but not a second varName"<<std::endl;
			return;
		}

		//advance
		this->tokenizer.advance();
	}
	
	//must find end of line ;
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == ';'))
	{
		//write symbol to output
		tokenizerOutput<<"	<symbol> ";
		tokenizerOutput<<tokenizer.symbol();
		tokenizerOutput<<" </symbol>"<<std::endl;		
	}
	else
	{
		//abort
		std::cout<<"error didn't find end of line ; after classVarDec"<<std::endl;
		return;
	}

	this->output<<"	</classVarDec> ";
}

void CompilationEngine::compileSubroutineDec()
{

}

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