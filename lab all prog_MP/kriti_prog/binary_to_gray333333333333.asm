.model small
.data
a db "enter the number=$"
b db "number in binary form=$"
.code
start: 
Xor bx,bx
mov ax,@data
mov ds,ax  
mov dx,offset a
mov ah,09h
int 21h 
mov ah,01h             
int 21h 
mov bl,al
sub  bl,30h
mov cl,01h
l: 
cmp cl,09h
jz s 
inc cl
rcl bl,1
jc p
mov dl,30H
mov ah,02h
int 21h
jmp l
p:
mov dl,31H
mov ah,02h
int 21h
jmp l
s: 
end start
;when we rotate just use sub baby


 