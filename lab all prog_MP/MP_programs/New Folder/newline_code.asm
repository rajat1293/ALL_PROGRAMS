 .model small
 .code
 start:
 mov cl,2
 mov bl,'a'
 l:
 mov dl,bl
 mov ah,02h
 int 21h 
 mov dl,13
 mov ah,02h
 int 21h
 mov dl,10
 mov ah,02h
 int 21h 
 inc bl
 loop l
 end start