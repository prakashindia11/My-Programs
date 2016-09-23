mov al,80h      ;CWR
out 67h,al

mov al,01h      ;Latch
out 63h,al

mov al,00h      ;Staircase

back :	out 61h,al
	mov cx,00ffh
	
delay :	dec cx
	jnz delay
	add al,55h
	cmp al,0ffh
	jne back

back1 :	out 61h,al
	mov cx,00ffh
	
delay1 :dec cx
	jnz back1
	sub al,55h
	cmp al,00h
	jne back1
	jmp back
	
	int 3
