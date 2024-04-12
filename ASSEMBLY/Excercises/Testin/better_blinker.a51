	org 00h
start:	mov P0,#00h
		setb P1.4
		clr P1.4
		acall OneSec
		mov P0,#0FFh
		setb P1.4
		clr P1.4
		acall OneSec
		jmp start
		
OneSec:	mov R7,#14h	;20*50ms is 1s 
back:	acall timer1
		djnz R7,back
		ret
		
timer1:	mov TMOD,#00000001b
jump:	mov TH0,#03ch	;50 miliseconds
		mov TL0,#0b0h
		
		setb TR0
loop:	jnb TF0,loop
		clr TF0
		clr TR0
		ret
		
		end
			