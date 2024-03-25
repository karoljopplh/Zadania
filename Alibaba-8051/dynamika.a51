segmenty equ P0
cyfry equ P1
		org 0h
		jmp start
		org 0bh
		jmp licznik0
		org 1bh
		jmp licznik1
start:	mov 80,#2
		mov 81,#0
		mov 82,#2
		mov 83,#4
		mov TMOD,#00010010b;timer1 tryb1, timer 0 tryb2
		setb TR0
		setb ET0
		setb TR1
		setb ET1
		setb EA
		mov segmenty,#0ffh
		mov cyfry,#0ffh
		mov R0,#80
		mov R1,#11111110b
		mov DPTR,#seg7
		mov R3,#0
czekaj:
		jmp czekaj
licznik1:
		mov TH1,#1fh
		mov TL1,#0
		inc R3
		cjne R3,#16,omin1
		cpl P1.4
		mov R3,#0
		inc 83
		mov R2,83
		cjne R2,#10,omin1
		mov 83,#0
omin1:		
		reti
licznik0:
		mov A,@R0
		movc A,@A+DPTR
		mov segmenty,A
		mov cyfry,R1
		inc R0
		mov A,R1
		rl A
		mov R1,A
		cjne R0,#84,omin
		mov R0,#80
		mov R1,#11111110b
		mov DPTR,#seg7
omin:
		reti
seg7:	db 0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x00,0x10
	end