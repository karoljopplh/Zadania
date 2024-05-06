	org 0h
	jmp start
magistrala	equ P0
RS	bit P1.2
RW	bit P1.1
E	bit P1.0
	org 0bh
	jmp licznik0

start:
	clr RW
	clr RS
	mov R6,#38h
	call LCDwrite
	mov R6,#6h
	call LCDwrite
	mov R6,#0Fh
	call LCDwrite
	mov R6,#1h
	call LCDwrite
	mov TMOD,#00100001b
	mov TH1,#0FDh
	mov TH0,#10h
	mov TL0,#00h
	mov R5,#0
	mov DPTR,#napis2
	mov R4,#0
	setb TR0
	setb TR1
	setb ET1
	setb ET0
	setb EA
	mov SCON,#50h
stop:
	jmp stop

licznik0:
	mov TH0,#10h
	inc R5
	cjne R5,#5,wyjdz
	mov R5,#0
	mov A,R4
	movc A,@A+DPTR
	cjne A,#'$',wyswietl
	jmp wyjdz
wyswietl:
	setb RS
	mov R6,A
	call LCDwrite
	cjne R3,#32,skok2
	mov R3,#0
	clr RS
	mov R6,#80h
	call LCDwrite
	setb RS
	mov R6,A
	call LCDwrite
	jmp skok1
skok2:	
	cjne R3,#16,skok1
	mov R6,#0C0h
	clr RS
	call LCDwrite
	setb RS
	mov R6,A
	call LCDwrite
	;jmp wyjdz
skok1:	
		mov SBUF,A
		inc R4
		inc R3
wyjdz:
	reti

delay:
	mov R7,#5
sk1:
	djnz R7,sk1
	ret
	
LCDwrite:
	mov magistrala,R6
	setb E
	call delay
	clr E
	call delay
	ret
	
napis2:	db "aaaaaaaaaaaaaaaa dupa dupa dupa cycki cycki cycki"
napis:	db "WSTI w Katowicach. $"	
	
	end