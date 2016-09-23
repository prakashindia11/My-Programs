;MIL Assignment No. 1
;X86/64 Assembly language program (ALP) 
;Addition of N 16-bit nos, result is 32 bit.
;Accept input from the user. Display the result.
;---------------------------------------------------------------------
section .data
	nline		db	10,10
	nline_len:	equ	$-nline

	msg 		db 	10,"MIL assignment 01 : Addition of N 16-bit nos."
			db	10,"---------------------------------------------",10
	msg_len:	equ 	$-msg

	smsg 		db 	10,"Enter size of array <????> = "
	smsg_len:	equ 	$-smsg

	amsg 		db 	10,"Enter data <????>	= "
	amsg_len:	equ 	$-amsg

	dmsg 		db 	10,"Result <????????>	= "
	dmsg_len:	equ 	$-dmsg

	emsg 		db 	10,"You entered Invalid Data!!!",10
	emsg_len:	equ 	$-emsg
;---------------------------------------------------------------------
section .bss
	buf 		resb 	5		;4digits + enter
	buf_len:	equ 	$-buf
	size		resw	1
	resl		resw	1
	resh		resw	1
	char_res	resb	4
;---------------------------------------------------------------------
;macros as per 64-bit convensions

%macro  print   2
	mov 	rax,1		; Function 1 - write
  	mov 	rdi,1		; To stdout
   	mov 	rsi,%1		; String address
   	mov 	rdx,%2		; String size
   	syscall			; invoke operating system to WRITE
%endmacro

%macro  read   2
	mov 	rax,0		; Function 0 - Read
  	mov 	rdi,0		; from stdin
   	mov 	rsi,%1		; buffer address
   	mov 	rdx,%2		; buffer size
   	syscall			; invoke operating system to READ
%endmacro

%macro	exit	0
	mov rax, 60		; system call 60 is exit
	xor rdi, rdi 		                   ; we want return code 0
	syscall 		                   ; invoke operating system to exit
%endmacro
;--------------------------------------------------------------- 
section .text
	global _start
_start:
	print	msg,msg_len	; "MIL assignment 01 : Addition of N 16-bit nos."

	print	smsg,smsg_len	; "Enter size of array <????> = "
	read	buf,buf_len
	call	accept_16
	mov	[size],bx

	mov 	rbp,[size]
next_num:
	print	amsg,amsg_len	; "Enter data <????>	= "
	read	buf,buf_len
	call	accept_16
	add	[resl],bx
	jnc	next

	inc	word [resh]
next:	dec	rbp
	jnz	next_num	
	
	print 	dmsg,dmsg_len	; "Result <???? ????>	= "
	mov 	rax,[resh]	; load value of resh in rax
	call 	disp16_proc	; display result

	mov 	rax,[resl]	; load value of resl in rax
	call 	disp16_proc	; display result

	print	nline, nline_len
	exit
;------------------------------------------------------------------
accept_16:
	xor 	bx,bx
	mov 	rcx,04
	mov 	rsi,buf
next_digit:
	rol	bx,04
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

error:  print 	emsg,emsg_len	; "You entered Invalid Data!!!"  
        exit

sub57:	sub    	al,20h      	; subtract 57h if no is in the range 'a'-'f'
sub37:  sub    	al,07h      	; subtract 37h if no is in the range 'a'-'f'
sub30:  sub    	al,30h      	; subtract 30h if no is in the range '0'-'9'
    	
	add	bx,ax		; prepare number
	inc	rsi		; point to next digit
	loop	next_digit
ret


;------------------------------------------------------------------
disp16_proc:
	mov 	rsi,char_res+3	; load last byte address of char_res in rsi
	mov 	rcx,4		; number of digits 

cnt:	mov 	rdx,0		; make rdx=0 (as in div instruction rdx:rax/rbx)
	mov 	rbx,16		; divisor=16 for hex
	div 	rbx
	cmp 	dl, 09h		; check for remainder in RDX
	jbe  	add30
	add  	dl, 07h 
add30:
	add 	dl,30h		; calculate ASCII code
	mov 	[rsi],dl	; store it in buffer
	dec 	rsi		; point to one byte back

	dec 	rcx		; decrement count
	jnz 	cnt		; if not zero repeat
	
	print char_res,4	; display result on screen
ret
;----------------------------------------------------------------
