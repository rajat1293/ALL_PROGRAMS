.model small
.data
a db "enter 1st number$"
b db "enter second number$"
c db "result$"    
.code
start:
mov ax,@data
mov ds,ax 
mov dx,offset a
mov ah,09h
int 21h 
mov ah,01h 
int 21h  
;sub al,30h
mov bl,al 
mov dx,offset b
mov ah,09h
int 21h
mov ah,01h
int 21h
;sub al,30h  
add al,bl 
mov ah,00h
AAA  
mov bx,ax
mov dx,offset c
mov ah,09h
int 21h
add bx,3030h
mov dl,bh
mov ah,02h
int 21h
mov dl,bl
mov ah,02h
int 21h
end start
          

