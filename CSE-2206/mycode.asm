.MODEL SMALL
.STACK 100H
.DATA    
A DW 0
B DW 0   
NL DB 10,13,'$'
.CODE 
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX   
    CALL INPUT
    MOV A,BX      
    MOV AH,9
    LEA DX,NL
    INT 21H
    
    CALL INPUT 
    MOV B,BX       
    
    MOV AH,9
    LEA DX,NL
    INT 21H       
    
    MOV AX,A
    MOV BX,B
    CALL MULTIPLY    
    MOV BX,AX
    CALL OUTPUT
    
    
    
END:
    MOV AH,4CH
    INT 21H
    MAIN ENDP   
    
    
   
INPUT PROC        
    MOV CX,0
    MOV AH,1    
    MOV BX,0
INPUT_LOOP:
    INT 21H                                        
    CMP AL,0DH
    JE REVERSE
    RCR AL,1
    RCL BX,1
    INC CX
    JMP INPUT_LOOP
REVERSE:
    RET
    INPUT ENDP          

OUTPUT PROC
    MOV AH,2
    MOV CX,16
OUTPUT_LOOP: 
    MOV DL,0
    RCL BX,1
    RCL DL,1   
    ADD DL,'0'
    INT 21H
    LOOP OUTPUT_LOOP
    RET                 
    OUTPUT ENDP     
MULTIPLY PROC          
    MOV CX,0
MULTIPLY_LOOP:
    SHR BX,1
    JC CARRY_ONE   
    CMP BX,0
    JE PRESUM 
    INC CX
    PUSH 0    
    SHL AX,1
    JMP MULTIPLY_LOOP    

CARRY_ONE:                                                    
    PUSH AX
    SHL AX,1         
    INC CX
    JMP MULTIPLY_LOOP  
PRESUM:  
    MOV AX,0       
SUM:
    POP BX
    ADD AX,BX
    LOOP SUM      
    RET
    MULTIPLY ENDP    
END MAIN                                                                                       
                           