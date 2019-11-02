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
//push constant 6
	@6	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push constant 8
	@8	//A=index
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
	@2
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
//goto Class1.set
	@Class1.set//label to go to
	0;JMP	//unconditional jump
//label returnAddress1
(returnAddress1)	//label declaration
//pop temp 0
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@R5	//A = RAM @
	D=A	//D is now @temp + index
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
//push constant 23
	@23	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push constant 15
	@15	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
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
	@2
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
//goto Class2.set
	@Class2.set//label to go to
	0;JMP	//unconditional jump
//label returnAddress2
(returnAddress2)	//label declaration
//pop temp 0
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@R5	//A = RAM @
	D=A	//D is now @temp + index
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
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
//goto Class1.get
	@Class1.get//label to go to
	0;JMP	//unconditional jump
//label returnAddress3
(returnAddress3)	//label declaration
//push returnAddress
	@returnAddress4
	D=A	//D=returnAddress4
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
//goto Class2.get
	@Class2.get//label to go to
	0;JMP	//unconditional jump
//label returnAddress4
(returnAddress4)	//label declaration
//label WHILE
(WHILE)	//label declaration
//goto WHILE
	@WHILE//label to go to
	0;JMP	//unconditional jump
(Class1.set)	//function name
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
//pop static 0
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@static.Class1.vm.0	//the static variable location
	D=A	//D =@static.0 => the static value location
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
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
//pop static 1
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@static.Class1.vm.1	//the static variable location
	D=A	//D =@static.1 => the static value location
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
//push constant 0
	@0	//A=index
	D=A	//D is now the constant
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
(Class1.get)	//function name
//push static 0
	@static.Class1.vm.0	//the static variable location
	D=A	//D =@static.0 => the static value location
	A=D	//A = @ contained in D
	D=M//D=M[A], value to push
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push static 1
	@static.Class1.vm.1	//the static variable location
	D=A	//D =@static.1 => the static value location
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
(Class2.set)	//function name
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
//pop static 0
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@static.Class2.vm.0	//the static variable location
	D=A	//D =@static.0 => the static value location
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
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
//pop static 1
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@static.Class2.vm.1	//the static variable location
	D=A	//D =@static.1 => the static value location
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
//push constant 0
	@0	//A=index
	D=A	//D is now the constant
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
(Class2.get)	//function name
//push static 0
	@static.Class2.vm.0	//the static variable location
	D=A	//D =@static.0 => the static value location
	A=D	//A = @ contained in D
	D=M//D=M[A], value to push
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push static 1
	@static.Class2.vm.1	//the static variable location
	D=A	//D =@static.1 => the static value location
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
