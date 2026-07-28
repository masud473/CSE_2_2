.MODEL SMALL
.STACK 100H
                              
.DATA 
.CODE 
MAIN PROC
    MOV AX,5H
    MOV BX,12H
    MOV CX,20H
    MOV DX,31H    
    
    XCHG AX,DX; AX=31H,DX=5H
    XCHG AX,BX;BX=31H,AX=12H
    
    DEC DX
    SUB BX,AX
    ADD CX,AX
    INC AX
    
    
    MAIN ENDP
END MAIN
    