.model small
.data
a db "adccda$"
b db "string is palindrom$"
c db "not pallindrom$"
start:
      mov ax,@data
      mov ds,ax
      mov si,offset a
      mov di,offset a
    x:
       cmp [si],'$'
       je y
       inc si
       jmp x
   y: 
     
     cmp di,si
     je p
     dec si
     mov bl,[di]
     
     cmp bl,[si]
     jne t
      inc di
     jmp y
   
   t:
       mov dx,offset c
       mov ah,09h
       int 21h
       jmp e
    p:
       mov dx,offset b
       mov ah,09h
       int 21h
       jmp e
          
   e:
       end start
           