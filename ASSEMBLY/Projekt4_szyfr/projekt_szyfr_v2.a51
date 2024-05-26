magistrala equ P0
E bit P1.0
RS bit P1.2
RW bit P1.1
ustaws	bit P3.4
ustawd	bit P3.3
ustawj	bit	P3.2
sprawdz	bit P3.5
	
	org 0h
		jmp start
	org 0bh
		jmp licznik0
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
		mov TMOD,#00000001b
		mov TH0,#0D5h	//10ms
		mov TL0,#9Ch
		setb TR0
		setb ET0
		setb EA
		
		//ustawianie komorek z aktualnym kodem
		mov 70h,#0	//setki
		mov 71h,#0	//dziesiatki
		mov 72h,#0	//jednosci
		
		//ustawianie komorek z haslem
		mov 60h,#1	//haslo setek
		mov 61h,#2	//haslo dziesiatek
		mov 62h,#3	//haslo jednosci
		
		call wypiszD	//pierwsze wypisanie
		
stop:	jmp stop

////////////////////////////////

licznik0:	//obserwacja przyciskow
		jb P3.5,cniewcisniete
;		jb F0,st
		setb F0
		mov A,70h
		cjne A,60h,niepoprawny
		mov A,71h
		cjne A,61h,niepoprawny
		mov A,72h
		cjne A,62h,niepoprawny
		//haslo poprawne
		
		mov magistrala,#255
		clr P0.0	//dioda LED
		call delayM	//ma byc 3s=3000ms
		mov 70h,#0	//setki
		mov 71h,#0	//dziesiatki
		mov 72h,#0	//jednosci
		setb P0.0
niepoprawny:
		jmp st
cniewcisniete:	;clr F0

st:		jb ustaws,sniewcisniete
		jb P1.3,dz
		inc 70h
		setb P1.3
		mov R3,70h			//R3 jest tylko po to by uzyc cjne
		cjne R3,#10,dz
		mov 70h,#0
		jmp dz
sniewcisniete:	clr P1.3

dz:		jb ustawd,dniewcisniete
		jb P1.4,jed
		inc 71h
		setb P1.4
		mov R3,71h
		cjne R3,#10,jed
		mov 71h,#0
		jmp jed
dniewcisniete:	clr P1.4

jed:	jb ustawj,jniewcisniete
		jb P1.5,dalej
		inc 72h
		setb P1.5
		mov R3,72h
		cjne R3,#10,dalej
		mov 72h,#0
		jmp dalej
jniewcisniete:	clr P1.5
dalej:	call wypiszD
		reti

////////////////////////////////

/*wypisz:
		clr RS
		mov R6,#80h
		call LCDzapis
		setb RS
		
		mov 80h,#2
		mov R0,#70h
////////
bit4:	cjne @R0,#9,bit41
		mov R6,#'1'
		setb RS
		call LCDzapis
		jmp bit3
bit41:	cjne @R0,#8,bit40
		mov R6,#'1'
		setb RS
		call LCDzapis
		jmp bit3
bit40:	mov R6,#'0'
		setb RS
		call LCDzapis
////////
bit3:	cjne @R0,#7,bit31
		mov R6,#'1'
		setb RS
		call LCDzapis
		jmp bit2
bit31:	cjne @R0,#6,bit32
		mov R6,#'1'
		setb RS
		call LCDzapis
		jmp bit2
bit32:	cjne @R0,#5,bit33
		mov R6,#'1'
		setb RS
		call LCDzapis
		jmp bit2
bit33:	cjne @R0,#4,bit30
		mov R6,#'1'
		setb RS
		call LCDzapis
		jmp bit2
bit30:	mov R6,#'0'
		setb RS
		call LCDzapis
////////
bit2:	cjne @R0,#2,bit21
		mov R6,#'1'
		setb RS
		call LCDzapis
		jmp bit1
bit21:	cjne @R0,#3,bit22
		mov R6,#'1'
		setb RS
		call LCDzapis
		jmp bit1
bit22:	cjne @R0,#6,bit23
		mov R6,#'1'
		setb RS
		call LCDzapis
		jmp bit1
bit23:	cjne @R0,#7,bit20
		mov R6,#'1'
		setb RS
		call LCDzapis
		jmp bit1
bit20:	mov R6,#'0'
		setb RS
		call LCDzapis
////////
bit1:	cjne @R0,#9,bit11
		mov R6,#'1'
		setb RS
		call LCDzapis
		jmp pomin
bit11:	cjne @R0,#7,bit12
		mov R6,#'1'
		setb RS
		call LCDzapis
		jmp pomin
bit12:	cjne @R0,#5,bit13
		mov R6,#'1'
		setb RS
		call LCDzapis
		jmp pomin
bit13:	cjne @R0,#3,bit14
		mov R6,#'1'
		setb RS
		call LCDzapis
		jmp pomin
bit14:	cjne @R0,#1,bit10
		mov R6,#'1'
		setb RS
		call LCDzapis
		jmp pomin
bit10:	mov R6,#'0'
		setb RS
		call LCDzapis
		mov R6,#' '
		call LCDzapis
////////
pomin:
		inc R0
		djnz 80h,bit4A
		ret
bit4A:	jmp bit4
		ret
*/

wypiszD:	//wypisuje aktualny kod w decymalnym
	clr RS
	mov R6,#80h
	call LCDzapis
	setb RS
	mov A,70h
	add A,#30h
	mov R6,A
	call LCDzapis
	mov A,71h
	add A,#30h
	mov R6,A
	call LCDzapis
	mov A,72h
	add A,#30h
	mov R6,A
	call LCDzapis
	ret
	
delay:		//krotki delay potrzebny do wysylania informacji do wyswietlacza
	mov R7,#5
sk1:djnz R7,sk1
	ret
	
delayL:		//wiekszy delay do opoznienia po wyczyszczeniu ekranu
	mov R4,#0ffh
sk3:mov R5,#0ffh
sk2:djnz R5,sk2
	djnz R4,sk3
	ret

delayM:		//3 sekundowy delay
	mov 64h,#14
skM:call delayL
	djnz 64h,skM
	ret

LCDzapis:	//wysylanie instrukcji do wyswietlacza
	mov magistrala,R6
	setb E
	call delay
	clr E
	call delay
	ret
	
	end	