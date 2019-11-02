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
//push constant 4000
	@4000	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//pop pointer 0
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@3	//A = RAM @3
	D=A	//D is now @pointer + index
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
//push constant 5000
	@5000	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//pop pointer 1
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@4	//A = RAM @4
	D=A	//D is now @pointer + index
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
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
//goto Sys.main
	@Sys.main//label to go to
	0;JMP	//unconditional jump
//label returnAddress1
(returnAddress1)	//label declaration
//pop temp 1
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@R6	//A = RAM @
	D=A	//D is now @static + index
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
//label LOOP
(LOOP)	//label declaration
//goto LOOP
	@LOOP//label to go to
	0;JMP	//unconditional jump
(Sys.main)	//function name
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
//push constant 0
	@0	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push constant 4001
	@4001	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//pop pointer 0
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@3	//A = RAM @3
	D=A	//D is now @pointer + index
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
//push constant 5001
	@5001	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//pop pointer 1
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@4	//A = RAM @4
	D=A	//D is now @pointer + index
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
//push constant 200
	@200	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//pop local 1
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@LCL	//A=LCL
	D=M	//save M[local] in D
	@1	//A = index
	D=D+A	//D is now @(local + index)
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
//push constant 40
	@40	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//pop local 2
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@LCL	//A=LCL
	D=M	//save M[local] in D
	@2	//A = index
	D=D+A	//D is now @(local + index)
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
//push constant 6
	@6	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//pop local 3
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@LCL	//A=LCL
	D=M	//save M[local] in D
	@3	//A = index
	D=D+A	//D is now @(local + index)
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
//push constant 123
	@123	//A=index
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
//goto Sys.add12
	@Sys.add12//label to go to
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
	D=A	//D is now @static + index
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
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
//push local 2
	@LCL	//A=LCL
	D=M	//save M[local] in D
	@2	//A = index
	D=D+A	//D is now @(local + index)
	A=D	//A = @ contained in D
	D=M//D=M[A], value to push
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push local 3
	@LCL	//A=LCL
	D=M	//save M[local] in D
	@3	//A = index
	D=D+A	//D is now @(local + index)
	A=D	//A = @ contained in D
	D=M//D=M[A], value to push
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//push local 4
	@LCL	//A=LCL
	D=M	//save M[local] in D
	@4	//A = index
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
//add
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @y
	D=M	//D=M[A] e.g y
	A=A-1	//A = @y - 1 e.g @x
	M=D+M	//M[@x] = y + M[@x]
//add
	@SP
	AM=M-1	//AM[SP] = M[SP] - 1 e.g @y
	D=M	//D=M[A] e.g y
	A=A-1	//A = @y - 1 e.g @x
	M=D+M	//M[@x] = y + M[@x]
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
(Sys.add12)	//function name
//push constant 4002
	@4002	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//pop pointer 0
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@3	//A = RAM @3
	D=A	//D is now @pointer + index
	@R14
	M=D	//save D value
	@R13
	D=M	//D= value to pop
	@R14
	A=M	//A = (segmentBase+index)
	M=D	//M[A] = value to pop
//push constant 5002
	@5002	//A=index
	D=A	//D is now the constant
	@SP
	A=M	//A = @SP
	M=D	//M[A] = value to push
	@SP
	M=M+1	//sp+1
//pop pointer 1
	@SP
	AM=M-1	//AM = M[SP] - 1
	D=M	//D = the value to pop
	@R13
	M=D	//save the value in R13
	@4	//A = RAM @4
	D=A	//D is now @pointer + index
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
//push constant 12
	@12	//A=index
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
