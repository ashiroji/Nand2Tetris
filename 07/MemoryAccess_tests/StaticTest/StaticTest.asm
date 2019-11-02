//push constant 111
	@111	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push constant 333
	@333	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push constant 888
	@888	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//pop static 8
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@24	//A = RAM @24
	D=A	//D is now @static + index
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
//pop static 3
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@19	//A = RAM @19
	D=A	//D is now @static + index
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
//pop static 1
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@17	//A = RAM @17
	D=A	//D is now @static + index
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
//push static 3
	@19	//A = RAM @19
	D=A	//D is now @static + index
	A=D	//A = @ contained in D
	D=M//D=M[A], value to push
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push static 1
	@17	//A = RAM @17
	D=A	//D is now @static + index
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
//push static 8
	@24	//A = RAM @24
	D=A	//D is now @static + index
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
