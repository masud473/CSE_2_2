.MODEL SMALL
.STACK 100H
.DATA
ORIG DB ?
COMP DB ?        
REV DB ?
ODD DB ?
TEMP DB ?

.CODE

MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV BL,0
    MOV AH,1
    MOV CX,8
INPUT:
    INT 21H 
    SUB AL,'0'
    SHL BL,1
    OR BL,AL
    LOOP INPUT
    JMP COMPLEMENT   
COMPLEMENT:
    MOV DL,BL
    MOV ORIG,BL          
    XOR DL, 11111111B 
    MOV COMP,DL    
    
    MOV CX,8              
    MOV AL,0        
REVERSE:                 
    MOV TEMP,1
    AND TEMP,DL
    ROR DL,1  
    SHL AL,1
    OR AL,TEMP
    LOOP REVERSE
    MOV REV,AL 
    MOV CX,4 
    MOV DH,0
PARITY:
    MOV TEMP,1
    AND TEMP, AL
    SHR AL,1   
    XOR DH,TEMP     
    LOOP PARITY    
    XOR DH,1 
    MOV ODD,DH           
  
END:              
   MOV AH,2     
   
   MOV CX,8     
   MOV DL,10
   INT 21H
   MOV DL,13
   INT 21H
   MOV BL,ORIG
LOOP1:
   MOV TEMP,10000000B
   AND TEMP,BL
   ROL BL,1   
   ROL TEMP,1  
   ADD TEMP,'0'
   MOV DL,TEMP
   INT 21H
   LOOP LOOP1
                  
   MOV CX,8     
   MOV DL,10
   INT 21H
   MOV DL,13
   INT 21H
   MOV BL,COMP
LOOP2:
   MOV TEMP,10000000B
   AND TEMP,BL
   ROL BL,1   
   ROL TEMP,1  
   ADD TEMP,'0'
   MOV DL,TEMP
   INT 21H
   LOOP LOOP2
   
   
   MOV CX,8     
   MOV DL,10
   INT 21H
   MOV DL,13
   INT 21H
   MOV BL,REV
LOOP3:
   MOV TEMP,10000000B
   AND TEMP,BL
   ROL BL,1   
   ROL TEMP,1  
   ADD TEMP,'0'
   MOV DL,TEMP
   INT 21H
   LOOP LOOP3  
   
   MOV DL,10
   INT 21H
   MOV DL,13
   INT 21H
   MOV BL,REV  
   
   MOV DL,ODD
   ADD DL,'0'
   INT 21H
   
   MOV AH,4CH
   INT 21H
   MAIN ENDP
END MAIN