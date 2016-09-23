mov al,80h      ;CWR
out 67h,al

mov al,01h      ;Latch
out 63h,al

mov al,00h      ;Forward ramp

back :  out 61h,al
        inc al
        jmp back
        int 3
