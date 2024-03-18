wyswietlacz equ P0
cyfra0 bit P1.0
przycisk bit P3.2
przycisk1	bit P3.3
			org 0h
		jmp poczatek
			org 0bh
		jmp licznik0
poczatek:
		clr cyfra0
		mov DPTR, #seg7
		mov R1,#0
		mov R2,#0
		mov R3,#0
		mov TMOD,#00000000b;//tryb 13 bitowy
		setb TR0
		setb ET0
		setb EA
		mov wyswietlacz,#0ffh
start:
	mov A, R3
	movc A,@A+DPTR
	mov wyswietlacz,A
	cjne R1,#2,start1
	mov R1,#3
	inc R3
	cjne R3,#10,start1
	
start1:
	cjne R2,#2,start
	mov R2,#3
	dec R3
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

jedynka1:
	cjne R2,#1,trojka1
	jb przycisk1,wyjdz1
	mov R2,#2
	jmp wyjdz1
trojka1:
	cjne R2,#3,czworka1
	jnb przycisk1,wyjdz1
	mov R2,#4
	jmp wyjdz1
czworka1:
	cjne R2,#4,wyjdz1
	jnb przycisk1,wyjdz1
	mov R2,#0
wyjdz1:
	reti
seg7:	db 0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x00,0x10
wyjdz:
	reti
	end
