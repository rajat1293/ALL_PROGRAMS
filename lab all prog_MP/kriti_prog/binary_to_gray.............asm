.model small
.data 
a db "entr a number$"
.code
start:
mov dx,@data
mov ds,dx
mov dx,offset a
mov ah,09h
int 21h
mov ah,01h
int 21h   
sub al,30h
mov bl,al           
clc
rcr al,1
xor al,bl
;add al,30h
mov cl,01h
mov bl,al   
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
end start
             