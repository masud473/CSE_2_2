.MODEL SMALL
.STACK 100H
.DATA
 ARR DW 100DUP(0)   
 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX    
    MOV SI,0
    MOV CX,0
    MOV BX,0
INPUT:    
    MOV AH,1
    INT 21H
    CMP AL,0DH     
    JE  NEXT    
    CALL COUNT
    INC CX
    MOV AH,0
    PUSH AX  
    JMP INPUT
NEXT:
    POP AX    
    MOV ARR[SI],AX
    ADD SI,2
    LOOP NEXT          
    MOV AH,2
    MOV DX,0DH
    INT 21H
    MOV DX,0AH
    INT 21H      
    MOV CX,0
PRINT:              
     SUB SI,2
     MOV DX,ARR[SI]      
     CMP ARR[SI],' '
     JE PRINT_STACK
     JE PRINT
     PUSH DX         
     INC CX  
     CMP SI,0
     JG PRINT
     JL END
PRINT_STACK:  
    POP DX
    MOV AH,2
    INT 21H
    LOOP PRINT_STACK    
    MOV DX,' '
    INT 21H
    JMP PRINT
    

END:           
    MOV AH,2   
    MOV DX,0DH
    INT 21H
    MOV DX,0AH
    INT 21H
    MOV DX,BX   
    ADD DX,'0'
    INT 21H
    MOV AH,4CH
    INT 21H
    MAIN ENDP 


COUNT PROC
    CMP AL,'a'
    JE YES
    CMP AL,'e'
    JE YES
    CMP AL ,'i'
    JE YES
    CMP AL,'o'
    JE YES
    CMP AL ,'u'
    JE YES    
NO:
    RET
YES:
    INC BX  
    RET     
    COUNT ENDP
END MAIN
      
    