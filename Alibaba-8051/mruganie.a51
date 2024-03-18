dioda	bit P0.3
	org	0h
		mov P0,#0xff
start:	cpl dioda
		call delay
		jmp start
		
delay:	mov R5,#5
sk3:	mov R6,#255
sk2:	mov R7,#255		
sk1:	djnz R7,sk1
		djnz R6,sk2
		djnz R5,sk3
		ret
		end