//push constant 17
	@17	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push constant 17
	@17	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//eq
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @y
	D=M	//D = M[@y] e.g y
	@R13
	M=D	//R13 = D e.g y
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @x
	D=M	//D = M[@x] e.g x
	@R13
	D=D-M	//D = D - R13 e.g x = x-y
	@L0
	D;JEQ	//if D == 0 jump to L0
	@SP	//else put 0 in @x
	A=M	//A = M[SP] e.g @x
	M=0	//M[A] = 0 e.g @x = false
	@END0
	0;JMP	//jump to end
(L0)
	@SP	//JEQ target code
	A=M	//A=M[SP] e.g @x
	M=-1	//M[A] = -1 e.g @x = true
(END0)
	@SP
	M=M+1	//M[SP] = M[SP] + 1 e.g @y
//push constant 17
	@17	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push constant 16
	@16	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//eq
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @y
	D=M	//D = M[@y] e.g y
	@R13
	M=D	//R13 = D e.g y
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @x
	D=M	//D = M[@x] e.g x
	@R13
	D=D-M	//D = D - R13 e.g x = x-y
	@L1
	D;JEQ	//if D == 0 jump to L1
	@SP	//else put 0 in @x
	A=M	//A = M[SP] e.g @x
	M=0	//M[A] = 0 e.g @x = false
	@END1
	0;JMP	//jump to end
(L1)
	@SP	//JEQ target code
	A=M	//A=M[SP] e.g @x
	M=-1	//M[A] = -1 e.g @x = true
(END1)
	@SP
	M=M+1	//M[SP] = M[SP] + 1 e.g @y
//push constant 16
	@16	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push constant 17
	@17	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//eq
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @y
	D=M	//D = M[@y] e.g y
	@R13
	M=D	//R13 = D e.g y
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @x
	D=M	//D = M[@x] e.g x
	@R13
	D=D-M	//D = D - R13 e.g x = x-y
	@L2
	D;JEQ	//if D == 0 jump to L2
	@SP	//else put 0 in @x
	A=M	//A = M[SP] e.g @x
	M=0	//M[A] = 0 e.g @x = false
	@END2
	0;JMP	//jump to end
(L2)
	@SP	//JEQ target code
	A=M	//A=M[SP] e.g @x
	M=-1	//M[A] = -1 e.g @x = true
(END2)
	@SP
	M=M+1	//M[SP] = M[SP] + 1 e.g @y
//push constant 892
	@892	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push constant 891
	@891	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//lt
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @y
	D=M	//D = M[@y] e.g y
	@R13
	M=D	//R13 = D e.g y
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @x
	D=M	//D = M[@x] e.g x
	@R13
	D=D-M	//D = D - R13 e.g x = x-y
	@L3
	D;JLT	//if D < 0 jump to L3
	@SP	//else put 0 in @x
	A=M	//A = M[SP] e.g @x
	M=0	//M[A] = 0 e.g @x = false
	@END3
	0;JMP	//jump to end
(L3)
	@SP	//JLT target code
	A=M	//A=M[SP] e.g @x
	M=-1	//M[A] = -1 e.g @x = true
(END3)
	@SP
	M=M+1	//M[SP] = M[SP] + 1 e.g @y
//push constant 891
	@891	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push constant 892
	@892	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//lt
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @y
	D=M	//D = M[@y] e.g y
	@R13
	M=D	//R13 = D e.g y
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @x
	D=M	//D = M[@x] e.g x
	@R13
	D=D-M	//D = D - R13 e.g x = x-y
	@L4
	D;JLT	//if D < 0 jump to L4
	@SP	//else put 0 in @x
	A=M	//A = M[SP] e.g @x
	M=0	//M[A] = 0 e.g @x = false
	@END4
	0;JMP	//jump to end
(L4)
	@SP	//JLT target code
	A=M	//A=M[SP] e.g @x
	M=-1	//M[A] = -1 e.g @x = true
(END4)
	@SP
	M=M+1	//M[SP] = M[SP] + 1 e.g @y
//push constant 891
	@891	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push constant 891
	@891	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//lt
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @y
	D=M	//D = M[@y] e.g y
	@R13
	M=D	//R13 = D e.g y
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @x
	D=M	//D = M[@x] e.g x
	@R13
	D=D-M	//D = D - R13 e.g x = x-y
	@L5
	D;JLT	//if D < 0 jump to L5
	@SP	//else put 0 in @x
	A=M	//A = M[SP] e.g @x
	M=0	//M[A] = 0 e.g @x = false
	@END5
	0;JMP	//jump to end
(L5)
	@SP	//JLT target code
	A=M	//A=M[SP] e.g @x
	M=-1	//M[A] = -1 e.g @x = true
(END5)
	@SP
	M=M+1	//M[SP] = M[SP] + 1 e.g @y
//push constant 32767
	@32767	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push constant 32766
	@32766	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//gt
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @y
	D=M	//D = M[@y] e.g y
	@R13
	M=D	//R13 = D e.g y
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @x
	D=M	//D = M[@x] e.g x
	@R13
	D=D-M	//D = D - R13 e.g x = x-y
	@L6
	D;JGT	//if D > 0 jump to L6
	@SP	//else put 0 in @x
	A=M	//A = M[SP] e.g @x
	M=0	//M[A] = 0 e.g @x = false
	@END6
	0;JMP	//jump to end
(L6)
	@SP	//JGT target code
	A=M	//A=M[SP] e.g @x
	M=-1	//M[A] = -1 e.g @x = true
(END6)
	@SP
	M=M+1	//M[SP] = M[SP] + 1 e.g @y
//push constant 32766
	@32766	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push constant 32767
	@32767	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//gt
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @y
	D=M	//D = M[@y] e.g y
	@R13
	M=D	//R13 = D e.g y
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @x
	D=M	//D = M[@x] e.g x
	@R13
	D=D-M	//D = D - R13 e.g x = x-y
	@L7
	D;JGT	//if D > 0 jump to L7
	@SP	//else put 0 in @x
	A=M	//A = M[SP] e.g @x
	M=0	//M[A] = 0 e.g @x = false
	@END7
	0;JMP	//jump to end
(L7)
	@SP	//JGT target code
	A=M	//A=M[SP] e.g @x
	M=-1	//M[A] = -1 e.g @x = true
(END7)
	@SP
	M=M+1	//M[SP] = M[SP] + 1 e.g @y
//push constant 32766
	@32766	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push constant 32766
	@32766	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//gt
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @y
	D=M	//D = M[@y] e.g y
	@R13
	M=D	//R13 = D e.g y
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @x
	D=M	//D = M[@x] e.g x
	@R13
	D=D-M	//D = D - R13 e.g x = x-y
	@L8
	D;JGT	//if D > 0 jump to L8
	@SP	//else put 0 in @x
	A=M	//A = M[SP] e.g @x
	M=0	//M[A] = 0 e.g @x = false
	@END8
	0;JMP	//jump to end
(L8)
	@SP	//JGT target code
	A=M	//A=M[SP] e.g @x
	M=-1	//M[A] = -1 e.g @x = true
(END8)
	@SP
	M=M+1	//M[SP] = M[SP] + 1 e.g @y
//push constant 57
	@57	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push constant 31
	@31	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push constant 53
	@53	//A=index
	D=A	//D is now the constant
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
//push constant 112
	@112	//A=index
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
//neg
	@SP
	A=M-1	//A = M[SP] - 1 e.g @y
	M=-M	//M[A]=-M[A] e.g -y
//and
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @y
	D=M	//D = M[@y] e.g y
	A=A-1	//@y = @y - 1 e.g @x
	M=D&M	//M[@x] = y & M[@x]
//push constant 82
	@82	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//or
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @y
	D=M	//D = M[@y] e.g y
	A=A-1//@y = @y - 1 e.g @x
	M=D|M	//M[@x] = y | M[@x]
//not
	@SP
	A=M-1	//A = M[SP] - 1 e.g @y
	M=!M	//M[@y] = !M[@y] e.g !y
