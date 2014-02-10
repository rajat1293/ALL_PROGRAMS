.model small
.data
a db "enter first no= $"
b db "enter second no=$"
c db "sum of no=$"
v1 db 00h
start:
mov ax,@data 
mov ds,ax
mov dx,offset a
mov ah,09h
int 21h 
mov ah,01h
int 21h
mov bh,al  
mov ah,01h
int 21h
mov bl,al
mov dx,offset b
mov ah,09h
int 21h
mov ah,01h
int 21h
mov ch,al
mov ah,01h
int 21h  
add al,bl    
mov ah,00h
AAA
add bh,ah       
add bh,ch
mov v1,al
mov al,bh
mov ah,00h
AAA
mov bx,ax 
add bx,3030h
mov dl,bh
mov ah,02h
int 21h  
mov dl,bl
mov ah,02h
int 21h
mov dl,v1
add dl,30h
mov ah,02h
int 21h   
end start


