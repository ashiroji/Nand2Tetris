/* -lboost_system -lboost_filesystem*/
#include "Tokenizer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include <cstdio>

namespace fs = boost::filesystem;

void runner(Tokenizer& tokenizer, std::string fileName)
{
	std::string cType;
	std::ofstream tokenizerOutput(fileName+"T.xml");

	tokenizerOutput<<"<tokens>"<<std::endl;
	
	do{
		tokenizer.advance(); //read next command
		cType = tokenizer.tokenType();//extract command type
		std::cout<<"current Token3 : "<<tokenizer.getCurrentToken()<<std::endl;
		std::cout<<"token type: "<<cType<<std::endl;
		if(cType == "keyword")
		{
				tokenizerOutput<<"<keyword> ";
				tokenizerOutput<<tokenizer.keyWord();
				tokenizerOutput<<" </keyword>"<<std::endl;
		}
		else if (cType == "symbol")
		{
				tokenizerOutput<<"<symbol> ";
				if('<' == tokenizer.symbol())
				{
					tokenizerOutput<<"&lt;";
				}
				else if ('>' == tokenizer.symbol())
				{
					tokenizerOutput<<"&gt;";
				}
				else if('&' == tokenizer.symbol())
				{
					tokenizerOutput<<"&amp;";
				}
				else if('\"' == tokenizer.symbol())
				{
					tokenizerOutput<<"&quot";
				}
				else
				{
					tokenizerOutput<<tokenizer.symbol();
				}
				tokenizerOutput<<" </symbol>"<<std::endl;;
		}
		else if (cType == "int")
		{
				tokenizerOutput<<"<integerConstant> ";
				tokenizerOutput<<tokenizer.intVal();
				tokenizerOutput<<" </integerConstant>"<<std::endl;;
		}
		else if (cType == "string")
		{
				tokenizerOutput<<"<stringConstant> ";
				tokenizerOutput<<tokenizer.stringVal();
				tokenizerOutput<<" </stringConstant>"<<std::endl;;
		}
		else if (cType == "identifier")
		{
				tokenizerOutput<<"<identifier> ";
				tokenizerOutput<<tokenizer.identifier();				
				tokenizerOutput<<"</identifier>"<<std::endl;;
		}

	}while(tokenizer.hasMoreTokens());

	tokenizerOutput<<"</tokens>"<<std::endl;
	tokenizerOutput.close();
}
void handleFile(std::string fileName)
{
	//construct the parser and the codeWriter
	Tokenizer tokenizer(fileName);
	runner(tokenizer, fileName);

}

int handleDir(std::string dirName)
{

	fs::path full_path( fs::initial_path<fs::path>() );
	full_path = fs::system_complete( fs::path( dirName ) );

	std::map<std::string, std::string> paths;	
	std::size_t secondDelimeter = dirName.rfind('/'); //find first space or npos
	std::size_t firstDelimeter = dirName.rfind('/', secondDelimeter-1);
	std::string outputName = full_path.string() + dirName.substr(firstDelimeter+1, secondDelimeter - firstDelimeter-1 );
	std::cout<<"outputName = "<<outputName<<std::endl;				
	//vmCodeWriter.writeInit();
	if ( !fs::exists( full_path ) )
	{
		std::cout << "\nNot found: " << full_path.string() << std::endl;
		return -1;	
	}

	if ( fs::is_directory( full_path ) )
	{
		std::cout << "\nIn directory: "
		          << full_path.string() << "\n\n";
		fs::directory_iterator end_iter;
		for ( fs::directory_iterator dir_itr( full_path );
		      dir_itr != end_iter;
		      ++dir_itr )
		{
			try
			{
				if ( fs::is_regular_file( dir_itr->status() ) )
				{
					if (dir_itr->path().filename().string().find(".jack") != std::string::npos)
					{
						std::cout<<"full path file : "<<full_path.string()+dir_itr->path().filename().string()<<std::endl;
						paths.emplace(dir_itr->path().filename().string(), full_path.string()+dir_itr->path().filename().string());
					}
				}
			}
			catch ( const std::exception & ex )
			{
				std::cout << dir_itr->path().filename() << " " << ex.what() << std::endl;
			}
		}


		/* handle Main.jack*/
		if (paths.find("Main.jack") != paths.end())
		{
			std::cout<<"Parsing file "<<paths.at("Main.jack")<<std::endl;
			Tokenizer tokenizer(paths.at("Main.jack"));
			runner(tokenizer, paths.at("Main.jack"));
		}
		/* handle the rest */
		for (auto& file: paths) 
		{
			if (file.first != "Main.jack")
			{
				std::cout<<"Parsing file "<<file.second<<std::endl;
				Tokenizer tokenizer(file.second);
				runner(tokenizer, file.second);
			}
		    
  		}

	}
	return(0);
}

int main(int argc, char const *argv[])
{
	std::string name;

	if(argc > 1)
	{
		name = argv[1];
		//check that file name ends with .jack
		if(name.find(".jack") != std::string::npos)
		{
			handleFile(name);		
		} else {
		
			handleDir(name);		
		}
	
	} else {
		
			std::cout<<"error no arguments found!"<<std::endl;
	
	}
	return 0;
}