.model small
.data
a db "enter number of term > 2 : $"
b db "fibonacci series is : $" 
val1 db 01h
val2 db 01h
v1 db 00h
v2 db 00h
.code
start:
        mov ax,@data
        mov ds,ax
        mov dx,offset a
        mov ah,09h
        int 21h
        mov ah,01h
        int 21h
        mov bl,al
        sub bl,30h
        mov ah,01h
        int 21h
        sub al,30h
        mov ah,bl
        aad
        mov cl,al
        sub cl,02h
          
        mov dl,0ah ;for space
        mov ah,02h
        int 21h
       
        mov dx,offset b
        mov ah,09h
        int 21h 
       
        mov dl,v1
        add dl,48
        mov ah,02h
        int 21h
        mov dl,val1
        add dl,48
        mov ah,02h
        int 21h
       
        mov dl,32
        mov ah,02h
        int 21h
       
        mov dl,v2
        add dl,48
        mov ah,02h
        int 21h
        mov dl,val2
        add dl,48
        mov ah,02h
        int 21h
       
        mov dl,32
        mov ah,02h
        int 21h
        z:
      
         mov al,val1
         add al,val2 
         mov ah,00h
         aaa
         add ah,v1
         add ah,v2
       
       
         mov bl,val2
         mov val1,bl
         mov bl,v2
         mov v1,bl  
        
    
         mov v2,ah
         mov val2,al
         
         mov dl,v2
         add dl,48
         mov ah,02h
         int 21h
         
         mov dl,val2
         add dl,48
         mov ah,02h
         int 21h
        
         mov dl,32
         mov ah,02h
         int 21h
         loop z 
      
         end start         




            