	org 0000h
main:	mov TMOD,#00000001b	;Timer0 mode 1
		mov TH0,#03Ch	;50ms timer
		mov TL0,#0B0h	;0011 1100 1011 0000
start:	setb P0.2
		acall onesec
		clr P0.2
		acall onesec
		sjmp start
		
onesec:	mov R7,#20
sec:	acall delay
		djnz R7,sec
		ret             
		
delay:	setb TR0	;Timer0 turned on
loop:	jnb TF0,loop
		clr TR0
		clr TF0
		ret
		end