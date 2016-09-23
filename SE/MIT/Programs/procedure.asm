section .data

        cmsg		db	10,"Concatenated string :  "
	cmsg_len:	equ	$-cmsg
	
	ymsg            db      10,"The substring is present."
	ymsg_len:       equ     $-ymsg
	
	nmsg            db      10,"The substring is absent."
	nmsg_len:       equ     $-nmsg
	
	osmsg           db      10,"Number of occurences of substring is : "
	osmsg_len:       equ     $-osmsg
	
	nline		db	10
	nline_len:	equ	$-nline
;----------------------------------------------------------------
section .bss

        str3            resb    20
	str3_len:       equ     $-str3
	
        len3		resw	1
        
        count           resw    1
        
        cur_add         resq    1
        end_add         resq    1
        
        char_ans        resb	4
;----------------------------------------------------------------
%include "macro.asm"
;----------------------------------------------------------------
section .text
	global _main
	
_main :
        
        global concatenate,substring
        extern str1,str1_len,len1
        extern str2,str2,len,len2

concatenate:
        xor rcx,rcx
        
        mov rsi,str1
        mov rdi,str3
        mov cx,[len1]
        mov [len3],cx
        cld
        
        rep movsb
        
        mov rsi,str2
        mov cx,[len2]
        add [len3],cx
        
        rep movsb
        
        print cmsg,cmsg_len
        print str3,[len3]
        print nline,nline_len  
ret

;----------------------------------------------------------------
substring:
        mov rsi,str1
        cld
        xor rcx,rcx
        
        mov [count],rcx
        xor rcx,rcx
        mov rcx,rsi
        mov [cur_add],rsi
        add cx,[len1]
        dec rcx
        mov [end_add],rcx
        
back :  mov rdi,str2
        xor rcx,rcx
        mov cx,[len2]
        repe cmpsb
        jnz continue
        inc word[count]
        
continue :
        inc qword[cur_add]
        mov rsi,[cur_add]
        cmp rsi,[end_add]
        jbe back   
        cmp word[count],00
        je no
        print ymsg,ymsg_len
        jmp last
        
no :    print nmsg,nmsg_len
        
last :  print osmsg,osmsg_len        
        mov ax,[count]
        call disp_16 
        
        print nline,nline_len             
              
ret
;----------------------------------------------------------------
disp_16:
	mov rsi,char_ans+3
	mov rcx,4
cnt:
	mov rdx,0
	mov rbx,16
	div rbx
	cmp dl,09h
	jbe add30
	add dl,07H
add30:
	add dl,30H
	mov [rsi],dl
	dec rsi
	dec rcx
	jnz cnt
print 	char_ans,4
ret
