diody equ P0
przycisk bit P3.2
przycisk1	bit P3.3
			org 0h
		jmp poczatek
			org 0bh
		jmp licznik0
poczatek:
		mov R1,#0
		mov R2,#0
		mov TMOD,#00000000b;//tryb 13 bitowy
		setb TR0
		setb ET0
		setb EA
		mov diody,#0ffh
start:
	cjne R1,#2,start1
	dec diody
	mov R1,#3
start1:
	cjne R2,#2,start
	inc diody
	mov R2,#3
	jmp start
	
licznik0:
	cjne R1,#0,jedynka
	jb przycisk,wyjdz
	mov R1,#1
	jmp wyjdz
jedynka:
	cjne R1,#1,trojka
	jb przycisk,wyjdz
	mov R1,#2
	jmp wyjdz
trojka:
	cjne R1,#3,czworka
	jnb przycisk,wyjdz
	mov R1,#4
	jmp wyjdz
czworka:
	cjne R1,#4,wyjdz
	jnb przycisk,wyjdz
	mov R1,#0
wyjdz:
	reti
	end
