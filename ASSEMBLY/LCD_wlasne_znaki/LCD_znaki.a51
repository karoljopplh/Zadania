magistrala equ P0
E bit P1.0
RS bit P1.2
RW bit P1.1
	org 0h
		jmp start
	org 0bh
		jmp licznik0
start:	
		mov TMOD,#00000001b
		mov TH0,#0h
		mov TL0,#0h
		setb TR0
		setb ET0
		setb EA

		clr RW//zapis
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
		mov R1,#1//znak0
		mov DPTR,#znak1
		call LCDznak
		mov R1,#2//znak0
		mov DPTR,#znak2
		call LCDznak
		mov R1,#3//znak0
		mov DPTR,#znak3
		call LCDznak
		clr RS
		mov R6,#80h
		call LCDzapis
		setb RS
		/*
		mov R6,#'W'
		call LCDzapis
		mov R6,#1//znak0
		call LCDzapis
		mov R6,#2//znak0
		call LCDzapis
		mov R6,#3//znak0
		call LCDzapis
		*/
		mov DPTR,#napisek
		call LCDnapis
		clr RS
		mov R6,#1Ch
		call LCDzapis
stop:	
		jmp stop

licznik0:
		

LCDnapis:
		setb RS
		mov R0,#0
jump:	;setb RS
		cjne R0,#16,skuk
		clr RS
		mov R6,#0C0h
		call LCDzapis
		setb RS
skuk:	mov A,R0
		movc A,@A+DPTR
		cjne A,#'$',pokaz
		jmp wyjdz
pokaz:	cjne A,#'¹',omin2
		mov A,#1
		jmp omin0
omin2:	
		cjne A,#'³',omin1
		mov A,#2
		jmp omin0
omin1:	
		cjne A,#'ê',omin0
		mov A,#3
omin0:
		mov R6,A
		call LCDzapis
jumpin:	inc R0
		jmp jump
wyjdz:	ret

/*
skok2:	inc R7
		call LCDzapis
		call licznik0
		cjne R7,#3Ah,skok
		jmp skok2
*/


/*		mov R1,#0
sk6:	mov R6,A
		call LCDzapis
		inc A
		inc R1
		cjne R1,#4,sk6
		jmp sk7
	*/	
		mov R6,#0C1h
		setb RS//dane kody ASCII
		;call LCDzapis
		;mov R6,#'W'
		;call LCDzapis
		;mov R6,#'S'
		;call LCDzapis
		;mov R6,#'T'
		;call LCDzapis
		;mov R6,#'I'
		;call LCDzapis
		mov DPTR,#napisek
		call Tekst
		
Napis:	db "WSTI Katowice$"
Napis1:	db "aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbcccccccccccccccc$"

Tekst:	setb RS
		mov R3,#0
tutaj:	mov A,R3
		movc A,@A+DPTR
		mov R6,A
		cjne R6,#'¹',wyswietla
		cjne R6,#'³',wyswietll
		cjne R6,#'$',wyswietl
		jmp omin
wyswietla:
		mov R6,#1
		jmp wyswietl
wyswietll:
		mov R6,#2
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

LCDznak:
		mov B,#0
		mov A,R1
		rl A
		rl A
		rl A
		add A,#40h
		mov R1,A
powrot:	clr RS
		mov A,R1
		mov R6,A
		call LCDzapis
		setb RS
		mov A,B
		movc A,@A+DPTR
		mov R6,A
		call LCDzapis
		inc B
		inc R1
		mov A,B
		cjne A,#8,powrot
		ret
		
znak0:	db 0h, 0h, 1Fh, 15h, 1Fh, 15h, 1Fh, 0h
znak1:	db 0h, 0h, 0Eh, 01h, 0Fh, 11h, 0Fh, 02h
znak2:	db 0Ch, 04h, 06h, 04h, 0Ch, 04h, 0Eh, 0h
znak3:	db 0h, 0h, 0Eh, 11h, 1Fh, 10h, 0Eh, 04h
napisek:	db " Kwiaty na ³¹ce zwiêd³y$"
	end