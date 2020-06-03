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

/* this is the show runner, since everything is inside
** a class
** Indent Level 0
*/
void CompilationEngine::compileClass()
{
	//skip the comments
	this->advance();

	this->writeOpenMK("class", 0);

	//find a keyword in the start
	if (this->tokenizer.tokenType() != "keyword")
	{
		//abort
		std::cout<<"compileClass error :  didn't find class keyword"<<std::endl;
	}

	// the keyword must be class
	if (this->tokenizer.keyWord() == "class")
	{
		//write to output
		this->writeMKToFile(this->tokenizer.keyWord(),"keyword",1);

		//skip the comments
		this->advance();
	} 
	else 
	{
		//abort
		std::cout<<"compileClass error: found a keyword but it's not class"<<std::endl;
	}	

	//next find the class name which is an identifier
	if (this->tokenizer.tokenType() == "identifier")
	{
		//write identifier to output
		this->writeMKToFile(this->tokenizer.identifier(),"identifier",1);						

		//skip the comments
		this->advance();
	}
	else
	{
		//abort
		std::cout<<"compileClass error : didn't find identifier after class keyword"<<std::endl;
	}		

	
	//next we must find the opening {	
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == '{'))
	{
		//write to output
		this->writeMKToFile(this->tokenizer.symbol(),"symbol",1);

		//skip the comments
		this->advance();
	}		
	else
	{
		//abort
		std::cout<<"compileClass error didn't find { symbol after class name"<<std::endl;
	}

	/*from here on treat the symbols as needed by calling 
	**appropriate functions
	loop over the file until no more tokens
	we can find classVarDeclarations or methods or nothing at all
	but in the end we must find the }
	*/
	do{

		std::cout<<"compileClass currentToken : "<<this->tokenizer.getCurrentToken()<<std::endl;

		if (this->tokenizer.tokenType() == "keyword")
		{
			//classVarDec =>
			if((this->tokenizer.keyWord() == "static") 
				|| (this->tokenizer.keyWord() == "field"))
			{	
				this->compileClassVarDec();
				
				//skip the comments
				this->advance();

			}
			//subroutineDev
			else if((this->tokenizer.keyWord() == "constructor") 
					|| (this->tokenizer.keyWord() == "function")
					|| (this->tokenizer.keyWord() == "method"))
			{
				this->compileSubroutineDec();
				//skip the comments
				this->advance();
			}
		}
		else if ((this->tokenizer.tokenType() == "symbol") && 
			(this->tokenizer.symbol() == '}'))
		{
			//end of the class }
			this->writeMKToFile(this->tokenizer.symbol(),"symbol",1);
			this->writeCloseMK("class", 0);
			return;
		}
		else
		{
			//abort
			std::cout<<"compileClass error : found nothing after the opening { not even the closing }"<<std::endl;
			break;			
		}

	}while(this->tokenizer.hasMoreTokens());					
}

void CompilationEngine::compileClassVarDec()
{
	//static or field variables
	// static | field type varName,* ;
	this->writeOpenMK("classVarDec", 1);
	
	//we must find a keyword
	if (this->tokenizer.tokenType() != "keyword")
	{
		//abort
		std::cout<<"compileClassVarDec error expecting a keyword here"<<std::endl;	
	}

	//we must find one the following keywords
	if ((this->tokenizer.keyWord() == "static") || 
		(this->tokenizer.keyWord() == "field"))
	{
		//write to output
		this->writeMKToFile(this->tokenizer.keyWord(), "keyword", 2);

		//skip the comments
		this->advance();
	}
	else
	{
		std::cout<<"compileClassVarDec error, found a keyword but it's not static nor field"<<std::endl;
	}	

	//varDecLL
	this->compileVarDecLL(2);

	//must find end of line ;
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == ';'))
	{
		//write symbol to output
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", 2);		
	}
	else
	{
		//abort
		std::cout<<"compileClassVarDec error didn't find end of line ; after classVarDec"<<std::endl;
	}

	this->writeCloseMK("classVarDec", 1);
}


void CompilationEngine::compileSubroutineDec()
{
	this->writeOpenMK("subroutineDec", 1);
	//must find a keyword
	//we must find a keyword
	if (this->tokenizer.tokenType() != "keyword")
	{
		//abort
		std::cout<<"compileSubroutineDec error expecting a keyword here"<<std::endl;
	}

	// must find constructor, method or function
	if ((this->tokenizer.keyWord() == "constructor") || 
		(this->tokenizer.keyWord() == "method") ||
		(this->tokenizer.keyWord() == "function"))
	{
		//write to output
		this->writeMKToFile(this->tokenizer.keyWord(), "keyword", 2);

		//skip the comments
		this->advance();
	}
	else
	{
		std::cout<<"compileSubroutineDec error, found a keyword but it's not constructor, method or function"<<std::endl;
	}

	//must find a keyword or an identifier
	if ((this->tokenizer.tokenType() !=  "keyword") && (this->tokenizer.tokenType() != "identifier"))
	{
		std::cout<<"compileSubroutineDec error, found a token but it's not keyword nor identifier"<<std::endl;
	}

	//must find void or type
	if ((this->tokenizer.keyWord() != "int") && 
		(this->tokenizer.keyWord() != "char") &&
		(this->tokenizer.keyWord() != "boolean") &&
		(this->tokenizer.keyWord() != "void") &&
		(this->tokenizer.tokenType() != "identifier") )
	{
		std::cout<<"compileSubroutineDec error, found a token but it's not a type"<<std::endl;		
	}

	//the Type is a known type
	if(this->tokenizer.tokenType() == "keyword")
	{
		this->writeMKToFile(this->tokenizer.keyWord(), "keyword", 2);
	}
	//the type is a className
	else
	{
		this->writeMKToFile(this->tokenizer.identifier(), "identifier", 2);					
	}
	//skip the comments
	this->advance();

	//must find identifier as subroutine Name
	if (this->tokenizer.tokenType() == "identifier")
	{
		//write to output
		this->writeMKToFile(this->tokenizer.identifier(), "identifier", 2);
		
		//skip the comments
		this->advance();
	}
	else
	{
		std::cout<<"compileSubroutineDec error, found a token but it's not an identifier subroutine name"<<std::endl;	
	}

	//must find (
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == '('))
	{
		//write symbol to output
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", 2);		
	
		//skip the comments
		this->advance();
	}
	else
	{
		std::cout<<"compileSubroutineDec error didn't find opening ("<<std::endl;
	}
	
	//next is the Parameter List
	this->compileParameterList();
	
	//next is the closing )
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == ')'))
	{
		//write symbol to output
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", 2);		

		//skip the comments
		this->advance();
	}
	else
	{
		std::cout<<"compileSubroutineDec error didn't find closing )"<<std::endl;
	}

	//next is the subroutine body
	this->compileSubroutineBody();

	this->writeCloseMK("subroutineDec", 1);
}

void CompilationEngine::compileParameterList()
{
	//start the parameter list
	this->writeOpenMK("parameterList", 2);

	//no advance because we advanced after the reading the (
	// so now we will find a var declaration or the )

	//varDecLL
	this->compileVarDecLL(3);

	//or we find the ) symbol
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == ')'))
	{
		this->writeCloseMK("parameterList", 2);	
	}

}

void CompilationEngine::compileSubroutineBody()
{
	this->writeOpenMK("subroutineBody", 2);
	
	//find the opening {
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == '{'))
	{
		//write symbol to output
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", 3);

		//skip the comments
		this->advance();
	}
	else
	{
		//abort
		std::cout<<"compileSubroutineBody error didn't find opening {"<<std::endl;
	}

	//varDec
	while((this->tokenizer.tokenType()=="keyword") && (this->tokenizer.keyWord() == "var"))	
	{
		this->compileVarDec();
		std::cout<<"compileSubroutineBody : varDec : currentToken "<<this->tokenizer.getCurrentToken()<<std::endl;
	
		//skip the comments
		this->advance();

		std::cout<<"compileSubroutineBody : varDec : currentToken2 "<<this->tokenizer.getCurrentToken()<<std::endl;		
	}

	// no advancing in here either
	// last thing we treated is ; inside varDec
	// then we advanced in the while loop so it was 
	// stupid to advance again

	//statements
	this->compileStatements(3);
	// the advancing is done in the 
	// compileStatements

	//find the closing }
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == '}'))
	{
		//write symbol to output
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", 3);
	}
	else
	{
		//abort
		std::cout<<"compileSubroutineBody error didn't find closing }"<<std::endl;
	}

	this->writeCloseMK("subroutineBody", 2);	
}

void CompilationEngine::compileVarDec()
{
	//this is to handle multiline variable declarations
	// as all previous ones are single line
	//while the first token is a type
	//parse the variable declaration
	
	this->writeOpenMK("varDec", 3);
	
	if ((this->tokenizer.tokenType() == "keyword") && (this->tokenizer.keyWord() == "var"))
	{
		
		this->writeMKToFile(this->tokenizer.keyWord(), "keyword", 4);
		
		//skip the comments
		this->advance();

		while ((this->tokenizer.tokenType() == "keyword") || (this->tokenizer.tokenType() == "identifier"))
		{
			//the keyword must be a type
			// type must be  int or char or boolean or className(identifier)
			if ((this->tokenizer.keyWord() != "int") && 
				(this->tokenizer.keyWord() != "char") &&
				(this->tokenizer.keyWord() != "boolean") &&
				(this->tokenizer.tokenType() != "identifier"))
			{
				std::cout<<"compileVarDec error, found a token but it's not a type it's :"<<this->tokenizer.tokenType()<<std::endl;
				break;		
			}
			
			this->compileVarDecLL(4);

			//must find end of line ;
			if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == ';'))
			{
				//write symbol to output
				this->writeMKToFile(this->tokenizer.symbol(), "symbol", 4);		
			}
			else
			{
				//abort
				std::cout<<"compileVarDec error didn't find end of line ; after classVarDec"<<std::endl;
				break;
			}
			
		
		}
	}

	this->writeCloseMK("varDec", 3);
}

//all variable declaration (class, param or in subroutine)
// are the same except for the outer markups
// and the end of the line ; or ) 
void CompilationEngine::compileVarDecLL(int indentLevel)
{
	//do we find the construct type varName
	if ((this->tokenizer.tokenType() == "keyword") || (this->tokenizer.tokenType() == "identifier"))
	{
		//the keyword must be a type
		// type must be  int or char or boolean or className(identifier)
		if ((this->tokenizer.keyWord() != "int") && 
			(this->tokenizer.keyWord() != "char") &&
			(this->tokenizer.keyWord() != "boolean") &&
			(this->tokenizer.tokenType() != "identifier"))
		{
			std::cout<<"compileVarDec error, found a token but it's not a type"<<std::endl;		
		}
		//the Type is a known type
		if(this->tokenizer.tokenType() == "keyword")
		{
			this->writeMKToFile(this->tokenizer.keyWord(), "keyword", indentLevel);
		}
		//the type is a className
		else
		{
			this->writeMKToFile(this->tokenizer.identifier(), "identifier", indentLevel);						
		}

		//skip the comments
		this->advance();

		//must find an identifier => VarName
		if (this->tokenizer.tokenType() == "identifier")
		{
			//write to output
			this->writeMKToFile(this->tokenizer.identifier(), "identifier", indentLevel);
			//skip the comments
			this->advance();		
		}
		else
		{
			std::cout<<"compileVarDec error, found a token but it's not an identifier varName"<<std::endl;	
		}

		//now looking for (, type VarName)* construct
		// or (, varName)* construct
		while((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == ','))
		{
			//write symbol to output
			this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel);

			//skip the comments
			this->advance();

			//must find identifier or type + identifier
			while ((this->tokenizer.tokenType() == "keyword") || (this->tokenizer.tokenType() == "identifier"))
			{
				//the keyword must be a type
				// type must be  int or char or boolean or className(identifier)
				if ((this->tokenizer.keyWord() != "int") && 
					(this->tokenizer.keyWord() != "char") &&
					(this->tokenizer.keyWord() != "boolean") &&
					(this->tokenizer.tokenType() != "identifier"))
				{
					std::cout<<"compileVarDec error, found a token but it's not a type"<<std::endl;		
				}
				//the Type is a known type
				if(this->tokenizer.tokenType() == "keyword")
				{
					this->writeMKToFile(this->tokenizer.keyWord(), "keyword", indentLevel);
				}
				//the type is a className
				else
				{
					this->writeMKToFile(this->tokenizer.identifier(), "identifier", indentLevel);						
				}
				this->advance();
			}
		}
	}
}
void CompilationEngine::compileStatements(int indentLevel)
{
	/*	Read the current keyword
	*   if it's a statement start processing
	*	if not just return
	*/	
	this->writeOpenMK("statements", indentLevel);

	while(this->tokenizer.tokenType() == "keyword")
	{
		std::cout<<"compileStatements currentToken : "<<this->tokenizer.getCurrentToken()<<std::endl;
		//current keyword is let
		if(this->tokenizer.keyWord() == "let")
		{
			this->compileLet(indentLevel+1);
			
			//skip the comments
			this->advance();
		}

		//current keyword is if
		else if(this->tokenizer.keyWord() == "if")
		{
			this->compileIf(indentLevel+1);
			//exit advancing done in compileIf
		}

		//current keyword is while
		else if(this->tokenizer.keyWord() == "while")
		{
			this->compileWhile(indentLevel+1);
		
			//skip the comments
			this->advance();
		}

		//current keyword is do
		else if(this->tokenizer.keyWord() == "do")
		{
			this->compileDo(indentLevel+1);
		
			//skip the comments
			this->advance();
		}


		//current keyword is return
		else if(this->tokenizer.keyWord() =="return")
		{
			this->compileReturn(indentLevel+1);
	
			//skip the comments
			this->advance();
		}

		else
		{
			std::cout<<"compileStatements error"<<std::endl;
			std::cout<<"compileStatements currentToken1 : "<<this->tokenizer.getCurrentToken()<<std::endl;
			std::cout<<"compileStatements tokenType : "<<this->tokenizer.tokenType()<<std::endl;
			break;
		}

	}

	this->writeCloseMK("statements", indentLevel);
}

//let statement
// let varName ('[' expression ']')? '=' expression ;
void CompilationEngine::compileLet(int indentLevel)
{
	this->writeOpenMK("letStatement", indentLevel);

	//must find let keyword
	if(this->tokenizer.keyWord() == "let")
	{
		this->writeMKToFile(this->tokenizer.keyWord(), "keyword", indentLevel+1);
		
		//skip the comments
		this->advance();
	}
	else
	{
		std::cout<<"compileLet error : keyword is not let"<<std::endl;
	}


	if(this->tokenizer.tokenType() == "identifier")
	{
		this->writeMKToFile(this->tokenizer.identifier(), "identifier", indentLevel+1);			
	
		//skip the comments
		this->advance();
	}
	else
	{
		std::cout<<"compileLet error : did not find identifier var name"<<std::endl;
	}

	//we might find [expression] now
	if((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == '[')) 
	{
		//write symbol to output
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel+1);

		//skip the comments
		this->advance();

		//next we must find an expression
		this->compileExpression(5);
		
		//exit advancing done in compileExpression

		std::cout<<"compileLet currentToken : "<<this->tokenizer.getCurrentToken()<<std::endl;
		//next we must find closing ]
		if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == ']'))
		{
			//write symbol to output
			this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel+1);

			//skip the comments
			this->advance();
		}
		else
		{
			std::cout<<"compileLet error : found [ but not ]"<<std::endl;
		}
	}

	//next we must find the = symbol
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == '='))
	{
		//write symbol to output
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel+1);
		
		//skip the comments
		this->advance();
	}
	else
	{
		std::cout<<"compileLet error : = not found in letStatement"<<std::endl;
	}

	//must find an expression
	this->compileExpression(indentLevel+1);

	//exit advancing done in compileExpression

	std::cout<<"compileLet currentToken1 : "<<this->tokenizer.getCurrentToken()<<std::endl;	
	//must find ;
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == ';'))
	{
		//write symbol to output
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel+1);
	}
	else
	{
		std::cout<<"compileLet error : ; not found in letStatement"<<std::endl;
	}

	this->writeCloseMK("letStatement", indentLevel); 
}

//if (expression) { statements } else {statements}
void CompilationEngine::compileIf(int indentLevel)
{
	this->writeOpenMK("ifStatement", indentLevel);

	//must find if keyword
	if(this->tokenizer.keyWord() == "if")
	{
		this->writeMKToFile(this->tokenizer.keyWord(), "keyword", indentLevel+1);
	
		//skip the comments
		this->advance();
	}
	else
	{
		std::cout<<"compileIf error : keyword is not if"<<std::endl;
	}

	//we must find ( now
	if((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == '(')) 
	{
		//write symbol to output
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel+1);
	
		//skip the comments
		this->advance();
	}
	else
	{
		std::cout<<"compileIf error : didn't find ( in ifStatement"<<std::endl;
	}

	//must find an expression
	this->compileExpression(indentLevel+1);
	//exit advancing in compileExpression

	//must find )
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == ')'))
	{
		//write symbol to output
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel+1);

		//skip the comments
		this->advance();
	}
	else
	{
		std::cout<<"compileIf error : ) not found in ifStatement"<<std::endl;
	}

	//must find {
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == '{'))
	{
		//write symbol to output
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel+1);
		
		//skip the comments
		this->advance();
	}
	else
	{
		std::cout<<"compileIf error : { not found in ifStatement"<<std::endl;
	}

	//might find statements
	this->compileStatements(indentLevel+1);
	//exit advancing done in compileStatements


	//must find }
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == '}'))
	{
		//write symbol to output
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel+1);
		
		//skip the comments
		this->advance();
	}
	else
	{
		std::cout<<"compileIf error : } not found in ifStatement"<<std::endl;
	}

	//can find else
	if((this->tokenizer.tokenType() == "keyword") && (this->tokenizer.keyWord()=="else"))
	{
		this->writeMKToFile(this->tokenizer.keyWord(), "keyword", indentLevel+1);

		//skip the comments
		this->advance();

		//must find {
		if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == '{'))
		{
			//write symbol to output
			this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel+1);
			
			//skip the comments
			this->advance();
		}
		else
		{
			std::cout<<"compileIf error : { not found in elseStatement"<<std::endl;
		}

		//might find statements
		this->compileStatements(indentLevel+1);
		//exit advancing in compileStatements

		//must find }		
		if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == '}'))
		{
			//write symbol to output
			this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel+1);
			
			//skip the comments
			this->advance();
		}
		else
		{
			std::cout<<"compileIf error : } not found in elseStatement"<<std::endl;
		}
	}

	this->writeCloseMK("ifStatement", indentLevel);
}

//while (expression){statements}
void CompilationEngine::compileWhile(int indentLevel)
{
	this->writeOpenMK("whileStatement", indentLevel);
	
	//must find if keyword
	if(this->tokenizer.keyWord() == "while")
	{
		this->writeMKToFile(this->tokenizer.keyWord(), "keyword", indentLevel+1);
		
		//skip the comments
		this->advance();	
	}
	else
	{
		std::cout<<"compileWhile error : keyword is not while"<<std::endl;
	}

	//we must find ( now
	if((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == '(')) 
	{
		//write symbol to output
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel+1);
	
		//skip the comments
		this->advance();
	}
	else
	{
		std::cout<<"compileWhile error : didn't find ( in whileStatement"<<std::endl;
		
	}

	//must find an expression
	this->compileExpression(indentLevel+1);
	//exit advancing in compileExpression

	//must find )
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == ')'))
	{
		//write symbol to output
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel+1);

		//skip the comments
		this->advance();	
	}
	else
	{
		std::cout<<"compileWhile error : ) not found in whileStatement"<<std::endl;
	}

	//must find {
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == '{'))
	{
		//write symbol to output
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel+1);

		//skip the comments
		this->advance();
	}
	else
	{
		std::cout<<"compileWhile error : { not found in whileStatement"<<std::endl;
	}

	//might find statements
	this->compileStatements(indentLevel+1);
	//exit advancing in compileStatements

	//must find }
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == '}'))
	{
		//write symbol to output
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel+1);
	}
	else
	{
		std::cout<<"compileWhile error : } not found in whileStatement"<<std::endl;
	}

	this->writeCloseMK("whileStatement", indentLevel);
}
//do subroutineCall;
void CompilationEngine::compileDo(int indentLevel)
{
	this->writeOpenMK("doStatement", indentLevel);
	
	//must find do
	if(this->tokenizer.keyWord() == "do")
	{
		this->writeMKToFile(this->tokenizer.keyWord(), "keyword", indentLevel+1);
		
		//skip the comments
		this->advance();
	}
	else
	{
		std::cout<<"compileDo error : keyword is not do"<<std::endl;
	}

	//must find subroutineCall
	this->compileSubroutineCall(indentLevel+1);

	//skip the comments
	this->advance();

	//must find ;
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == ';'))
	{
		//write symbol to output
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel+1);
	}
	else
	{
		std::cout<<"compileDo error : ; not found in doStatement"<<std::endl;
	}

	this->writeCloseMK("doStatement", indentLevel);
}

//return expression ;
void CompilationEngine::compileReturn(int indentLevel)
{
	this->writeOpenMK("returnStatement", indentLevel);

	//must find if keyword
	if(this->tokenizer.keyWord() == "return")
	{
		this->writeMKToFile(this->tokenizer.keyWord(), "keyword", indentLevel+1);
		
		//skip the comments
		this->advance();
	}
	else
	{
		std::cout<<"compileReturn error : keyword is not return"<<std::endl;
	}

	//might find expression
	if((this->tokenizer.tokenType() != "symbol") || (this->tokenizer.symbol() != ';'))
	{
		this->compileExpression(indentLevel+1);
		//exit advancing in compileExpression
	}

	//must find ;
	if ((this->tokenizer.tokenType() == "symbol") && (this->tokenizer.symbol() == ';'))
	{
		//write symbol to output
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel+1);
	}
	else
	{
		std::cout<<"compileReturn error : ; not found in returnStatement"<<std::endl;
	}

	this->writeCloseMK("returnStatement", indentLevel);
}

// term (op term)*
// term and the rest is optional
void CompilationEngine::compileExpression(int indentLevel)
{
	this->writeOpenMK("expression", indentLevel);

	//must find a term
	this->compileTerm(indentLevel + 1);

	//skip the comments
	//this->advance();


	//might find op
	while ((this->tokenizer.tokenType()== "symbol") && (this->tokenizer.symbol() != ';') 
		&& (this->tokenizer.symbol() != '(') && (this->tokenizer.symbol() != ')')
		&& (this->tokenizer.symbol() != '[') && (this->tokenizer.symbol() != ']')
		&& (this->tokenizer.symbol() != '{') && (this->tokenizer.symbol() != '}'))
	{

		this->compileOp(indentLevel + 1);
		
		//skip the comments
		this->advance();

		//must find another term
		this->compileTerm(indentLevel + 1);

		//skip the comments
		//this->advance();
	}
	this->writeCloseMK("expression", indentLevel);
}

/* a term is one of the following
** integerConstant, stringConstant, keywordConstant,
** varName, varName[expression], subroutineCall,
** (expression), unaryOp term
*/
void CompilationEngine::compileTerm(int indentLevel)
{
	this->writeOpenMK("term", indentLevel);
	//integerConstant
	if (this->tokenizer.tokenType() == "int")
	{
		this->writeMKToFile(this->tokenizer.intVal(), "integerConstant", indentLevel + 1);
	}

	//string Constant
	if (this->tokenizer.tokenType() == "string")
	{
		this->writeMKToFile(this->tokenizer.stringVal(), "stringConstant", indentLevel + 1);
	}

	//keyWord Constant : true, false, null, this
	if ((this->tokenizer.tokenType() == "keyword") 
		&& (this->tokenizer.keyWord() == "true"))
	{
		this->writeMKToFile(this->tokenizer.keyWord(), "keyWord", indentLevel + 1);
	}

	if ((this->tokenizer.tokenType() == "keyword") 
		&& (this->tokenizer.keyWord() == "false"))
	{
		this->writeMKToFile(this->tokenizer.keyWord(), "keyWord", indentLevel + 1);
	}

	if ((this->tokenizer.tokenType() == "keyword") 
		&& (this->tokenizer.keyWord() == "null"))
	{
		this->writeMKToFile(this->tokenizer.keyWord(), "keyWord", indentLevel + 1);
	}

	if ((this->tokenizer.tokenType() == "keyword") 
		&& (this->tokenizer.keyWord() == "this"))
	{
		this->writeMKToFile(this->tokenizer.keyWord(), "keyWord", indentLevel + 1);
	}	

	//varName, varName[], subroutineCall
	if ((this->tokenizer.tokenType() == "identifier"))
	{
		// varName
		this->writeMKToFile(this->tokenizer.identifier(), "identifier", indentLevel + 1);
		
		//skip the comments
		this->advance();

		//if this token is [ or . or (
		if(this->tokenizer.tokenType() == "symbol")
		{
			if(this->tokenizer.symbol() == '[')
			{
				//it's an array
				//varName[expression]
				// [
				this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel + 1);
				
				//skip the comments
				this->advance();
				
				//expression indent 7 + 1				
				this->compileExpression(indentLevel+1);

				// ]
				if ((this->tokenizer.tokenType()=="symbol") 
					&& (this->tokenizer.symbol()==']'))
				{
					this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel + 1);
				}
				else
				{
					std::cout<<"compileTerm error : didn't find ] at the end of array use"<<std::endl;
				}

			}
			else if (this->tokenizer.symbol() == '(')
			{
				//it's a subroutine Call
				this->compileSubroutineCall(indentLevel+1);
			}
			else if (this->tokenizer.symbol()=='.')
			{
				//it's a subroutine Call
				//object.subroutine()

				//object
				this->writeMKToFile(this->tokenizer.identifier(), "identifier", indentLevel + 1);
				// .
				this->writeMKToFile(this->tokenizer.symbol(), "symbol", 7);

				//skip the comments
				this->advance();
				
				//subroutine name
				if (this->tokenizer.tokenType()!="identifier")
				{
					std::cout<<"compileTerm error : didn't find identifier after ."<<std::endl;
				}

				//it's a subroutine call
				this->compileSubroutineCall(indentLevel+1);
	
			}
		}
	}
	
	//(expression)
	if((this->tokenizer.tokenType()=="symbol") 
		&& (this->tokenizer.symbol()=='('))
	{
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel + 1);

		//skip the comments
		this->advance();

		this->compileExpression(indentLevel+1);
		// )
		if ((this->tokenizer.tokenType()=="symbol") 
			&& (this->tokenizer.symbol()==')'))
		{
			this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel + 1);
		}
		else
		{
			std::cout<<"compileTerm error : didn't find ) at the end of (expression)"<<std::endl;
		}
	}

	//unaryOp term
	if((this->tokenizer.tokenType()=="symbol") 
		&& ((this->tokenizer.symbol()=='-') || (this->tokenizer.symbol()=='~')))
	{
		//unaryOp
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel + 1);

		//skip the comments
		this->advance();

		//Term
		this->compileTerm(indentLevel+1);
	}

	this->writeCloseMK("term", indentLevel);
}

// (expression(, expression)*)?
void CompilationEngine::compileExpressionList(int indentLevel)
{
	this->writeOpenMK("expressionList", indentLevel);
	
	if ((this->tokenizer.tokenType()!="symbol") 
		|| (this->tokenizer.symbol()!=')'))
	{
		this->compileExpression(indentLevel+1);

		//might find ,
		while ((this->tokenizer.tokenType() == "symbol") 
			&& (this->tokenizer.symbol() == ','))
		{
			this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel+1);

			//skip the comments
			this->advance();

			this->compileExpression(indentLevel+1);
		}
	}

	this->writeCloseMK("expressionList", indentLevel);
}

void CompilationEngine::compileSubroutineCall(int indentLevel)
{
	//identifier(expressionList) or identifier.identifier(expressionList)

	//identifier
	if(this->tokenizer.tokenType() == "identifier")
	{
		this->writeMKToFile(this->tokenizer.identifier(), "identifier", indentLevel);
		//skip the comments
		this->advance();
	}
	else
	{
		std::cout<<"compileSubroutineCall error : no identifier found"<<std::endl;
	}

	//find .
	if (this->tokenizer.symbol() == '.')
	{
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel);
	
		//skip the comments
		this->advance();

		//find identifier
		if (this->tokenizer.tokenType()=="identifier")
		{
			//identifier
			this->writeMKToFile(this->tokenizer.identifier(), "identifier", indentLevel);
			
			//skip the comments
			this->advance();	
		}	
		else
		{
			std::cout<<"compileSubroutineCall error : didn't find identifier after . in subroutineCall"<<std::endl;
		}
	}
	// find (
	if ((this->tokenizer.tokenType()=="symbol") 
		&& (this->tokenizer.symbol()=='('))
	{
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel);
	
		//skip the comments
		this->advance();
	}	
	else
	{
		std::cout<<"compileSubroutineCall error : didn't find ( at the start of subroutineCall"<<std::endl;
	}
	
	//expressionList				
	this->compileExpressionList(indentLevel);

	// )
	if ((this->tokenizer.tokenType()=="symbol") 
		&& (this->tokenizer.symbol()==')'))
	{
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel);
	}
	else
	{
		std::cout<<"compileSubroutineCall error : didn't find ) at the end of subroutineCall"<<std::endl;
	}
}

// + - * / & | < > = 
void CompilationEngine::compileOp(int indentLevel)
{
	if((this->tokenizer.tokenType()=="symbol") 
		&& this->tokenizer.symbol() == '+')
	{
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel);
	}
	else if ((this->tokenizer.tokenType()=="symbol") 
		&& this->tokenizer.symbol() == '-')
	{
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel);
	}
	else if ((this->tokenizer.tokenType()=="symbol") 
		&& this->tokenizer.symbol() == '*')
	{
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel);
	}
	else if ((this->tokenizer.tokenType()=="symbol") 
		&& this->tokenizer.symbol() == '/')
	{
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel);
	}
	else if ((this->tokenizer.tokenType()=="symbol") 
		&& this->tokenizer.symbol() == '&')
	{
		this->writeMKToFile("&amp;", "symbol", indentLevel);
	}
	else if ((this->tokenizer.tokenType()=="symbol") 
		&& this->tokenizer.symbol() == '|')
	{
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel);
	}
	else if ((this->tokenizer.tokenType()=="symbol") 
		&& this->tokenizer.symbol() == '>')
	{
		this->writeMKToFile("&gt;", "symbol", indentLevel);
	}
	else if ((this->tokenizer.tokenType()=="symbol") 
		&& this->tokenizer.symbol() == '<')
	{
		this->writeMKToFile("&lt;", "symbol", indentLevel);
	}
	else if ((this->tokenizer.tokenType()=="symbol") 
		&& this->tokenizer.symbol() == '=')
	{
		this->writeMKToFile(this->tokenizer.symbol(), "symbol", indentLevel);
	}
	else 
	{
		std::cout<<"compileOp error : didn't find an operator"<<std::endl;
	}
}

void CompilationEngine::writeOpenMK(std::string type, int indentLevel)
{
	for (int i = 0; i < indentLevel; ++i)
	{
		this->output<<"  ";
	}
	this->output<<"<"<<type<<">"<<std::endl;
}

void CompilationEngine::writeCloseMK(std::string type, int indentLevel)
{
	for (int i = 0; i < indentLevel; ++i)
	{
		this->output<<"  ";
	}
	this->output<<"</"<<type<<">"<<std::endl;
}

template<typename T>
void CompilationEngine::writeMKToFile(T variable, std::string type, int indentLevel)
{
	for (int i = 0; i < indentLevel; ++i)
	{
		this->output<<"  ";
	}
	this->output<<"<"<<type<<">";
	this->output<<variable;
	this->output<<"</"<<type<<">"<<std::endl;
}

void CompilationEngine::advance()
{
	this->tokenizer.advance();
	while((this->tokenizer.tokenType() == "no_token") && (this->tokenizer.hasMoreTokens()))
	{
		this->tokenizer.advance();
	}	
}