	org 0h
		;mov P0,#01010101b
		;mov P0,#11111101b
		;mov P0,#0Fh ;00001111
		mov A,#0Fh
		mov P0,A
		;clr P0.0
		;setb P0.1
stop: 	jmp stop
		end