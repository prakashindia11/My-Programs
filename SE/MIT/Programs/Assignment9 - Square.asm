mov al,80h      ;CWR
out 67h,al

mov al,01h      ;Latch
out 63h,al

repeat : mov al,00h     ;Square
         out 61h,al
         mov cx,0ffh
         
back :   dec cx 
         jnz back
         mov al,00ffh
         out 61h,al
         mov cx,00ffh
         
back1 : dec cx
        jnz back1
        jmp repeat
        int 3
