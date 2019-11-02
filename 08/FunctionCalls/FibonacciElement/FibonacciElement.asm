//bootstrap code
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
(Sys.init)	//function name
//push constant 4
	@4	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push returnAddress
	@returnAddress1
	D=A	//D=returnAddress1
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
	@1
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
//goto Main.fibonacci
	@Main.fibonacci//label to go to
	0;JMP	//unconditional jump
//label returnAddress1
(returnAddress1)	//label declaration
//label WHILE
(WHILE)	//label declaration
//goto WHILE
	@WHILE//label to go to
	0;JMP	//unconditional jump
(Main.fibonacci)	//function name
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
//push constant 2
	@2	//A=index
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
	@L0
	D;JLT	//if D < 0 jump to L0
	@SP	//else put 0 in @x
	A=M	//A = M[SP] e.g @x
	M=0	//M[A] = 0 e.g @x = false
	@END0
	0;JMP	//jump to end
(L0)
	@SP	//JLT target code
	A=M	//A=M[SP] e.g @x
	M=-1	//M[A] = -1 e.g @x = true
(END0)
	@SP
	M=M+1	//M[SP] = M[SP] + 1 e.g @y
//if-goto IF_TRUE
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@IF_TRUE
	D;JNE	//if D != 0 jump to IF_TRUE
//goto IF_FALSE
	@IF_FALSE//label to go to
	0;JMP	//unconditional jump
//label IF_TRUE
(IF_TRUE)	//label declaration
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
//return instruction
//frame = LCL
	@LCL	//A=LCL
	D=M	//D=LCL
	@frame	//frame is a variable
	M=D	//frame = LCL
//retAddr = *(frame - 5)
	@5	//A=5
	D=D-A	//D = frame - 5
	A=D	//A = D = @retAddr
	D=M	//D=M[A] = retAddr
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
//label IF_FALSE
(IF_FALSE)	//label declaration
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
//push constant 2
	@2	//A=index
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
//push returnAddress
	@returnAddress2
	D=A	//D=returnAddress2
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
	@1
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
//goto Main.fibonacci
	@Main.fibonacci//label to go to
	0;JMP	//unconditional jump
//label returnAddress2
(returnAddress2)	//label declaration
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
//push returnAddress
	@returnAddress3
	D=A	//D=returnAddress3
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
	@1
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
//goto Main.fibonacci
	@Main.fibonacci//label to go to
	0;JMP	//unconditional jump
//label returnAddress3
(returnAddress3)	//label declaration
//add
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @y
	D=M	//D=M[A] e.g y
	A=A-1	//A = @y - 1 e.g @x
	M=D+M	//M[@x] = y + M[@x]
//return instruction
//frame = LCL
	@LCL	//A=LCL
	D=M	//D=LCL
	@frame	//frame is a variable
	M=D	//frame = LCL
//retAddr = *(frame - 5)
	@5	//A=5
	D=D-A	//D = frame - 5
	A=D	//A = D = @retAddr
	D=M	//D=M[A] = retAddr
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
