.MODEL SMALL
.STACK 100H
.DATA
ARR DW 100 DUP (0)
N DW 13         
DIG DW 10
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX    
    
    CALL INPUT   
    MOV N,AX     
    CALL NL
    MOV CX,N 
    LEA SI,ARR
ARR_LOOP:
    CALL INPUT    
    MOV [SI],AX
    ADD SI,2        
    LOOP ARR_LOOP           
    
    LEA SI,ARR   
    LEA DI,ARR
    SHL N,1
    ADD DI,N
    SHR N,1
    MOV CX,N
    CALL NL
SORT_LOOP:
    PUSH SI
    CALL MIN              
    POP BX
    CALL POS
    LOOP SORT_LOOP      
    
    MOV CX,N    
    LEA SI,ARR
PRINT_SORTED: 
     MOV DX,[SI]
     CALL OUTPUT   
     ADD SI,2
     MOV AH,2
     MOV DL,' '
     INT 21H
     LOOP PRINT_SORTED
    

PRINT_MAX:   
    CALL NL
    CALL MAX
    MOV DX,AX   
    CALL OUTPUT
END:           
    MOV AH,4CH
    INT 21H
    MAIN ENDP
    
    
MIN PROC
    MOV BX,SI
    MOV AX,[SI]
MIN_LOOP:   
    ADD BX,2
    CMP BX,DI  
    JGE MIN_END
    CMP AX,[BX]
    JL MIN_LOOP
    MOV AX,[BX]
    MOV SI,BX
    JMP MIN_LOOP
MIN_END:
    RET
    MIN ENDP       

POS PROC
    MOV AX,[BX]
    XCHG AX,[SI]
    MOV [BX],AX
    MOV SI,BX
    ADD SI,2
    RET
    POS ENDP    

MAX PROC
    LEA SI,ARR
    MOV AX,[SI]
    LEA DI,ARR
    SHL N,1
    ADD DI,N
    SHR N,1
MAX_LOOP:
    ADD SI,2
    CMP SI,DI
    JGE MAX_END
    CMP AX,[SI]
    JG MAX_LOOP
    MOV AX,[SI] 
    JMP MAX_LOOP
MAX_END:
    RET
    MAX ENDP            

INPUT PROC     
     PUSH BX
     PUSH CX
     MOV BX,0      
     MOV CX,10
INPUT_LOOP:
    MOV AH,1
    INT 21H
    CMP AL,0DH
    JE INPUT_END    
    CMP AL, ' '
    JE INPUT_END
    XCHG AX,BX
    MUL CX
    AND BX,0FH
    ADD AX,BX
    MOV BX,AX
    JMP INPUT_LOOP
INPUT_END:
    MOV AX,BX   
    POP CX
    POP BX
    RET 
    INPUT ENDP
     
                
OUTPUT PROC
    MOV AX,DX  
    PUSH CX
    PUSH BX 
    MOV CX,0 
    MOV BX,10
OUTPUT_LOOP:
    MOV DX,0
    DIV BX
    PUSH DX  
    INC CX
    CMP AX,0
    JNE OUTPUT_LOOP   
    MOV AH,2
PRINT_LOOP:
    POP DX 
    ADD DX,'0' 
    INT 21H   
    LOOP PRINT_LOOP   
    POP BX
    POP CX
    RET 
    OUTPUT ENDP

NL PROC     
    PUSH AX
    PUSH DX
    MOV AH,2
    MOV DL,10
    INT 21H
    MOV DL,13 
    INT 21H
    POP DX
    POP AX
    RET
    NL ENDP
END MAIN