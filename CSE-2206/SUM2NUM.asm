.MODEL SMALL
.STACK 100H
.DATA
.CODE
MAIN PROC

    MOV AH,1
    INT 21H
    
    MOV BL,AL
                    
    MOV AH,2
    MOV DL,'+'
    INT 21H
    MOV AH,1
    INT 21H
    ADD BL,AL
    
    SUB BL,'0'
    
    MOV AH,2      
    
    MOV DL,'='
    INT 21H
    
    MOV DL,BL
    INT 21H

    MOV AH, 4CH
    INT 21H 
MAIN ENDP
END MAIN