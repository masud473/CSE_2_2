.MODEL SMALL
.STACK 100H
.DATA    

.CODE
MAIN PROC   
    MOV AX,@DATA
    MOV DS,AX      
    
    MOV CX,4
    MOV AH,1
    MOV BX,0
INPUT:     
    INT 21H 
    CMP AL,'0'
    JB INVALID
    CMP AL,'9'
    JA CAPITAL
    AND AL,0FH
    JMP NEXT
CAPITAL:
    CMP AL,'A'
    JB INVALID
    CMP AL,'F'
    JA SMALL
    SUB AL,'A'
    ADD AL,0AH
    JMP NEXT
SMALL:
    CMP AL,'a'
    JB INVALID
    CMP AL,'f'
    JA INVALID
    SUB AL,'a'
    ADD AL,0AH      
NEXT:         
    SAL BX,4  
    OR BL,AL  
    LOOP INPUT

    MOV CX,4
    MOV AH,2  
    MOV DL,10
    INT 21H
    MOV DL,13
    INT 21H
OUTPUT:      
    ROL BX,4
    MOV DL,BL
    AND DL,0FH     
    CMP DL,10
    JL NUM
    SUB DL,10
    ADD DL,'A'
    JMP PRINT
NUM:
    ADD DL,'0'
    
PRINT:
    INT 21H  
    LOOP OUTPUT
INVALID:
    JMP END
    
END:

    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN