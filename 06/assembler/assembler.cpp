#include "symTable.h"
#include "code.h"
#include "parser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
int main(int argc, char const *argv[])
{
	std::string fileName;
	std::ofstream output;
	//read CLI to get file name
	if(argc > 1)
	{
		fileName = argv[1];
		//check that file name ends with .asm
		if(fileName.find(".asm") != std::string::npos)
		{
			//construct the parser and the code
			parser symParser(fileName);
			symTable symbolTable;

			std::string bin;
			std::string tempString;
			std::string cType;

			//first loop : build the symTable
			do{
				symParser.advance();
				cType = symParser.commandType();
				if(cType == "A_COMMAND" || cType == "C_COMMAND")
				{
					//increment rom address;
					symbolTable.incRom();
				}
				else if (cType == "L_COMMAND")
				{
					//new label : add it
					tempString = symParser.symbol(cType);
					symbolTable.addEntry(tempString, symbolTable.getRomAddress());
				}
			}while(symParser.hasMoreCommands());

			//second loop, translate and resolve syms
			symParser.~parser();
			parser newParser(fileName);
			code coder;
			//open the output file
			std::string outputName = fileName.replace(fileName.find("asm"),4,"hack");
			output.open(outputName.c_str());
			do {
				bin="";
				//advance in the file
				newParser.advance();
				//get the next command
				cType = newParser.commandType();
				//process the command
				if (cType == "A_COMMAND")
				{
					std::cout<<"A_COMMAND"<<std::endl;
					//extract the symbol
					tempString = newParser.symbol(cType);
					bool has_only_digits = (tempString.find_first_not_of( "0123456789" ) == std::string::npos);
					if(has_only_digits)
					{
						//convert it int
						int x =	std::stoi(tempString, nullptr);
						//convert it to binary
						bin = std::bitset<16>(x).to_string();
					}
					else
					{
						//check the symTable
						if(symbolTable.contains(tempString))
						{
							//found it, get the value , to bin
							int x = symbolTable.getAddress(tempString);
							bin = std::bitset<16>(x).to_string();				
						}
						else{
							//didn't find it => new var, add it
							symbolTable.addEntry(tempString, symbolTable.getRamAddress());
							symbolTable.incRam();
							//output is ram address the new var
							int x =symbolTable.getAddress(tempString);
							bin = std::bitset<16>(x).to_string();
						}
					}					

				}
				else if (cType == "C_COMMAND")
				{
					//extract the comp, dest and jmp
					std::cout<<"C_COMMAND"<<std::endl;
					tempString=newParser.comp();
					std::cout<<"parser comp result : "<<tempString<<std::endl;
					std::string compBin = coder.comp(tempString);
					std::cout<<"code comp result "<<compBin<<std::endl;

					tempString = newParser.dest();
					std::cout<<"parser dest result : "<<tempString<<std::endl;
					std::string destBin= coder.dest(tempString);
					std::cout<<"code dest result "<<destBin<<std::endl;

					tempString = newParser.jump();
					std::cout<<"parser jump result : "<<tempString<<std::endl;
					std::string jumpBin = coder.jump(tempString);
					std::cout<<"code jump result"<<jumpBin<<std::endl;

					bin = "111" + compBin + destBin + jumpBin;
				}
				else if (cType == "L_COMMAND")
				{
					std::cout<<"L_COMMAND"<<std::endl;
				}
				//write the string in the file
				if(!bin.empty())
				{
					bin+= "\n";
				}
				std::cout<<"bin : "<<bin;
				output<<bin;
			} while(newParser.hasMoreCommands());
		}
		else
		{
			std::cout<<"argument is not a valid .asm file"<<std::endl;
		}
	}
	else
	{
		std::cout<<"No args"<<std::endl;
	}

	output.close();	
	return 0;
}