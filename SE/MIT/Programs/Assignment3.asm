;Assignment No : 3
;Aim : 
;Name :
;Roll No : 138
;------------------------------------------------------------------------
section .data

	nline	db	10,10
	nline_len:	equ	$-nline

	msg	db	10,10,"Assignment 2 : Number Conversion"
		db	10,"-----------------------------------------",10
	msg_len:	equ	$-msg

	msg1	db	10,"**********MENU**********"
		db	10,"1 HEX to BCD Conversion"
		db	10,"2 BCD to HEX Conversion"
		db	10,"3 Exit"
		db	10,"Enter your choice : "
	msg1_len:	equ	$-msg1

	msg2	db	10,"HEX to BCD CONVERSION"
	msg2_len:	equ	$-msg2

	msg3	db	10,"Enter 4-digit HEX Number : "
	msg3_len:	equ	$-msg3

	msg4	db	"Equivalent BCD Number : "
	msg4_len:	equ	$-msg4

	msg5	db	10,"BCD to HEX CONVERSION"
	msg5_len:	equ	$-msg5

	msg6	db	10,"Enter 5-digit BCD Number : "
	msg6_len:	equ	$-msg6

	msg7	db	"Equivalent HEX Number : "
	msg7_len:	equ	$-msg7

	msg8	db	10,"Error!"
	msg8_len:	equ	$-msg8
;------------------------------------------------------------------------
section .bss

	buf	resb	6
	buf_len:	equ	$-buf

	char_ans	resb	6

	digitcount	resb	5

	ans		resw	1
;------------------------------------------------------------------------
%macro	print	2
	mov	rax,	1 		
	mov	rdi,	1		
	mov	rsi,	%1		
	mov	rdx,	%2	
	syscall  
%endmacro

%macro	read	2
	mov	rax,	0 		
	mov	rdi,	0		
	mov	rsi,	%1		
	mov	rdx,	%2	
	syscall  
%endmacro

%macro	exit	0
	mov	rax,	60
	mov	rdi,	0
	syscall
%endmacro
;-------------------------------------------------------------------------
section .text
	global _start:

_start:
	print msg,msg_len
	print msg1,msg1_len

	read buf,2
	mov al,[buf]

c1 :	cmp al,'1'
	jne c2
	call hex_bcd
	jmp _start

c2 :	cmp al,'2'
	jne c3
	call bcd_hex
	jmp _start

c3 :	cmp al,'3'
	jne error
	exit
	
error :	print msg8,msg8_len
	jmp _start

exit
;--------------------------------------------------------------------------
hex_bcd :print msg2,msg2_len
	 print msg3,msg3_len
	 call accept_16
	 mov ax,bx
	 mov rbx,10
	 	 
back1 :	xor rdx,rdx
	div rbx
	push dx
	inc byte[digitcount]
	cmp ax,0
	jnz back1

	print msg4,msg4_len

print_bcd : pop	dx
	    add dl,30H
	    mov [char_ans],dl
	    print char_ans, 1
	    dec byte[digitcount]
	    jnz print_bcd
ret
;--------------------------------------------------------------------------
bcd_hex :print msg5,msg5_len
	 print msg6,msg6_len
	 read buf,buf_len
	 xor rax,rax
	 mov bx,10
	 mov rcx,05
	 mov rsi,buf

back2 :
	xor	rdx,rdx
	mul	rbx
	mov	dl,[rsi]
	sub	dl,30h
	add	rax,rdx
	inc	rsi
	dec	rcx
	jnz	back2

	mov	[ans],ax
	print	msg7,msg7_len
	mov	ax,[ans]
	call	disp_16
ret
;---------------------------------------------------------------------------
accept_16:
	read buf, 5
	xor 	bx,bx
	mov 	rcx,04
	mov 	rsi,buf
next_digit:
	shl	bx,04
	mov	al,[rsi]
        cmp    	al,'0'     	; '0' = 30h or 48d
        jb     	error      	; jump if below '0' to error
        cmp    	al,'9'   
        jbe    	sub30     	; subtract 30h if no is in the range '0'-'9'

        cmp    	al,'A'    	; 'A' = 41h or 65d
        jb     	error       	; jump if below 'A' to error
        cmp    	al,'F'
        jbe    	sub37       	; subtract 37h if no is in the range 'A'-'F'

        cmp    	al,'a'      	; 'a' = 61h or 97d
        jb     	error       	; jump if below 'a' to error
        cmp    	al,'f'
        jbe     sub57       	; subtract 57h if no is in the range 'a'-'f'

sub57:	sub    	al,20h      	; subtract 57h if no is in the range 'a'-'f'
sub37:  sub    	al,07h      	; subtract 37h if no is in the range 'A'-'F'
sub30:  sub    	al,30h      	; subtract 30h if no is in the range '0'-'9'
    	
	add	bx,ax		; prepare number
	inc	rsi		; point to next digit
	loop	next_digit
ret
;---------------------------------------------------------------------------
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
