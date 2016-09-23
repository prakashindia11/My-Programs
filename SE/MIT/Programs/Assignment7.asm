;Assignment No : 7
;Aim :
;Name : 
;Roll No : 138
;----------------------------------------------------------------
extern concatenate,substring
        global str1,str1_len,len1
        global str2,str2,len,len2

section .data:

	msg 		db 	10,"Assignment No 7 :  String Manipulation"
			db	10,"--------------------------------------"
	msg_len:	equ 	$-msg
	
	fmsg		db	10,"Enter String 1 : "
	fmsg_len:	equ	$-fmsg

	smsg		db	10,"Enter String 2 : "
	smsg_len:	equ	$-smsg
	
	
	mmsg		db	10,"-----------Menu------------"
			db	10,"1 Concatenation of strings"
			db	10,"2 Occurance Of Character"
			db	10,"3 Exit"
			db	10,"Enter your choice :	"
	mmsg_len:	equ	$-mmsg

	emsg		db	10,"Error!"
	emsg_len:	equ	$-emsg	
;----------------------------------------------------------------
section .bss

	buf		resb	2
	buf_len:	equ	$-buf
	
	str1            resb    20
	str1_len:       equ     $-str1
	
	str2            resb    20
	str2_len:       equ     $-str2
	
	len1		resw	1	
        len2		resw	1 
             	
;----------------------------------------------------------------
%include "macro.asm"
;----------------------------------------------------------------
section .text
	global _start
_start :

        
        
        print msg,msg_len
	
	print fmsg,fmsg_len
	read str1,str1_len
	dec rax
	mov [len1],rax
	
	print smsg,smsg_len
	read str2,str2_len
	dec rax
	mov [len2],rax
	
menu_start: 
	print mmsg,mmsg_len

	read buf,2
	mov al,[buf]

c1 :	cmp al,'1'
	jne c2
	call concatenate
	jmp menu_start

c2 :	cmp al,'2'
	jne c3
	call substring
	jmp menu_start
	
c3 :	cmp al,'3'
	jne error
	exit

error :	print emsg,emsg_len
	jmp menu_start
exit	
;----------------------------------------------------------------

