	org 00h
loop:	mov P0,#00h
		acall delay
		mov P0,#0FFh
		acall delay
		jmp loop
		
delay:	mov R7,#255
d2:		mov R6,#255
d1:		djnz R6,d1
		djnz R7,d2
		ret
stop: jmp stop
	end