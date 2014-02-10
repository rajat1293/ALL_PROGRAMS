.model small
.data
a db "WELCOME$"
.code
start:
      mov ax,@data
      mov ds,ax      
   
      mov si,offset a
      mov di,offset a
      mov bl,[di]
      
    d:  
       cmp [si],'$'
       je n
       
       inc si
       
       jmp d
       
    n: dec si
       
       cmp bl,[si]
       je e
       mov dl,[si]
       mov ah,02h
       int 21h
      
       jmp n
   e: 
       mov dl,[si]
       mov ah,02h
       int 21h     
       end start   