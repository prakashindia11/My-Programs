mov al,80h      ;CWR
out 67h,al

mov al,01h      ;Latch
out 63h,al

mov al,00h      ;Triangle

back :  out 61h,al
        inc al
        cmp al,0ffh
        jne back
        
back1 : out 61h,al
        dec al
        cmp al,00h
        jne back1
        int 3
