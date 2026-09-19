.MODEL SMALL
.STACK 100H
.DATA
ARR DB 50 DUP('$')  
PASSED DB 'PALINDROME$'
FAILED DB 'NOT PALINDROME$'
.CODE  
MAIN PROC 
    MOV AX,@DATA
    MOV DS,AX
    
    CALL INPUT         
    CALL NL
    
    LEA DI,ARR     
    
    MOV AX,DI  ; POINTER SWAP
    XCHG SI,AX
    MOV DI,AX
CHECK:
    MOV AX,SI
    CMP AX,DI
    JGE PASS
    
    MOV AL,[SI]
    CMP AL,[DI]
    JNE FAIL
    INC SI
    DEC DI
    JMP CHECK
PASS:
    MOV AH,9
    LEA DX, PASSED
    INT 21H
    JMP ENDIT 
FAIL:
    MOV AH,9
    LEA DX, FAILED
    INT 21H
    JMP ENDIT
ENDIT:
    MOV AH,4CH
    INT 21H  
    MAIN ENDP
  
        
INPUT PROC  
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX
    LEA SI,ARR
    MOV CX,0
    MOV AH,1
INPUT_LOOP:
    INT 21H
    CMP AL,0DH
    JE INPUT_END
    
    MOV [SI],AL
    INC SI
    JMP INPUT_LOOP
    
INPUT_END:
    DEC SI; POINTS TO THE LAST ELEMENT
    POP DX
    POP CX
    POP BX
    POP AX
    RET
    INPUT ENDP
NL PROC
    PUSH AX
    PUSH DX
    MOV AH,2
    MOV DL,0DH
    INT 21H
    MOV DL,0AH
    INT 21H
    POP DX
    POP AX
    RET 
    NL ENDP
END MAIN
    
    
    
    
    