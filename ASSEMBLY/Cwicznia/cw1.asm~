	org 0h
	mov R7,#20
	mov DPTR,#100h
	mov R6,#0
	mov R5,#0
dalej:	mov A,R5
	movc A,@A+DPTR
	mov B,A
	clr CY
	subb A,#101
	jc omin
	clr CY
	mov A,B
	subb A,#200
	jnc omin
	inc R6
omin:	inc R5
	djnz R7,dalej
	mov 30h,R6
stop:	jmp stop

	org 100h
	db 10,20,30,40,201,210,200,80,90,99
	db 100,101,110,120,130,140,150,160,170,180

end