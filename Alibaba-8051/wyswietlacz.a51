dioda	bit P0.3
	org	0h
		mov P0,#0xff
		clr	P1.0
		mov	DPTR,#seg7
zeruj:	mov R0,#0
start:	
		mov	A,R0
		movc A,@A+DPTR
		mov P0,A
		call delay
		inc R0
		cjne R0,#10,start
sc2:	mov	A,R0
		movc A,@A+DPTR
		mov P0,A
		call delay
		djnz R0
		cjne R0,#0,sc2
stop:	jmp zeruj
	
seg7:	db 0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x00,0x10


delay:	mov R5,#5
sk3:	mov R6,#255
sk2:	mov R7,#255		
sk1:	djnz R7,sk1
		djnz R6,sk2
		djnz R5,sk3
		ret

		end