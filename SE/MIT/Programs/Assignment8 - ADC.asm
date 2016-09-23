mov ax,cs               ;Initialization of data segment
mov ds,ax

mov al,99h              ;Initializing CWR
out 67h,al

mov al,05h              ;EO,SOC
out 63h,al

mov al,04h
out 63h,al              ;Reset SOC for conversion

back :  in al,65h       ;Read data from Port C
        test al,01h     ;Test for EOC = 1
        jz back

mov al,06h              ;Enable output
out 63h,al

in al,61h
mov bx,3000
mov [bx],al
int 3

