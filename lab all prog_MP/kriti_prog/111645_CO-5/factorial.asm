.MODEL SMALL
.data
a db  "ENTER THE NUMBER:$"
b db  "FACTORIAL OF NUMBER IS: $"
v1 db 00h
v2 db 00h
v3 db 00h
v4 db 00h
.code
START:
       mov ax,@data
       mov ds,ax
       mov dx,offset a
       mov ah,09h
       int 21h 
       mov ah,01h
       int 21h  
       sub al,30h  
       mov bl,al
       mov cl,al
     
       sub cl,02
       mov ah,00h
       aaa
    c: 
    
       dec bl
       mul bl
       mov v2,ah 
       mov ah,00h
       aaa
       mov v3,al
       mov al,v2
       mul bl
       add al,ah
       aaa
       mov bl,v1
       mov v4,bl
       mov v1,ah
       mov ah,al
       mov al,v4
       mul bl
       add v1,al
       mov al,v3 
   
       loop c
      
      mov v2,ah
      mov v3, al
      MOV DX,offset b
      MOV AH,09h
      INT 21H  
      
        
      mov dl,v1
      add dl,48
      mov ah,02h
      int 21h  
      mov dl,v2
      add dl,48
      mov ah,02h
      int 21h
       mov dl,v3
      add dl,48
      mov ah,02h
      int 21h 
      
      end start



