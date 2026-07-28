.MODEL SMALL
.STACK 100H
                              
.DATA 
A DW ?
B DW ?
C DW ?

.CODE 
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,1
    INT 21H    
    
    SUB AX,'0'
    
    MOV BX,AX;B=A
    INC AX;A++
   
    MOV CX,BX;C=B
    INC BX;B++
    INC AX;++A
    SUB CX,AX;C=B++-++A
    
    MOV B,BX;STORE TEMP 
    MOV A,AX
    MOV C,CX
    
    MOV BX,AX
    SUB BX,B
    SUB BX,CX;B=A-B-C
    
    MOV B,BX; B=BX   
    
    
    ADD A,'0'
    ADD B,'0'
    ADD C,'0'
    
    MOV AH,2
    MOV DX,A
    INT 21H
    MOV DX,B
    INT 21H
    MOV DX,C
    INT 21H
    
    MAIN ENDP
END MAIN
    
        
    