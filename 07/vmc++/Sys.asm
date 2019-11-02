	@256
	D=A	//D = 256
	@SP
	M=D	//M[SP] = 256
//push returnAddress
	@returnAddress0
	D=A	//D=returnAddress0
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push LCL
	@LCL
	D=M	//D=LCL
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push ARG
	@ARG
	D=M	//D=ARG
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push THIS
	@THIS
	D=M	//D=THIS
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push THAT
	@THAT
	D=M	//D=THAT
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//ARG = SP - nArgs - 5
	@SP
	D=M	//D=SP
	@0
	D=D-A	//D = SP-nArgs
	@5
	D=D-A	//D=SP-5
	@ARG
	M=D	//ARG= SP - nArgs -5
//LCL = SP
	@SP
	D=M	//D=SP
	@LCL
	M=D	//LCL = SP
//goto Sys.init
	@Sys.init//label to go to
	0;JMP	//unconditional jump
//label returnAddress0
(returnAddress0)	//label declaration
