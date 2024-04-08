	org 0h
	mov R7,#0
jedynka:setb CY
	mov A,R7
	mov P1,R7
	RRC A
	mov R7,A
	cjne R7,#255,jedynka
zero:	clr Cy
	mov A,R7
	mov P1,R7
	RRC A
	mov R7,A
	cjne R7,#0,zero
	jmp jedynka