.MODEL SMALL
.STACK 100H
                              
.DATA 
.CODE 
MAIN PROC
    MOV AX,10H
    MOV BX,12H
    MOV CX,23H
    MOV DX,35H    
    
    XCHG CX,DX
    ADD CX,DX
    
    XCHG AX,BX
    ADD AX,BX
    
    
    
    
    MAIN ENDP
END MAIN
    