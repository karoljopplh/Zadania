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
	mov TMOD,#00000001b
	mov TH0,#10h
	mov TL0,#00h
	setb TR0
	setb ET0
	setb EA
stop:
	jmp stop

licznik0:
	mov TH0,#10h
	inc R5
	cjne R5,#15,wyjdz
	cpl P3.7
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
	end