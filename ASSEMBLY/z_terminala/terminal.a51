	org 0h
	jmp start
	org 23h
	jmp serial
magistrala	equ P0
RS	bit P1.2
RW	bit P1.1
E	bit P1.0

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
	mov TMOD,#00100000b
	mov TH1,#0FDh
	setb TR1
	;setb ET1
	mov R5,#0
	mov SCON,#50h//transmisja asynchroniczna 8-bitowa
	mov IP,#00010000b//priorytety przerwan
	setb PS
	setb ES
	setb EA
stop:
	jmp stop

serial:
	mov R6,SBUF
	cjne R5,#16,skok
	clr RS
	mov R6,#0C0h
	call LCDwrite
	mov R6,SBUF
skok:
	cjne R5,#32,pisz
	mov R5,#0
	clr RS
	mov R6,#01h//czyszczenie ekranu
	call LCDwrite
	;mov R6,#80h//potrzebny duzy delay
	;call LCDwrite
	mov R6,SBUF
pisz:	
	setb RS
	call LCDwrite
	clr RI
	inc R5
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
	
napis:	db "WSTI w Katowicach. $"	
	
	end