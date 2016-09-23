mov al,01h      ;1st Command Word for left entry 2 key lockout
out 31h,al

mov al,90h      ;Write onto display RAM
out 31h,al

mov ax,cs       ;Initialization of Data Segment
mov ds,ax

again : mov cl,04h      ;Counter for 4 numbers

        mov bx,1000h

back:   mov al,[bx]
        out 30h,al

        mov si,00ffffh  ;Counter for delay
        
delay : dec si
        jnz delay
        inc bx
        dec cl
        jnz back
        jmp again
        
        int 3
