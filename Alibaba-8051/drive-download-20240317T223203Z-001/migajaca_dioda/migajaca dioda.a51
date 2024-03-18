dioda bit	P0.3
	org 0h
		mov P0,#0xff
start:	cpl dioda
		call delay
		jmp start
		
delay:	mov R5,#10 ;komentarz
sk3:    mov R6,#255
sk2:    mov R7,#255
sk1: 	djnz R7,sk1 ;dekrementuje sie R7
		djnz R6,sk2 ;dekrementuje sie R6 i ustawia wartosc R7 jeszcze raz
		djnz R5,sk3 ;dekrementuje sie R5 i ustawia wartosc R7,R6 jeszcze raz
		ret
		end