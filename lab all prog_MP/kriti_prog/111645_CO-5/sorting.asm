.model small
.data
a db "ENTER THE NUMBER IN THE ARRAY$"    
c db "SORTED ARRAY IS--$"
m db "ENTER TOTAL NUMBER IN ARRAY$"
b db 50 dup(?)
start:
      MOV AX,@DATA
      MOV DS,AX
      
      MOV DX,OFFSET m
      MOV AH,09H
      INT 21H
      
      MOV AH,01H
      INT 21H
      SUB AL,48
      MOV CL,AL
      MOV BH,AL
      
      MOV DL,32
      MOV AH,02H
      INT 21H
 
      
      MOV DX,OFFSET a
      MOV AH,09H
      INT 21H
    
      MOV SI,OFFSET b
      MOV DI,OFFSET b
      MOV BP,OFFSET b
    Y:MOV AH,01H
      INT 21H
      MOV [SI],AL
      INC SI
     
      LOOP Y
      
      MOV CL,BH
      INC CL
 
     
   L:MOV BL,[DI]
      CMP BL,[DI+1]
      JGE T
   F:INC DI
      CMP DI,SI
      JL L
      DEC SI
      CMP SI,BP
      JZ P      
      MOV DI,BP
      JMP L
   T:
      MOV BH,[DI+1]
      MOV [DI],BH
      MOV [DI+1],BL
      JMP F
      
   P:
       MOV DL,0AH
       MOV AH,02H
       INT 21H
       MOV DX,OFFSET c
       MOV AH,09H
       INT 21H
    
      
     
   Q:       
      MOV DL,[BP]
      MOV AH,02H
      INT 21H
      INC BP
      
      LOOP Q
    E:
      end start   
         
         
       
      
         
       