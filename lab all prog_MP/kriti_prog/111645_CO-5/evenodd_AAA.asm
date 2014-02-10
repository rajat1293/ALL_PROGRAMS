.model small
.data      
a db "enter the number=$"
b db "number is even$"   
c db "number is odd$"
start:
mov ax,@data
mov ds,ax
mov ah,09h
int 21h
mov ah,01h
int 21h
mov bh,al
mov ah,01h
int 21h  
mov bl,al
mov ax,bx
AAA
ROR al,01

jc P:
mov dx,offset b
mov ah,09h
int 21h
jmp E:
P: mov dx,offset c
mov ah,09h
int 21h
E:
end start 
