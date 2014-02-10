.model small
.data
a db "enter first no= $"
b db "enter second no=$"
c db "sum of no=$"
start:
mov ax,@data 
mov ds,ax
mov dx,offset a
mov ah,09h
int 21h 
mov ah,01h
int 21h 
mov bh,al
mov dx,offset b
mov ah,09h
int 21h
mov ah,01h
int 21h  
add al,bh
mov ah,00h
AAA
mov bx,ax
add bx,3030h
mov dx,offset c
mov ah,09h
int 21h 
mov dl,bh 
mov ah,02h
int 21h   
mov dl,bl
mov ah,02h
int 21h
end start


