;Assignment No : 4
;Aim : 
;Name :
;Roll No : 138
;------------------------------------------------------------------------
section .data

	nline	db	10,10
	nline_len:	equ	$-nline

	msg	db	10,10,"Assignment 4 : String Operations"
		db	10,"-----------------------------------",10
	msg_len:	equ	$-msg

	msg1	db	10,"Enter the string : "
	msg1_len:	equ	$-msg1

	msg2	db	10,10,"**********MENU**********"
		db	10,"1 Length of String"
		db	10,"2 Reverse the string"
		db	10,"3 Check if string is palindrome"
		db	10,"4 Exit"
		db	10,"Enter your choice : "
	msg2_len:	equ	$-msg2

	msg3	db	10,"Error!"
	msg3_len:	equ	$-msg3

	msg4	db	10,"Length of string : "
	msg4_len:	equ	$-msg4

	msg5	db	10,"Reverse of string : "
	msg5_len:	equ	$-msg5

	msg6	db	10,"The string is a palindrome"
	msg6_len:	equ	$-msg6

	msg7	db	10,"The string is not palindrome"
	msg7_len:	equ	$-msg7
;------------------------------------------------------------------------
section .bss

	char_ans	resb	4

	buf		resb	2
	buf_len:		equ	$-buf

	source		resb	30
	source_len:	equ	$-source

	dest		resb	30
	dest_len:	equ	$-dest

	len		resw	1
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

	read source,source_len
	dec rax
	mov [len],rax
	
menu_start: 
	print msg2,msg2_len

	read buf,2
	mov al,[buf]

c1 :	cmp al,'1'
	jne c2
	call length
	jmp menu_start

c2 :	cmp al,'2'
	jne c3
	call reverse
	jmp menu_start

c3 :	cmp al,'3'
	jne c4
	call palindrome
	jmp menu_start
	
c4 :	cmp al,'4'
	jne error
	exit

error :	print msg3,msg3_len
	jmp menu_start
exit
;---------------------------------------------------------------------------
length : print msg4,msg4_len
	 mov ax,[len]
	 call disp_16
ret
;---------------------------------------------------------------------------
reverse:
	print	msg5,msg5_len
	mov	rcx,[len]
	mov	rsi,source
	mov	rdi,dest
	add	rdi,rcx
	dec	rdi

back:
	mov	al,[rsi]
	mov	[rdi],al

	inc	rsi
	dec	rdi
	dec	rcx
	jnz	back

	print	dest,[len]

ret
;---------------------------------------------------------------------------
palindrome:
	mov	rcx,[len]
	mov	rsi,source

	mov	rdi,source
	add	rdi,rcx
	dec	rdi
	shr	rcx,1

back1:
	mov	al,[rsi]
	cmp	[rdi],al

	JE	next
	print	msg7,msg7_len
ret

next:
	inc	rsi
	dec	rdi
	dec	rcx
	jnz	back1
	
	print	msg6,msg6_len
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
