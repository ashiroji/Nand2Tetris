//push constant 0
	@0	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//pop local 0
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@LCL	//A=LCL
	D=M	//save M[local] in D
	@0	//A = index
	D=D+A	//D is now @(local + index)
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
//label LOOP_START
(LOOP_START)	//label declaration
//push argument 0
	@ARG	//A=ARG
	D=M	//save M[argument] in D
	@0	//A = index
	D=D+A	//D is now @(argument + index)
	A=D	//A = @ contained in D
	D=M//D=M[A], value to push
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push local 0
	@LCL	//A=LCL
	D=M	//save M[local] in D
	@0	//A = index
	D=D+A	//D is now @(local + index)
	A=D	//A = @ contained in D
	D=M//D=M[A], value to push
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//add
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @y
	D=M	//D=M[A] e.g y
	A=A-1	//A = @y - 1 e.g @x
	M=D+M	//M[@x] = y + M[@x]
//pop local 0
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@LCL	//A=LCL
	D=M	//save M[local] in D
	@0	//A = index
	D=D+A	//D is now @(local + index)
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
//push argument 0
	@ARG	//A=ARG
	D=M	//save M[argument] in D
	@0	//A = index
	D=D+A	//D is now @(argument + index)
	A=D	//A = @ contained in D
	D=M//D=M[A], value to push
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push constant 1
	@1	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//sub
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @y
	D=-M	//D=-M[A] e.g -y
	A=A-1	//A = @y - 1 e.g @x
	M=D+M	//M[@x] = -y + M[@x]
//pop argument 0
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@ARG	//A=ARG
	D=M	//save M[argument] in D
	@0	//A = index
	D=D+A	//D is now @(argument + index)
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
//push argument 0
	@ARG	//A=ARG
	D=M	//save M[argument] in D
	@0	//A = index
	D=D+A	//D is now @(argument + index)
	A=D	//A = @ contained in D
	D=M//D=M[A], value to push
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//if-goto LOOP_START
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@LOOP_START
	D;JNE	//if D != 0 jump to LOOP_START
//push local 0
	@LCL	//A=LCL
	D=M	//save M[local] in D
	@0	//A = index
	D=D+A	//D is now @(local + index)
	A=D	//A = @ contained in D
	D=M//D=M[A], value to push
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
