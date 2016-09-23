%macro	print	2
	
	mov	rax,	1 		;print/write
	mov	rdi,	1		;stdout	
	mov	rsi,	%1		;msg	
	mov	rdx,	%2		;msg_len
	syscall  
%endmacro

%macro	read	2
	
	mov	rax,	0		;read/scan
	mov	rdi,	0		;stdin
	mov	rsi,	%1		;buf
	mov	rdx,	%2		;buf_len
	syscall
%endmacro

%macro	exit	0

	mov	rax,	60
	mov	rdi,	0
	syscall
%endmacro
