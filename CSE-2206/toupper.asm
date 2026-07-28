.MODEL SMALL
.STACK 100H

.DATA   

 A db ?
 B db ?
 C db ?
.CODE

MAIN PROC                    
    MOV AX,@DATA ; LOAD DATA
    MOV DS,AX        
    
    
    MOV AH,1  ; store data to A,B,C    
    
    INT 21H     
    MOV A,AL
             
    INT 21H     
    MOV B,AL  
 
    INT 21H               
    MOV C,AL
               
    SUB A,20H ; CONVERT TO UPPERCASE
    SUB B,20H
    SUB C,20H
    
    MOV AH,2 ; start printing outputs  
    
    MOV DL,10 ; PRINT NEW LINE
    INT 21H
    
    MOV DL, 13; GO BACK TO THE START 
    INT 21H   
   
    MOV DL, A
    INT 21H       
    
    MOV DL, 10
    INT 21H
    
    MOV DL,13
    INT 21H
                    
    MOV DL, B
    INT 21H 
            
    MOV DL,13
    INT 21H
    
    MOV DL, 10
    INT 21H
      
    MOV DL, C
    INT 21H 
      
    

    
    MOV AH,4CH  ; END PROGRAM
    INT 21H
    MAIN ENDP
END MAIN
