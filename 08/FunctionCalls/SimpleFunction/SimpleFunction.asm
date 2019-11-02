(SimpleFunction.test)	//function name
//push constant 0
	@0	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push constant 0
	@0	//A=index
	D=A	//D is now the constant
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
//push local 1
	@LCL	//A=LCL
	D=M	//save M[local] in D
	@1	//A = index
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
//not
	@SP
	A=M-1	//A = M[SP] - 1 e.g @y
	M=!M	//M[@y] = !M[@y] e.g !y
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
//add
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @y
	D=M	//D=M[A] e.g y
	A=A-1	//A = @y - 1 e.g @x
	M=D+M	//M[@x] = y + M[@x]
//push argument 1
	@ARG	//A=ARG
	D=M	//save M[argument] in D
	@1	//A = index
	D=D+A	//D is now @(argument + index)
	A=D	//A = @ contained in D
	D=M//D=M[A], value to push
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
//return instruction
//frame = LCL
	@LCL	//A=LCL
	D=M	//D=LCL
	@frame	//frame is a variable
	M=D	//frame = LCL
//retAddr = *(frame - 5
	@5	//A=5
	D=D-A	//D = frame - 5
	@retAddr	//retAddr is a variable
	M=D	//retAddr = frame - 5
//*ARG = pop argument 0
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
//SP = ARG-1
	@ARG
	D=M	// D = ARG
	@SP
	M=D+1	//SP=ARG+1
//THAT = *(frame-1)
	@frame
	A=M-1	//A = frame-1
	D=M	//D=M[frame-1]
	@THAT
	M=D	//THAT = *(frame-1)
//THIS = *(frame-2)
	@frame
	D=M	//D=frame
	@2
	A=D-A	//A=frame-2
	D=M	//D = M[frame-2]
	@THIS
	M=D	//THIS = *(frame-2)
//ARG = *(frame-3)
	@frame
	D=M	//D=frame
	@3
	A=D-A	//A=frame-3
	D=M	//D = M[frame-3]
	@ARG
	M=D	//ARG = frame-3
//LCL = *(frame-4)
	@frame
	D=M	//D=frame
	@4
	A=D-A	//A=frame-4
	D=M	//D = M[frame-4]
	@LCL
	M=D	//LCL = frame-4
//goto retAddr
	@retAddr
	A=M	//A = *retAddr
	0;JMP	//jmp to retAddr
