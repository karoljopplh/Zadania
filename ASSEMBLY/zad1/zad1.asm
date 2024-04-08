	org 0h
	jmp start
	org 100h
start:	mov R0,#30h
	mov R7,#20
skok:	mov @R0,#55h
	inc R0
	djnz R7,skok
stop:	jmp stop
end