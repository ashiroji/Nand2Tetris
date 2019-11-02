#include "parser.h"
#include "CodeWriter.h"
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include <cstdio>

namespace fs = boost::filesystem;

void runner(parser& vmParser, CodeWriter& vmCodeWriter)
{
	std::string cType;
	std::string arg1;
	int arg2;

	do{
		vmParser.advance(); //read next command
		cType = vmParser.commandType();//extract command type
		//std::cout<<"current commmand :"<<vmParser.getCommand()<<std::endl;
		//std::cout<<"cType = "<<cType<<std::endl;
		//extract args
		if (cType == "C_PUSH" || cType == "C_POP" || cType == "C_FUNCTION" || cType == "C_CALL")
		{
			arg1 = vmParser.arg1(cType);
			arg2 = vmParser.arg2();
		
		} else if (cType == "C_RETURN"){
		
			arg1 = "";
			arg2 = 0;
		
		} else {
		
			arg1 = vmParser.arg1(cType);
		
		}

		//write code
		if (cType == "C_ARITHMETIC")
		{
		
			vmCodeWriter.writeArithmetic(vmParser.getCommand());
		
		}else if (cType == "C_PUSH" || cType == "C_POP") {

			vmCodeWriter.writePushPop(vmParser.getCommand(), arg1, vmParser.getFileName(),arg2);
		
		}else if (cType == "C_LABEL")
		{
			vmCodeWriter.writeLabel(arg1);
		}else if (cType == "C_IF")
		{
			vmCodeWriter.writeIf(arg1);

		}else if (cType == "C_GOTO")
		{
			vmCodeWriter.writeGoto(arg1);
		}else if (cType == "C_FUNCTION")
		{
			vmCodeWriter.writeFunction(arg1, arg2);
		}else if (cType == "C_RETURN")
		{
			vmCodeWriter.writeReturn();
		}else if (cType == "C_CALL")
		{
			vmCodeWriter.writeCall(arg1, arg2);
		}
	}while(vmParser.hasMoreCommands());

}
void handleFile(std::string fileName)
{
	//construct the parser and the codeWriter
	parser vmParser(fileName);
	CodeWriter vmCodeWriter(fileName);

	vmCodeWriter.writeInit();
	runner(vmParser, vmCodeWriter);

}

int handleDir(std::string dirName)
{

	fs::path full_path( fs::initial_path<fs::path>() );
	full_path = fs::system_complete( fs::path( dirName ) );

	std::map<std::string, std::string> paths;	
	std::size_t secondDelimeter = dirName.rfind('/'); //find first space or npos
	std::size_t firstDelimeter = dirName.rfind('/', secondDelimeter-1);
	std::string outputName = full_path.string() + dirName.substr(firstDelimeter+1, secondDelimeter - firstDelimeter-1 );

	CodeWriter vmCodeWriter(outputName);

	vmCodeWriter.writeInit();
					
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
					if (dir_itr->path().filename().string().find(".vm") != std::string::npos)
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

		/* handle sys.vm */
		std::cout<<"Parsing file "<<paths.at("Sys.vm")<<std::endl;
		parser sysParser(paths.at("Sys.vm"));
		runner(sysParser, vmCodeWriter);

		/* handle Main.vm*/
		if (paths.find("Main.vm") != paths.end())
		{
			std::cout<<"Parsing file "<<paths.at("Main.vm")<<std::endl;
			parser mainParser(paths.at("Main.vm"));
			runner(mainParser, vmCodeWriter);
		}
		/* handle the rest */
		for (auto& file: paths) 
		{
			if ((file.first != "Sys.vm") && (file.first != "Main.vm"))
			{
				std::cout<<"Parsing file "<<file.second<<std::endl;
				parser vmParser(file.second);
				runner(vmParser, vmCodeWriter);
			}
		    
  		}

	}
	return(0);
}

int main(int argc, char const *argv[])
{
	std::string name;
	std::ofstream output;

	if(argc > 1)
	{
		name = argv[1];
		//check that file name ends with .vm
		if(name.find(".vm") != std::string::npos)
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