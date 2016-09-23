;Assignment No : 5
;Aim : Write a ALP to perform multiplication of two HEX numbers by
;Add Shift method and successive addition method
;Name : 
;Roll No : 
;----------------------------------------------------------------
section .data

	nline	db	10,10
	nline_len:	equ	$-nline

	msg	db	10,"Assignment 5 : Multiplication of 2 HEX numbers"
	msg_len:	equ	$-msg

	fmsg	db	10,"Enter 1st Number : "
	fmsg_len:	equ	$-fmsg

	smsg	db	"Enter 2nd Number : "
	smsg_len:	equ	$-smsg

	mmsg	db	10,10,"............Menu..........."
		db	10,"1 Successive Additon Method"
		db	10,"2 Add & Shift Method"
		db	10,"3 Exit"
		db	10,"Enter your choice : "
	mmsg_len:	equ	$-mmsg	

	emsg	db	10,"Error !"
	emsg_len:	equ	$-emsg	
;----------------------------------------------------------------
section .bss
	buf	resb	5
	no1	resw	1
	no2	resw	1
	resl	resw	1
	resh	resw	1
	ans	resd	1		
	char_ans	resb	4
;----------------------------------------------------------------
%macro print 2
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

%macro read 2
	mov rax,0
	mov rdi,0
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

%macro exit 0
	mov rax,60
	mov rdi,00
	syscall
%endmacro
;----------------------------------------------------------------
section .text
global _start:
_start:
	print msg,msg_len

	print fmsg,fmsg_len
	call accept_16
	mov [no1],bx
	
	print smsg,smsg_len
	call accept_16
	mov [no2],bx

menu : 
	print mmsg,mmsg_len
	read buf,2
	mov al,[buf]

c1 : 	cmp al,'1'
     	jne c2
	call sa
     	jmp menu

c2 : 	cmp al,'2'
     	jne c3
	call as
     	jmp menu 

c3 : 	cmp al,'3'
     	jne error1
     	exit

error1 : print emsg,emsg_len
 		
exit
;----------------------------------------------------------------
sa :	
	xor rdx,rdx	
	mov bx,[no1]
	mov cx,[no2]
	xor rax,rax

back1 :	add rax,rbx
	dec rcx
	jnz back1	
	
	mov [resl],rax
	mov [resh],rdx
	jnz back1

	mov rax,[resh]
	call disp16_proc
	mov rax,[resl]
	call disp16_proc	
ret
;----------------------------------------------------------------
as :
	mov rcx,16
	mov ax,[no1]
	mov bx,[no2]	

back2 :	shl dword[ans],1
	shl ax,1
	jnc next
	add [ans],bx

next : dec rcx
       jnz back2

	mov ax,[ans+2]
	call disp16_proc
        mov ax,[ans+0]
	call disp16_proc
ret
;----------------------------------------------------------------
accept_16:
	read buf,5
	xor 	bx,bx
	mov 	rcx,04
	mov 	rsi,buf

next_digit:
	shl	bx,04
	mov	al,[rsi]
       
	cmp    	al,'0'     	; '0' = 30h or 48d
        jb     	error2      	; jump if below '0' to error
        cmp    	al,'9'   
        jbe    	sub30     	; subtract 30h if no is in the range '0'-'9'

        cmp    	al,'A'    	; 'A' = 41h or 65d
        jb     	error2       	; jump if below 'A' to error
        cmp    	al,'F'
        jbe    	sub37       	; subtract 37h if no is in the range 'A'-'F'

        cmp    	al,'a'      	; 'a' = 61h or 97d
        jb     	error2       	; jump if below 'a' to error
        cmp    	al,'f'
        jbe     sub57       	; subtract 57h if no is in the range 'a'-'f'

error2:  print 	emsg,emsg_len	; "Error"  
         exit

sub57:	sub    	al,20h      	; subtract 57h if no is in the range 'a'-'f'
sub37:  sub    	al,07h      	; subtract 37h if no is in the range 'a'-'f'
sub30:  sub    	al,30h      	; subtract 30h if no is in the range '0'-'9'
    	
	add	bx,ax		; prepare number
	inc	rsi		; point to next digit
	loop	next_digit
ret
;----------------------------------------------------------------
disp16_proc:
	mov 	rsi,char_ans+3	; load last byte address of char_res in rsi
	mov 	rcx,4		; number of digits 

cnt:	mov 	rdx,0		; make rdx=0 (as in div instruction rdx:rax/rbx)
	mov 	rbx,16		; divisor=16 for hex
	div 	rbx
	cmp 	dl, 09h		; check for remainder in RDX
	jbe  	add30
	add  	dl, 07h 

add30:	add 	dl,30h		; calculate ASCII code
	mov 	[rsi],dl	; store it in buffer
	dec 	rsi		; point to one byte back
	dec 	rcx		; decrement count
	jnz 	cnt		; if not zero repeat
	
	print char_ans,4	; display result on screen
ret
;----------------------------------------------------------------
