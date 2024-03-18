dioda bit	P0.3
	org 0h
		mov P0,#0xff
		clr P1.0
		mov DPTR,#seg7
		mov R0,#0
		mov R1,#10
		
start:	
		mov A,R0
		movc A,@A+DPTR
		mov P0,A
		call delay
		call increm
 		call porownaj
		jmp start

increm:	inc R0

porownaj: cjne R0,#10,wyjdz

wyjdz: ret		
		;dec R0
		;cjne R0,#0
		;!=0 then --		
		

delay:	mov R5,#5 ;komentarz
sk3:    mov R6,#255
sk2:    mov R7,#255
sk1: 	djnz R7,sk1 ;dekrementuje sie R7
		djnz R6,sk2 ;dekrementuje sie R6 i ustawia wartosc R7 jeszcze raz
		djnz R5,sk3 ;dekrementuje sie R5 i ustawia wartosc R7,R6 jeszcze raz
		ret
		
seg7:	db 11000000b,11111001b,10100100b,10110000b,10011001b,10010010b,00000010b,11011000b,10000000b,00010000b

		
		
		end