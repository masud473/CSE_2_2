.MODEL SMALL                             
.STACK 100H
.DATA
 DIG DB 10
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX         
    CALL INPUT          
    CALL NL
    CALL OUTPUT
    MOV AH,4CH
    INT 21H
    MAIN ENDP
    
    
    
    
    
INPUT PROC
    MOV BL,0
    MOV AH,1
INPUT_LOOP:     
    MOV AH,1
    INT 21H
    CMP AL,0DH
    JE NEXT
    XCHG BL,AL
    MUL DIG
    SUB BL,'0'
    ADD AL,BL
    XCHG BL,AL
    JMP INPUT_LOOP
NEXT:
    RET
    INPUT ENDP   


NL PROC
    MOV AH,2
    MOV DL,0DH
    INT 21H
    MOV DL,0AH
    INT 21H
    RET
    NL ENDP     
                                       

OUTPUT PROC         
    MOV CX,0   
    MOV AX,0                                            
    MOV AL,BL  
LOAD_STACK:             
    DIV DIG
    ROR AX,8
    PUSH AX
    INC CX
    SHR AX,8
    CMP AL,0
    JNE LOAD_STACK
    
    MOV AH,2
UNLOAD_STACK:        
    POP DX      

    ADD DX,'0'
    INT 21H    
    LOOP UNLOAD_STACK
    RET 
    OUTPUT ENDP
    
    

END MAIN