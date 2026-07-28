.MODEL SMALL
.STACK 100H                                                  
.DATA
E DB 10,13,'EVEN',10,13,'$'
O DB 10,13,'ODD',10,13,'$'    
D DB 10,13,'DECIMAL:','$'  
ERR DB 10,13,'WRONG INPUT SELECT Y/N',10,13,'$'     
ASK DB 10,13,'INPUT_HEX: ','$'    
ASK_AGAIN DB 10,13,'RECHECK: ','$'
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
INPUT:                  
    MOV AH,9
    LEA DX, ASK
    INT 21H
    
    MOV AH,1
    INT 21H       
    
    MOV BL, AL
    MOV AH,9
    LEA DX,D
    INT 21H   
    MOV AL,BL
    
    CMP BL,'A'
    JL  PRINT
    SUB BL,'A'  
    ADD BL,'0'        
    
    MOV AH,2
    MOV DL,'1'
    INT 21H
    
 PRINT:
    MOV AH,2
    MOV DL,BL
    INT 21H
    
CHECK_1:  
    AND BL,1
    CMP BL,1
    JNE EVEN
    MOV AH,9 
    LEA DX,O
    INT 21H
    JMP CHECK_2
EVEN:              
    MOV AH,9
    LEA DX,E
    INT 21H
CHECK_2:         
    MOV AH,9
    LEA DX, ASK_AGAIN
    INT 21H
    MOV AH,1
    INT 21H

    CMP AL,'Y'
    JE INPUT   
    CMP AL,'y'
    JE INPUT
    
    CMP AL,'N'
    JE END     
    CMP AL,'n'
    JE END
                    
    MOV AH,9
    LEA DX, ERR                
    INT 21H
    JMP CHECK_2
    
END:
    MOV AH,4CH  
    INT 21H
MAIN ENDP
END MAIN 

    