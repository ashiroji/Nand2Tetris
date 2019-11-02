// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.
	//set R2 to 0
	@R2
	M = 0
(LOOP)
	//first check if R0 is zero or not	
	@R0
	D=M
	@ZERO
	D;JLE
	//if R0 is not zero, R2 = R0 + R0
	@R2
	M = M+D
	
	//Check if R1 is zero or not
	@R1
	D = M
	@ZERO
	D;JLE
	//if R1 is not zero, R1 = R1-1
	@R1
	M = M -1
	//check if R1 is 0, if not jump to loop
	D = M
	@LOOP
	D;JGT
	//if yes jump to end
	@END
	0;JMP
(ZERO)
	@R2
	M = 0
(END)
