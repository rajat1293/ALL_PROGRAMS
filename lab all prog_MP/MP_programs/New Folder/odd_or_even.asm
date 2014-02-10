.model small 
.data
a db "enter number$" 
b db "odd$"
c db "even$"
.code
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
mov ax,bx 
sub ax,3030h
AAD 
Rcr ax,01h
jc g
d:  
mov dl,0ah
mov ah,02h
int 21h 
mov ax,@data
mov ds,ax 
mov dx,offset c
mov ah,09h
int 21h         
jmp e
g: 
mov dl,0ah
mov ah,02h
int 21h 
mov ax,@data
mov ds,ax 
mov dx,offset b
mov ah,09h
int 21h 
e:
end start