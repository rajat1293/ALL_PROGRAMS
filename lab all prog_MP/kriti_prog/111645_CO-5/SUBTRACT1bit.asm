.model small
.data
a db "enter first no= $"
b db "enter second no=$"
c db "SUB of no=$"
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
sub bh,al
mov al,bh
mov ah,00h
AAS
MOV BX,AX
mov dx,offset c
mov ah,09h
int 21h 
mov dl,bh
add dl,30h 
mov ah,02h
int 21h   
mov dl,bl 
add dl,30h
mov ah,02h
int 21h
end start


