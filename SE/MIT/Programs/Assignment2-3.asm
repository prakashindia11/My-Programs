;Assignment No : 2
;Aim : 
;Name :
;Roll No : 138
;---------------------------------------------------------
section .data
	nline		db	10,10
	nline_len:	equ	$-nline

	msg1		db 	10,"Assignment 2: Block Transfer Overlap (Without String Instruction)"
			db	10,"----------------------------------------------------",10
	msg1_len		equ	$-msg1
	
	msg2		db	10,"Before transfer"
	msg2_len:	equ	$-msg2
	
	msg3		db	10,"After transfer"
	msg3_len:	equ	$-msg3
	
	msg4		db	10,"Source block : "
	msg4_len:	equ	$-msg4

	msg5		db	10,"Destination block : "
	msg5_len:	equ	$-msg5

	srcblock	db	11h,22h,33h,44h,55h

	destblock	times	5	db	0

	count:		equ	5		
	
	space		db	" "
	
	
;---------------------------------------------------------
section .bss 
	char_ans 	resb	2
;---------------------------------------------------------
%macro	print	2
	mov	rax,	1 		;print/write
	mov	rdi,	1		;stdout	
	mov	rsi,	%1		;msg	
	mov	rdx,	%2		;msg_len
	syscall  
%endmacro
%macro	exit	0
	mov	rax,	60
	mov	rdi,	0
	syscall
%endmacro
;-----------------------------------------------------------
section .text
	global _start
_start :
	print	msg1,msg1_len
	
	print	msg2,msg2_len
	call	display_blocks
BT_NO:
	mov	rsi,srcblock
	mov	rdi,destblock
	mov	rcx,count
	
back:	mov	al,[rsi+4]
	mov	[rdi+2],al
	dec	rsi
	dec	rdi
	dec	rcx
	jnz	back

	print	msg3,msg3_len
	call	display_blocks
	
exit
;----------------------------------------------------------
display_blocks:
	print	msg4,msg4_len
	mov	rsi,srcblock
	call	display

	print	msg5,msg5_len
	mov	rsi,destblock
	call	display

	print	nline,nline_len
ret
;-----------------------------------------------------------
display: 
	mov	rbp,count
repeat:
	mov	al,[rsi]
	push	rsi
	call	disp_16
	print	space,1
	pop	rsi
	inc	rsi
	dec	rbp
	jnz	repeat

ret
;----------------------------------------------------------------
disp_16: 
	mov rsi,char_ans+1
	mov rcx,2
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
print 	char_ans,2
ret
