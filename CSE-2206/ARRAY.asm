.MODEL SMALL
.STACK 100H
.DATA
ARR DW 1,2,3,4,5   
N DW 5
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    CALL SUM  
    CALL REV
    MOV AH,4CH
    INT 21H
    MAIN ENDP   

SUM PROC
    MOV AX,0   
    LEA SI,ARR
    MOV CX,5
SUM_LOOP:
    ADD AX,[SI]
    ADD SI,2
    LOOP SUM_LOOP     
    RET
    SUM ENDP

REV PROC
    LEA SI,ARR
    LEA DI,ARR
    SHL N,1
    ADD DI,N    
    SUB DI,2    
    SHR N,1
REV_LOOP:
    CMP SI,DI
    JGE REV_END
    MOV AX,[SI]
    XCHG AX,[DI]
    MOV [SI],AX
    ADD SI,2
    SUB DI,2
    JMP REV_LOOP
REV_END:
    RET
    REV ENDP

END MAIN