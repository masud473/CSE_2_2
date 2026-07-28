.MODEL SMALL
.STACK 100H
.DATA 
A DB ?
B DB ?
C DB ?
E DB 'ERROR!$'

.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,1                      
    
    INT 21H
    MOV CL,AL
    
    INT 21H
    MOV BL,AL      
    
    INT 21H
    
    CMP AL,'A'
    JL ERROR 
    CMP AL,'Z'
    JG ERROR    
    
    CMP BL,'A'
    JL ERROR 
    CMP BL,'Z'
    JG ERROR           
    
    CMP CL,'A'
    JL ERROR 
    CMP CL,'Z'
    JG ERROR                
    
COMPARE_AB:  
    CMP AL,BL
    JL COMPARE_BC
    XCHG AL,BL;BL IS NOW BIGGER
    
COMPARE_BC:      
    CMP BL,CL
    JL COMPARE_AB_2
    XCHG CL,BL;CL IS NOW BIGGER        
    
COMPARE_AB_2:
    CMP AL,BL
    JL PRINT
    XCHG AL,BL;BL IS NOW BIGGER
    
PRINT:
    MOV A,AL
    MOV AH,2
    ADD A,32
    MOV DL,A
    INT 21H 
    ADD BL,32
    MOV DL,BL
    INT 21H  
    ADD CL,32
    MOV DL,CL
    INT 21H
    JMP ENDING    
ERROR:
    MOV AH,9
    LEA DX, E
    INT 21H 
    
 
ENDING:
       MAIN ENDP
END MAIN
    