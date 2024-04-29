magistrala equ P0
E bit P1.0
RS bit P1.2
RW bit P1.1
	org 0h
		jmp start

start:	clr RW//zapis
		clr RS//instrukcja
		mov R6,#38h//magistrala 8-bitowa
		call LCDzapis
		mov R6,#6h//inkrementacja adresu znaku
		call LCDzapis
		mov R6,#0Ch//wlaczenie LCD etc. bez kursora
		call LCDzapis
		mov R6,#1h//czyszczenie ekranu
		call LCDzapis
		call DelayL
		clr RS
		mov R6,#80h
		call LCDzapis
		setb RS
		mov R6,#'W'
		call LCDzapis

stop:	
		jmp stop
/*
skok2:	inc R7
		call LCDzapis
		call licznik0
		cjne R7,#3Ah,skok
		jmp skok2
*/
increm:	mov B,#0h
		mov R1,#5
		mov A,R1
		rl A
		rl A
		rl A
		add A,#40h
		mov R1,A
		clr RS
		
		ret


/*		mov R1,#0
sk6:	mov R6,A
		call LCDzapis
		inc A
		inc R1
		cjne R1,#4,sk6
		jmp sk7
	*/	
		;mov R6,#0C1h
		;setb RS//dane kody ASCII
		;call LCDzapis
		;mov R6,#'W'
		;call LCDzapis
		;mov R6,#'S'
		;call LCDzapis
		;mov R6,#'T'
		;call LCDzapis
		;mov R6,#'I'
		;call LCDzapis
		;mov DPTR,#Napis1
		;call Tekst
		
Napis:	db "WSTI Katowice$"
Napis1:	db "aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbcccccccccccccccc$"

Tekst:	setb RS
		mov R3,#0
tutaj:	mov A,R3
		movc A,@A+DPTR
		mov R6,A
		cjne R6,#'$',wyswietl
		jmp omin
wyswietl:
	call delayM
	call LCDzapis
	inc R3
	cjne R3,#32,sk5
	clr RS
	mov R6,#80h
	call LCDzapis
	setb RS
	jmp tutaj
sk5:cjne R3,#16,tutaj
	clr RS
	mov R6,#0C0h
	call LCDzapis
	setb RS
	jmp tutaj
	
omin:
	ret
		
delay:
	mov R7,#5
sk1:djnz R7,sk1
	ret
	
delayL:	
	mov R4,#0ffh
sk3:mov R5,#0ffh
sk2:djnz R5,sk2
	djnz R4,sk3
	ret
	
delayM: 
		mov R2,#2
sk4:	call delayL
		djnz R2,sk4
		ret
	
LCDzapis:
	mov magistrala,R6
	setb E
	call delay
	clr E
	call delay
	ret
	
znak0:	db 0h, 0h, 1Fh, 15h, 1Fh, 15h, 1Fh, 0h
	end