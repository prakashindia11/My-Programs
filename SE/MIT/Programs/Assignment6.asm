exit macro
        mov ah,4ch
        mov al,00h
        int 21h
endm

print macro msg
        mov ah,09h
        lea dx,msg
        int 21h
endm

putch macro ch
        mov ah,02h
        mov dl,ch
        int 21h
endm
;........................................................
data segment
        no1     db      18h
        no2     db      10h
        res     db      ?
        msg     db      10,13,"Assignment No 6 $"
        msg1    db      10,13,"Addition is : $"
data ends
;........................................................
code segment

assume cs:code,ds:data

start:
        mov ax,data		;Initialize ds as data segment
        mov ds,ax
        print msg

        mov al,no1
        mov bl,no2
        add al,bl		;Add no1 and no2. Result in al
        mov res,al		;Move content of al in res
        print msg1
        mov al,res
        call display_8
exit
;........................................................
display_8 proc
        mov ch,02       ;Counter
        mov cl,04       ;No of bits to be rotated

back:   rol al,cl
        push ax
        and al,0fh
        cmp al,09h
        jbe add30
        add al,07h

add30:  add al,30h
        putch al
        pop ax
        dec ch
        jnz back
ret
display_8 endp

code ends
end start

