// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

	@SCREEN
	D = A
	@R0
	M = D //R0 is array base
(LOOP)
	//check the keyboard
	@KBD
	D = M

	//if D = 0 go to clear screen
	@CLEAR
	D;JEQ

	//else fill the screen
	@R0
	A = M
	M = -1
	D = A +1

	@R0
	M = D

	@24575
	D = D - A

	@ZERO
	D;JGT
	
	@LOOP
	0;JMP
		
(CLEAR)
	@R0
	A = M
	M = 0
	D = A +1

	@R0
	M = D

	@24575
	D = D - A

	@ZERO
	D;JGT

	@LOOP
	0;JMP
(ZERO)
	@SCREEN
	D=A
	@R0
	M = D
	@LOOP
	0;JMP
