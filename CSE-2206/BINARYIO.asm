.MODEL SMALL
.STACK 100H
.DATA    
D DW ?
.CODE
MAIN PROC   
    MOV AX,@DATA
    MOV DS,AX      
    
    MOV CX,16
    MOV AH,1
    MOV BX,0
INPUT:     
    INT 21H
    SHR AL,1
    RCL BX,1
    LOOP INPUT           
    
    MOV CX,16   
    MOV AH,2   
    MOV DL,10
    INT 21H
    MOV DL,13 
    INT 21H
OUTPUT:     
    MOV DX,0
    SHL BX,1
    RCL DX,1
    ADD DX,'0'   
    INT 21H
    LOOP OUTPUT
    
    
END:
    MOV D,BX
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN