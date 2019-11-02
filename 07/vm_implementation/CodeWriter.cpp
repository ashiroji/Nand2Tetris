#include "CodeWriter.h"


CodeWriter::CodeWriter(std::string outputFileName)
{

	this->setFileName(outputFileName);
	this->output.open(this->fileName.c_str());

	if(!(this->output.is_open()))
	{
		std::cout<<"Writer : failed to open file"<<std::endl;
		std::cout<<outputFileName<<std::endl;
	}
}

CodeWriter::~CodeWriter()
{
	this->output.close();
}

void CodeWriter::setFileName(std::string name)
{
	if(name.find(".vm") != std::string::npos)
	{
		name = name.erase(name.find(".vm"));
	}
	name = name.append(".asm");

	this->fileName = name;
}

std::string CodeWriter::getFileName()
{
	return (this->fileName.substr(this->fileName.rfind('/')+1));
}
void CodeWriter::writeArithmetic(std::string command)
{
	static int replica = 0;
	std::string label = "L" + std::to_string(replica);
	std::string end = "END" + std::to_string(replica);
	this->output<<"//"<<command<<std::endl;

	if(command == "add")
	{
		this->output<<"\t@SP"<<std::endl;
		this->output<<"\tAM=M-1\t//AM[SP] = M[SP] - 1 e.g @y"<<std::endl;

		this->output<<"\tD=M\t//D=M[A] e.g y"<<std::endl;
		this->output<<"\tA=A-1\t//A = @y - 1 e.g @x"<<std::endl;
		this->output<<"\tM=D+M\t//M[@x] = y + M[@x]"<<std::endl;	
	}
	else if (command == "sub")
	{
		this->output<<"\t@SP"<<std::endl;
		this->output<<"\tAM=M-1\t//AM[SP] = M[SP] - 1 e.g @y"<<std::endl;

		this->output<<"\tD=-M\t//D=-M[A] e.g -y"<<std::endl;
		this->output<<"\tA=A-1\t//A = @y - 1 e.g @x"<<std::endl;
		this->output<<"\tM=D+M\t//M[@x] = -y + M[@x]"<<std::endl;
	}
	else if(command == "neg")
	{
		this->output<<"\t@SP"<<std::endl;
		this->output<<"\tA=M-1\t//A = M[SP] - 1 e.g @y"<<std::endl;
		
		this->output<<"\tM=-M\t//M[A]=-M[A] e.g -y"<<std::endl;		
	}
	else if (command == "eq")
	{
		this->output<<"\t@SP"<<std::endl;
		this->output<<"\tAM=M-1\t//AM[SP] = M[SP] - 1 e.g @y"<<std::endl;
		this->output<<"\tD=M\t//D = M[@y] e.g y"<<std::endl;
		
		this->output<<"\t@R13"<<std::endl;
		this->output<<"\tM=D\t//R13 = D e.g y"<<std::endl;
		
		this->output<<"\t@SP"<<std::endl;
		this->output<<"\tAM=M-1\t//AM[SP] = M[SP] - 1 e.g @x"<<std::endl;
		this->output<<"\tD=M\t//D = M[@x] e.g x"<<std::endl;
		
		this->output<<"\t@R13"<<std::endl;
		this->output<<"\tD=D-M\t//D = D - R13 e.g x = x-y"<<std::endl;
		
		this->output<<"\t@"<<label<<std::endl;
		this->output<<"\tD;JEQ\t//if D == 0 jump to "<<label<<std::endl;
		
		this->output<<"\t@SP\t//else put 0 in @x"<<std::endl;
		this->output<<"\tA=M\t//A = M[SP] e.g @x"<<std::endl;
		this->output<<"\tM=0\t//M[A] = 0 e.g @x = false"<<std::endl;
		
		this->output<<"\t@"<<end<<std::endl;
		this->output<<"\t0;JMP\t//jump to end"<<std::endl;
		this->output<<"("<<label<<")"<<std::endl;
		
		this->output<<"\t@SP\t//JEQ target code"<<std::endl;
		this->output<<"\tA=M\t//A=M[SP] e.g @x"<<std::endl;
		this->output<<"\tM=-1\t//M[A] = -1 e.g @x = true"<<std::endl;
		this->output<<"("<<end<<")"<<std::endl;

		this->output<<"\t@SP"<<std::endl;
		this->output<<"\tM=M+1\t//M[SP] = M[SP] + 1 e.g @y"<<std::endl;			
	}
	else if (command == "gt")
	{
		this->output<<"\t@SP"<<std::endl;
		this->output<<"\tAM=M-1\t//AM[SP] = M[SP] - 1 e.g @y"<<std::endl;
		this->output<<"\tD=M\t//D = M[@y] e.g y"<<std::endl;
		
		this->output<<"\t@R13"<<std::endl;
		this->output<<"\tM=D\t//R13 = D e.g y"<<std::endl;
		
		this->output<<"\t@SP"<<std::endl;
		this->output<<"\tAM=M-1\t//AM[SP] = M[SP] - 1 e.g @x"<<std::endl;
		this->output<<"\tD=M\t//D = M[@x] e.g x"<<std::endl;
		
		this->output<<"\t@R13"<<std::endl;
		this->output<<"\tD=D-M\t//D = D - R13 e.g x = x-y"<<std::endl;
		
		this->output<<"\t@"<<label<<std::endl;
		this->output<<"\tD;JGT\t//if D > 0 jump to "<<label<<std::endl;
		
		this->output<<"\t@SP\t//else put 0 in @x"<<std::endl;
		this->output<<"\tA=M\t//A = M[SP] e.g @x"<<std::endl;
		this->output<<"\tM=0\t//M[A] = 0 e.g @x = false"<<std::endl;
		
		this->output<<"\t@"<<end<<std::endl;
		this->output<<"\t0;JMP\t//jump to end"<<std::endl;
		this->output<<"("<<label<<")"<<std::endl;
		
		this->output<<"\t@SP\t//JGT target code"<<std::endl;
		this->output<<"\tA=M\t//A=M[SP] e.g @x"<<std::endl;
		this->output<<"\tM=-1\t//M[A] = -1 e.g @x = true"<<std::endl;
		this->output<<"("<<end<<")"<<std::endl;

		this->output<<"\t@SP"<<std::endl;
		this->output<<"\tM=M+1\t//M[SP] = M[SP] + 1 e.g @y"<<std::endl;					
	}
	else if (command == "lt")
	{
		this->output<<"\t@SP"<<std::endl;
		this->output<<"\tAM=M-1\t//AM[SP] = M[SP] - 1 e.g @y"<<std::endl;
		this->output<<"\tD=M\t//D = M[@y] e.g y"<<std::endl;
		
		this->output<<"\t@R13"<<std::endl;
		this->output<<"\tM=D\t//R13 = D e.g y"<<std::endl;
		
		this->output<<"\t@SP"<<std::endl;
		this->output<<"\tAM=M-1\t//AM[SP] = M[SP] - 1 e.g @x"<<std::endl;
		this->output<<"\tD=M\t//D = M[@x] e.g x"<<std::endl;
		
		this->output<<"\t@R13"<<std::endl;
		this->output<<"\tD=D-M\t//D = D - R13 e.g x = x-y"<<std::endl;
		
		this->output<<"\t@"<<label<<std::endl;
		this->output<<"\tD;JLT\t//if D < 0 jump to "<<label<<std::endl;
		
		this->output<<"\t@SP\t//else put 0 in @x"<<std::endl;
		this->output<<"\tA=M\t//A = M[SP] e.g @x"<<std::endl;
		this->output<<"\tM=0\t//M[A] = 0 e.g @x = false"<<std::endl;
		
		this->output<<"\t@"<<end<<std::endl;
		this->output<<"\t0;JMP\t//jump to end"<<std::endl;
		this->output<<"("<<label<<")"<<std::endl;
		
		this->output<<"\t@SP\t//JLT target code"<<std::endl;
		this->output<<"\tA=M\t//A=M[SP] e.g @x"<<std::endl;
		this->output<<"\tM=-1\t//M[A] = -1 e.g @x = true"<<std::endl;
		this->output<<"("<<end<<")"<<std::endl;

		this->output<<"\t@SP"<<std::endl;
		this->output<<"\tM=M+1\t//M[SP] = M[SP] + 1 e.g @y"<<std::endl;		
	}
	else if (command == "and")
	{
		this->output<<"\t@SP"<<std::endl;
		this->output<<"\tAM=M-1\t//AM[SP] = M[SP] - 1 e.g @y"<<std::endl;

		this->output<<"\tD=M\t//D = M[@y] e.g y"<<std::endl;
		this->output<<"\tA=A-1\t//@y = @y - 1 e.g @x"<<std::endl;
		this->output<<"\tM=D&M\t//M[@x] = y & M[@x]"<<std::endl;		
	}
	else if (command == "or")
	{
		this->output<<"\t@SP"<<std::endl;
		this->output<<"\tAM=M-1\t//AM[SP] = M[SP] - 1 e.g @y"<<std::endl;

		this->output<<"\tD=M\t//D = M[@y] e.g y"<<std::endl;
		this->output<<"\tA=A-1//@y = @y - 1 e.g @x"<<std::endl;
		this->output<<"\tM=D|M\t//M[@x] = y | M[@x]"<<std::endl;
	}
	else if (command == "not")
	{
		this->output<<"\t@SP"<<std::endl;
		this->output<<"\tA=M-1\t//A = M[SP] - 1 e.g @y"<<std::endl;
		
		this->output<<"\tM=!M\t//M[@y] = !M[@y] e.g !y"<<std::endl;				
	}
	replica++;
}

void CodeWriter::writePushPop(std::string command, std::string segment, std::string fileName,int index)
{

	this->output<<"//"<<command<<std::endl;

	//std::cout<<"command : "<<command<<std::endl;
	//std::cout<<"segment : "<<segment<<std::endl;
	std::string segmentHandle = "";

	if (segment == "static")
	{
	
		segmentHandle += "\t@static." + fileName + "." + (std::to_string(index)) + "\t//the static variable location\n";
		segmentHandle += "\tD=A\t//D =@static."+(std::to_string(index))+" => the static value location\n";

	}
	else if (segment == "this")
	{
		segmentHandle = "\t@THIS\t//A=THIS\n";
		segmentHandle += "\tD=M\t//save M[this] in D\n";
		segmentHandle += "\t@"+std::to_string(index)+"\t//A = index\n";
		segmentHandle += "\tD=D+A\t//D is now @(this + index)\n";
	}
	else if (segment == "local")
	{
		segmentHandle = "\t@LCL\t//A=LCL\n";
		segmentHandle += "\tD=M\t//save M[local] in D\n";
		segmentHandle += "\t@"+std::to_string(index)+"\t//A = index\n";
		segmentHandle += "\tD=D+A\t//D is now @(local + index)\n";
	}
	else if (segment == "argument")
	{
		segmentHandle = "\t@ARG\t//A=ARG\n";
		segmentHandle += "\tD=M\t//save M[argument] in D\n";
		segmentHandle += "\t@"+std::to_string(index)+"\t//A = index\n";
		segmentHandle += "\tD=D+A\t//D is now @(argument + index)\n";
	}
	else if (segment == "that")
	{
		segmentHandle = "\t@THAT\t//A=THAT\n";
		segmentHandle += "\tD=M\t//save M[that] in D\n";
		segmentHandle += "\t@"+std::to_string(index)+"\t//A = index\n";
		segmentHandle += "\tD=D+A\t//D is now @(that + index)\n";
	}
	else if (segment == "constant")
	{
		segmentHandle = "\t@"+std::to_string(index)+"\t//A=index\n";	
		segmentHandle += "\tD=A\t//D is now the constant\n";
	}
	else if (segment == "pointer")
	{
		index = 3 + index;
		segmentHandle = "\t@" + (std::to_string(index)) + "\t//A = RAM @" + (std::to_string(index))+"\n";
		segmentHandle +="\tD=A\t//D is now @pointer + index\n";
	}
	else if (segment == "temp")
	{
		index = 5 + index;
		segmentHandle = "\t@R"+std::to_string(index)+"\t//A = RAM @\n";
		segmentHandle +="\tD=A\t//D is now @temp + index\n";
	}

	if(command.find("push")!= std::string::npos)
	{
		//std::cout<<"pushing"<<std::endl;
		//segment to stack
		this->output<<segmentHandle;
		
		if(segment !="constant")
		{
			this->output<<"\tA=D\t//A = @ contained in D"<<std::endl;
			this->output<<"\tD=M//D=M[A], value to push"<<std::endl;
		}
		this->output<<"\t@SP"<<std::endl;
		this->output<<"\tA=M\t//A = @SP"<<std::endl;
		this->output<<"\tM=D\t//M[A] = value to push"<<std::endl;
		
		this->output<<"\t@SP"<<std::endl;
		this->output<<"\tM=M+1\t//sp+1"<<std::endl;
	}
	else if (command.find("pop") != std::string::npos)
	{
		//std::cout<<"poping"<<std::endl;
		//stack to memory segment
		this->output<<"\t@SP"<<std::endl;
		this->output<<"\tAM=M-1\t//AM = M[SP] - 1"<<std::endl;
		this->output<<"\tD=M\t//D = the value to pop"<<std::endl;

		this->output<<"\t@R13"<<std::endl;
		this->output<<"\tM=D\t//save the value in R13"<<std::endl;
		
		this->output<<segmentHandle;
		
		this->output<<"\t@R14"<<std::endl;
		this->output<<"\tM=D\t//save D value"<<std::endl;
		
		this->output<<"\t@R13"<<std::endl;
		this->output<<"\tD=M\t//D= value to pop"<<std::endl;
		
		this->output<<"\t@R14"<<std::endl;
		this->output<<"\tA=M\t//A = (segmentBase+index)"<<std::endl;
		this->output<<"\tM=D\t//M[A] = value to pop"<<std::endl;
	}
}

void CodeWriter::closeFile()
{
	this->output.close();
}

void CodeWriter::writeInit()
{
	//init the stack to 256
	this->output<<"//bootstrap code"<<std::endl;
	this->output<<"\t@256"<<std::endl;
	this->output<<"\tD=A\t//D = 256"<<std::endl;
	this->output<<"\t@SP"<<std::endl;
	this->output<<"\tM=D\t//M[SP] = 256"<<std::endl;
	//call Sys.init
	this->writeCall("Sys.init", 0);
}

void CodeWriter::writeLabel(std::string label)
{
	//label in assembly is (label)
	this->output<<"//label "<<label<<std::endl;
	this->output<<"("<<label<<")\t//label declaration"<<std::endl;
}

void CodeWriter::writeGoto(std::string label)
{
	//unconditional jump is @label followed by 0;jmp
	this->output<<"//goto "<<label<<std::endl;
	this->output<<"\t@"<<label<<"//label to go to"<<std::endl;
	this->output<<"\t0;JMP\t//unconditional jump"<<std::endl;
}

void CodeWriter::writeIf(std::string label)
{
	//pop stack, if != 0 go to label 
	//pop stack
	this->output<<"//if-goto "<<label<<std::endl;
	this->output<<"\t@SP"<<std::endl;
	this->output<<"\tAM=M-1\t//AM = M[SP] - 1"<<std::endl;
	this->output<<"\tD=M\t//D = the value to pop"<<std::endl;
	
	//compare with 0 and jmp or not
	this->output<<"\t@"<<label<<std::endl;
	this->output<<"\tD;JNE\t//if D != 0 jump to "<<label<<std::endl;
}

void CodeWriter::writeCall(std::string functionName, int numArgs)
{
	static int replica=0;
	std::string label = "returnAddress"+std::to_string(replica);
	replica++;
	//push returnAddress
	this->output<<"//push returnAddress"<<std::endl;
	this->output<<"\t@"<<label<<std::endl;
	this->output<<"\tD=A\t//D="<<label<<std::endl;
	this->output<<"\t@SP"<<std::endl;
	this->output<<"\tA=M\t//A = @SP"<<std::endl;
	this->output<<"\tM=D\t//M[A] = value to push"<<std::endl;	
	this->output<<"\t@SP"<<std::endl;
	this->output<<"\tM=M+1\t//sp+1"<<std::endl;

	//push LCL
	this->output<<"//push LCL"<<std::endl;
	this->output<<"\t@LCL"<<std::endl;
	this->output<<"\tD=M\t//D=LCL"<<std::endl;
	this->output<<"\t@SP"<<std::endl;
	this->output<<"\tA=M\t//A = @SP"<<std::endl;
	this->output<<"\tM=D\t//M[A] = value to push"<<std::endl;	
	this->output<<"\t@SP"<<std::endl;
	this->output<<"\tM=M+1\t//sp+1"<<std::endl;
	
	//push ARG
	this->output<<"//push ARG"<<std::endl;
	this->output<<"\t@ARG"<<std::endl;
	this->output<<"\tD=M\t//D=ARG"<<std::endl;
	this->output<<"\t@SP"<<std::endl;
	this->output<<"\tA=M\t//A = @SP"<<std::endl;
	this->output<<"\tM=D\t//M[A] = value to push"<<std::endl;	
	this->output<<"\t@SP"<<std::endl;
	this->output<<"\tM=M+1\t//sp+1"<<std::endl;

	//push THIS
	this->output<<"//push THIS"<<std::endl;
	this->output<<"\t@THIS"<<std::endl;
	this->output<<"\tD=M\t//D=THIS"<<std::endl;
	this->output<<"\t@SP"<<std::endl;
	this->output<<"\tA=M\t//A = @SP"<<std::endl;
	this->output<<"\tM=D\t//M[A] = value to push"<<std::endl;	
	this->output<<"\t@SP"<<std::endl;
	this->output<<"\tM=M+1\t//sp+1"<<std::endl;

	//push THAT
	this->output<<"//push THAT"<<std::endl;
	this->output<<"\t@THAT"<<std::endl;
	this->output<<"\tD=M\t//D=THAT"<<std::endl;
	this->output<<"\t@SP"<<std::endl;
	this->output<<"\tA=M\t//A = @SP"<<std::endl;
	this->output<<"\tM=D\t//M[A] = value to push"<<std::endl;	
	this->output<<"\t@SP"<<std::endl;
	this->output<<"\tM=M+1\t//sp+1"<<std::endl;	

	//ARG = SP - nArgs - 5
	this->output<<"//ARG = SP - nArgs - 5"<<std::endl;
	this->output<<"\t@SP"<<std::endl;
	this->output<<"\tD=M\t//D=SP"<<std::endl;
	this->output<<"\t@"<<numArgs<<std::endl;
	this->output<<"\tD=D-A\t//D = SP-nArgs"<<std::endl;
	this->output<<"\t@5"<<std::endl;
	this->output<<"\tD=D-A\t//D=SP-5"<<std::endl;
	this->output<<"\t@ARG"<<std::endl;
	this->output<<"\tM=D\t//ARG= SP - nArgs -5"<<std::endl;

	//LCL = SP
	this->output<<"//LCL = SP"<<std::endl;
	this->output<<"\t@SP"<<std::endl;
	this->output<<"\tD=M\t//D=SP"<<std::endl;
	this->output<<"\t@LCL"<<std::endl;
	this->output<<"\tM=D\t//LCL = SP"<<std::endl;

	//goto g
	this->writeGoto(functionName);
	
	//returnAddress : the generated symbol	
	this->writeLabel(label);
}

void CodeWriter::writeReturn()
{
	//frame = LCL
	this->output<<"//return instruction"<<std::endl;
	this->output<<"//frame = LCL"<<std::endl;
	this->output<<"\t@LCL\t//A=LCL"<<std::endl;
	this->output<<"\tD=M\t//D=LCL"<<std::endl;
	this->output<<"\t@frame\t//frame is a variable"<<std::endl;
	this->output<<"\tM=D\t//frame = LCL"<<std::endl;
	
	//retAddr = *(frame - 5)
	this->output<<"//retAddr = *(frame - 5)"<<std::endl;
	this->output<<"\t@5\t//A=5"<<std::endl;
	this->output<<"\tD=D-A\t//D = frame - 5"<<std::endl;
	this->output<<"\tA=D\t//A = D = @retAddr"<<std::endl;
	this->output<<"\tD=M\t//D=M[A] = retAddr"<<std::endl;
	this->output<<"\t@retAddr\t//retAddr is a variable"<<std::endl;
	this->output<<"\tM=D\t//retAddr = frame - 5"<<std::endl;

	//*ARG = pop argument 0
	this->output<<"//*ARG = pop argument 0"<<std::endl;
	this->writePushPop("pop argument 0", "argument","", 0);
	
	//SP = ARG + 1
	this->output<<"//SP = ARG-1"<<std::endl;
	this->output<<"\t@ARG"<<std::endl;
	this->output<<"\tD=M\t// D = ARG"<<std::endl;
	this->output<<"\t@SP"<<std::endl;
	this->output<<"\tM=D+1\t//SP=ARG+1"<<std::endl;

	//THAT = *(frame - 1)
	this->output<<"//THAT = *(frame-1)"<<std::endl;
	this->output<<"\t@frame"<<std::endl;
	this->output<<"\tA=M-1\t//A = frame-1"<<std::endl;
	this->output<<"\tD=M\t//D=M[frame-1]"<<std::endl;
	this->output<<"\t@THAT"<<std::endl;
	this->output<<"\tM=D\t//THAT = *(frame-1)"<<std::endl;

	//THIS = *(frame - 2)
	this->output<<"//THIS = *(frame-2)"<<std::endl;
	this->output<<"\t@frame"<<std::endl;
	this->output<<"\tD=M\t//D=frame"<<std::endl;
	this->output<<"\t@2"<<std::endl;
	this->output<<"\tA=D-A\t//A=frame-2"<<std::endl;
	this->output<<"\tD=M\t//D = M[frame-2]"<<std::endl;
	this->output<<"\t@THIS"<<std::endl;
	this->output<<"\tM=D\t//THIS = *(frame-2)"<<std::endl;

	//ARG = *(frame - 3)
	this->output<<"//ARG = *(frame-3)"<<std::endl;
	this->output<<"\t@frame"<<std::endl;
	this->output<<"\tD=M\t//D=frame"<<std::endl;
	this->output<<"\t@3"<<std::endl;
	this->output<<"\tA=D-A\t//A=frame-3"<<std::endl;
	this->output<<"\tD=M\t//D = M[frame-3]"<<std::endl;
	this->output<<"\t@ARG"<<std::endl;
	this->output<<"\tM=D\t//ARG = frame-3"<<std::endl;

	//LCL = *(frame -4)
	this->output<<"//LCL = *(frame-4)"<<std::endl;
	this->output<<"\t@frame"<<std::endl;
	this->output<<"\tD=M\t//D=frame"<<std::endl;
	this->output<<"\t@4"<<std::endl;
	this->output<<"\tA=D-A\t//A=frame-4"<<std::endl;
	this->output<<"\tD=M\t//D = M[frame-4]"<<std::endl;
	this->output<<"\t@LCL"<<std::endl;
	this->output<<"\tM=D\t//LCL = frame-4"<<std::endl;

	//goto retAddr
	this->output<<"//goto retAddr"<<std::endl;
	this->output<<"\t@retAddr"<<std::endl;
	this->output<<"\tA=M\t//A = *retAddr"<<std::endl;
	this->output<<"\t0;JMP\t//jmp to retAddr"<<std::endl;

}

void CodeWriter::writeFunction(std::string functionName, int numLocals)
{
	//g:
	this->output<<"("<<functionName<<")\t//function name"<<std::endl;
	//	repeat nVars times:
	//	push 0
	for (int i = 0; i < numLocals; ++i)
		{
			this->writePushPop("push constant 0", "constant","", 0);
		}	

}