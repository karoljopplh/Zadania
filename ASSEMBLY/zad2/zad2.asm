	org 0h
	mov 30h,#0
	mov 31h,#0
	mov R7,#0
	mov DPTR,#100h
skok:	mov A,R7
	movc A,@A+DPTR
	add A,30h
	mov 30h,A
	JNC omin
	inc 31h
omin:	inc R7
	cjne R7,#5,skok
stop:	jmp stop
	org 100h
db	40,50,60,70,80
end