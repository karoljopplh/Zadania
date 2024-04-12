	org 0000h
led equ P0
main:	mov TMOD,#00000001b
		mov TH0,#03Ch
		mov TL0,#0B0h		
		clr P1.3
		clr P1.2
		mov DPTR,#seg7
start:	mov R7,#0FFh
		mov A,R7
		mov A,@A+DPTR
mig:	mov led,R7
		acall licznik0
		djnz R7,mig
		jmp start
		
licznik0:	setb TR0
monitor:	jnb TF0,monitor
			clr TR0
			clr TF0
			ret
seg7:		db 11000000b,11111001b,10100100b,10110000b,10011001b,10010010b,10000010b,11011000b,10000000b,10010000b
		end