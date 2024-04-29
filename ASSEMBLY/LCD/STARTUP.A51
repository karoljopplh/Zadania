magistrala equ P0
E bit P1.0
RS bit P1.2
RW bit P1.1
przycisk bit P3.2
	org 0h
		jmp start
	org 0bh
		jmp licznik0
	org	1bh
		jmp licznik1
/*licznik0:
		mov TMOD,#00000001b
		setb TR0
		mov TH0,#4h
		mov TL0,#70h
		setb EA
		mov R1,#15

monitor:jnb TF0,monitor
		clr TR0
		clr TF0
		ret
*/
start:	clr RW//zapis
		clr RS//instrukcja
		mov R6,#38h//magistrala 8-bitowa
		call LCDzapis
		mov R6,#6h//inkrementacja adresu znaku
		call LCDzapis
		mov R6,#0Fh//wlaczenie LCD etc.
		call LCDzapis
		mov R6,#1h//czyszczenie ekranu
		call LCDzapis
		call DelayL
skok:	
		mov 80,#32h
		mov 81,#30h
		mov 82,#32h
		mov 83,#34h
		call czas
		mov R2,#0
		mov R0,#0//dotyczy przycisku
		mov TMOD,#00000001b
		mov TH0,#0h
		mov TL0,#0h
		mov TH1,#0h
		mov TL1,#0h
		setb TR0
		setb TR1
		setb ET0
		setb ET1
		setb EA
		
stop:	cjne R0,#2,stop
		mov R0,#3
		inc 81
		mov R1,81
		cjne R1,#3Ah,show
		mov 81,#'0'
		inc 80
		mov R1,80
		cjne R1,#3Ah,show
		mov 80,#'0'
show:	
		call czas
		jmp stop
/*
skok2:	inc R7
		call LCDzapis
		call licznik0
		cjne R7,#3Ah,skok
		jmp skok2
*/
czas:	clr RS
		mov R6,#80h
		call LCDzapis
		setb RS
		mov R6,80
		call LCDzapis
		mov R6,81
		call LCDzapis
		mov R6,82
		call LCDzapis
		mov R6,83
		call LCDzapis
		ret
licznik0:
		inc R2
		cjne R2,#14,wyjdz
		mov R2,#0
		inc 83
		mov R1,83
		cjne R1,#3ah, pokaz
		mov 83,#'0'
		inc 82
		mov R1,82
		cjne R1, #3ah, pokaz
		mov 82,#'0'
		
pokaz:	call czas
wyjdz:
		reti

licznik1:
		jb przycisk,nienacisniety
		cjne R0,#0,jeden
		mov R0,#1
		jmp koniec
		//cpl P3.7
jeden:	cjne R0,#1,koniec
		mov R0,#2
		jmp koniec

nienacisniety:
		cjne R0,#3,cztery
		mov R0,#4
		jmp koniec
cztery:	cjne R0,#4,koniec
		mov R0,#0
koniec:
		reti
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
	end