.MODEL SMALL
.STACK 100H
.DATA
INPUT DW ?         
INFO DB 'GIVE TIME INPUT: $'
HR DB 'HR: $'
MIN DB 'MIN: $'
SEC DB 'SEC: $' 
.CODE     
MAIN PROC 
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,9
    LEA DX,INFO
    INT 21H
    
    CALL INDEC
    MOV INPUT,AX       
    CALL NL
    MOV CX,3           
    
MAIN_LOOP:    
    MOV BX,60
    MOV DX,0 ; HR
    DIV BX    
    PUSH DX
    LOOP MAIN_LOOP     
    
PRINT:   
    MOV AH,9
    LEA DX, HR
    INT 21H
    POP BX
    CALL OUTDEC  
    CALL NL
    
    MOV AH,9
    LEA DX, MIN
    INT 21H
    POP BX
    CALL OUTDEC
    CALL NL
    
    MOV AH,9
    LEA DX, SEC
    INT 21H
    POP BX
    CALL OUTDEC    
    MOV AH,4CH
    INT 21H
    MAIN ENDP

INDEC PROC
    PUSH BX
    PUSH CX
    PUSH DX    
    MOV BX,0   
    MOV CX,10
INPUT_LOOP:
    MOV AH,1
    INT 21H
    CMP AL,' '
    JE ENDIT
    CMP AL,0DH
    JE ENDIT 
    AND AX,0FH
    XCHG AX,BX
    MUL CX
    ADD AX,BX
    MOV BX,AX      
    JMP INPUT_LOOP
ENDIT:
    MOV AX,BX
    POP DX
    POP CX
    POP BX
    RET
    INDEC ENDP

OUTDEC PROC
   PUSH AX
   PUSH DX
   PUSH CX
   MOV CX,0    
   MOV AX,BX
   MOV BX,10
STACK_LOAD:    
   MOV DX,0
   DIV BX  
   PUSH DX
   INC CX
   CMP AX,0
   JE  STACK_UNLOAD
   JMP STACK_LOAD
STACK_UNLOAD:    
    MOV AH,2
    POP DX    
    ADD DL,'0'
    INT 21H
    LOOP STACK_UNLOAD
    POP CX
    POP DX
    POP AX
    RET
    OUTDEC ENDP     

NL PROC
    PUSH DX
    PUSH AX
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    POP AX
    POP DX
    RET 
    NL ENDP
END MAIN
    
   
   
    
    
    
    