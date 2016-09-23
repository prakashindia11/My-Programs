mov al,01h      ;1st Command Word for left entry for flashing
out 31h,al

mov al,90h      ;2nd Command Word
out 31h,al

mov ax,cs       ;Initialization of Data Segment
mov ds,ax

again : mov cl,04h      ;Counter for 4 numbers

        mov bx,1000h

back:   mov al,[bx]
        out 30h,al
        inc bx
        dec cl
        jnz back
        
        mov si,00ffffh
        
delay : dec si
        jnz delay
        
        mov cl,04h
        mov bx,1005h
        
        mov al,[bx]
        
back1 : out 30h,al
        inc bx
        dec cl
        jnz back1
        
        mov si,00ffffh
        
delay1: dec si
        jnz delay
        jmp again
        
        int 3


