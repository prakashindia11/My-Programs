.model tiny
CODE SEGMENT
	ASSUME	CS:CODE 

	ORG	100H             ;PSP ADDRRESS IN MEMORY
BEGIN:
	JMP	INIT
	
	OFF1	DW 	?
	SEG1	DW 	?

	HR 	DB 	?
	MIN 	DB 	?
	SEC 	DB 	?
;---------------------------------------------
TEST1:
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	PUSH SI
	PUSH DI
	PUSH SP
	PUSH BP


	MOV 	AX,0B800H 		   ;VIDEO RAM ADDREESS
	MOV	ES,AX

               MOV     AH,02                		   ;READING CURRENT TIME
	INT	1AH

	MOV	HR,CH
	MOV	MIN,CL
	MOV	SEC,DH

               MOV     BX,1992                                 ;[ POSITION ON SCREEN TO DISPLAY 
					    ;  CURRENT TIME ATTRIBUTE]

	MOV	AL,HR
	CALL	DISP
	CALL	COLON
	MOV 	AL,MIN
	CALL	DISP
	CALL	COLON

	MOV 	AL,SEC
	CALL	DISP

	POP	BP
	POP	SP
	POP	DI
	POP	SI
	POP	DX
	POP	CX
	POP	BX
	POP	AX

        JMP     DWORD PTR OFF1
;---------------------------------------------
DISP 	PROC
	MOV 	CH,02H
	MOV 	CL,04H
BACK:
	ROL 	AL,CL
	MOV 	DL,AL
	AND 	DL,0FH
	ADD 	DL,30H

        MOV     ES:[BX],DL
	INC 	BX
        MOV     BYTE PTR ES:[BX],0BH
	INC 	BX
	
	DEC 	CH
	JNZ 	BACK
	
	RET
DISP 	ENDP
;---------------------------------------------
COLON 	PROC
        MOV BYTE PTR ES:[BX],':'
     	INC BX
        MOV BYTE PTR ES:[BX],8EH
     	INC BX
     	RET
COLON 	ENDP
;---------------------------------------------

INIT:
	PUSH 	CS		; mov	ax,cs
	POP 	DS		; mov	ds,ax

              MOV     AX,0002              ;CLEAR WHOLE SCREEN
              INT     10H                         ;or set video mode to 80x25

	CLI

               MOV     AH,35H               ;RETURN ADDRESS OF 08 INTRUPT FROM IVT  
	MOV 	AL,08H
	INT 	21H

               MOV     OFF1,BX
	MOV 	SEG1,ES

	MOV 	AH,25H
	MOV 	AL,08H
	LEA 	DX,TEST1
	INT 	21H

	STI

        	MOV     AH,31H          
        	MOV     AL,00           
        	LEA     DX,INIT       	  ;MEMORY REQIRED FOR PROGRAM
               	                 	  ;(16 BYTE PER PARAGRAPH)
	INT 	21H
;---------------------------------------------
EXIT:  	 MOV     AH,4CH
        	MOV     AL,00H
	INT 	21H
CODE ENDS
	END BEGIN
