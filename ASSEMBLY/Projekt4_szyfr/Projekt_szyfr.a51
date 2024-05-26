magistrala equ P0
E bit P1.0
RS bit P1.2
RW bit P1.1
ustaws	bit P3.5
ustawd	bit P3.4
ustawj	bit	P3.3
sprawdz	bit P3.2
	
	org 0h
		jmp start
	org 0bh
		jmp licznik0
	org 1bh
		jmp licznik1
		
start:
	//ustawienia LCD
		clr RW//zapis
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
		
	//ustawienia licznikow
		mov TMOD,#00010001b
		mov TH0,#0D5h	//10ms
		mov TL0,#9Ch
		mov TH1,#0D5h	//10ms
		mov TL1,#9Ch
		setb TR0
		setb TR1
		setb ET0
		setb ET1
		setb EA
		
	//zerowanie pamieci
		mov 70h,#0
		mov 71h,#0
		mov 72h,#0
		mov 80h,#0
/*	
R7 - delay
R6 - przesyl do magistrali
R5 - delayL
R4 - delayL
R3 - licznik0 cjne
R2 - wykrywanie zmiany
R1 - (@Ri)
R0 - (@Ri) refresh adresy (bez tego bylo by 3 razy wiecej kodu)
70h ... 72h - S D J
80h - refresh ktory to juz czesc kodu SDJ BCD
2000h - poprawny kod
*/
///////////////////////////////////////////////////////////////////////////////////////////////////

pstart:	cjne R2,#1,pstart
		call refresh
		mov R2,#0
		jmp pstart
		
stop:	jmp stop	//to jest tu po to by dalej nie przechodzilo, pozniej mozna usunac

///////////////////////////////////////////////////////////////////////////////////////////////////

licznik0:	//obserwacja przyciskow
st:		jb ustaws,dz
		inc 70h
		mov R2,#1
		mov R3,70h			//R3 jest tylko po to by uzyc cjne
		cjne R3,#10,dz
		mov 70h,#0
dz:		jb ustawd,jed
		inc 71h
		mov R2,#1
		mov R3,71h
		cjne R3,#10,jed
		mov 71h,#0
jed:	jb ustawj,dalej
		inc 72h
		mov R2,#1
		mov R3,72h
		cjne R3,#10,dalej
		mov 72h,#0
dalej:		
		reti
		
///////////////////////////////////////////////////////////////////////////////////////////////////		

refresh:
		mov 80h,#3
		mov R0,#70h
////////
bit4:	cjne @R0,#9,bit41
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit3
bit41:	cjne @R0,#8,bit40
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit3
bit40:	mov R6,#30h
		setb RS
		call LCDzapis
////////
bit3:	cjne @R0,#7,bit31
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit2
bit31:	cjne @R0,#6,bit32
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit2
bit32:	cjne @R0,#5,bit33
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit2
bit33:	cjne @R0,#4,bit30
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit2
bit30:	mov R6,#30h
		setb RS
		call LCDzapis
////////
bit2:	cjne @R0,#2,bit21
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit1
bit21:	cjne @R0,#3,bit22
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit1
bit22:	cjne @R0,#6,bit23
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit1
bit23:	cjne @R0,#7,bit20
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit1
bit20:	mov R6,#30h
		setb RS
		call LCDzapis
////////
bit1:	cjne @R0,#9,bit11
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp pomin
bit11:	cjne @R0,#7,bit12
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp pomin
bit12:	cjne @R0,#5,bit13
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp pomin
bit13:	cjne @R0,#3,bit14
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp pomin
bit14:	cjne @R0,#1,bit10
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp pomin
bit10:	mov R6,#30h
		setb RS
		call LCDzapis
		mov R6,#' '
		call LCDzapis
////////
pomin:
		inc R0
		djnz 80h,bit4A
		clr RS
		mov R6,#1h
		call LCDzapis
		call delayL
		mov R6,#80h
		//mov R6,#0C0h
		call LCDzapis
		jmp refresh
		ret
bit4A:	jmp bit4

///////////////////////////////////////////////////////////////////////////////////////////////////
		
licznik1:	//wyswietlanie BCD
/*
		mov 80h,#3
		mov R0,#70h
bit4:	cjne @R0,#9,bit41
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit3
bit41:	cjne @R0,#8,bit40
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit3
bit40:	mov R6,#30h
		setb RS
		call LCDzapis
bit3:	cjne @R0,#7,bit31
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit2
bit31:	cjne @R0,#6,bit32
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit2
bit32:	cjne @R0,#5,bit33
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit2
bit33:	cjne @R0,#4,bit30
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit2
bit30:	mov R6,#30h
		setb RS
		call LCDzapis
bit2:	cjne @R0,#2,bit21
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit1
bit21:	cjne @R0,#3,bit22
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit1
bit22:	cjne @R0,#6,bit23
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit1
bit23:	cjne @R0,#7,bit20
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp bit1
bit20:	mov R6,#30h
		setb RS
		call LCDzapis
bit1:	cjne @R0,#9,bit11
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp pomin
bit11:	cjne @R0,#7,bit12
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp pomin
bit12:	cjne @R0,#5,bit13
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp pomin
bit13:	cjne @R0,#3,bit14
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp pomin
bit14:	cjne @R0,#1,bit10
		mov R6,#31h
		setb RS
		call LCDzapis
		jmp pomin
bit10:	mov R6,#30h
		setb RS
		call LCDzapis
		mov R6,#' '
		call LCDzapis
pomin:
		inc R0
		djnz 80h,bit4A
		clr RS
		mov R6,#0C0h
		call LCDzapis
		reti
bit4A:	jmp bit4
*/
reti

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
	
LCDzapis:
	mov magistrala,R6
	setb E
	call delay
	clr E
	call delay
	ret
	
	end