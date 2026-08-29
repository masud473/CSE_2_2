.MODEL SMALL                             
.STACK 100H
.DATA
 DIG DW 10
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
    MOV BX,0                 
INPUT_LOOP:     
    MOV AH,1                         
    INT 21H
    CMP AL,0DH
    JE NEXT      
    AND AX,0FH
    XCHG BX,AX
    MUL DIG
    ADD AX,BX
    XCHG BX,AX
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
    MOV DX,0                                            
    MOV AX,BX  
LOAD_STACK:   
    MOV DX,0          
    DIV DIG                                                     
    PUSH DX          

    INC CX
    CMP AX,0
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