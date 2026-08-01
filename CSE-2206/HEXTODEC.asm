.MODEL SMALL
.STACK 100H
.DATA
.CODE
MAIN PROC

    MOV AX, @DATA 
    MOV DS, AX 
    
    MOV AH,1
    INT 21H
    MOV BL,AL
    
    MOV AH,2 
    MOV DL, ' '
    INT 21H
    
    MOV DL,'1'
    INT 21H
    
    SUB BL,'A'   
    ADD BL,'0'
    MOV DL,BL
    INT 21H
    
    MOV AH, 4CH
    INT 21H 
MAIN ENDP
END MAIN