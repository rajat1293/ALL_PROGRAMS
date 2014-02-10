.model small      
.data
a db "enter the number=$"
b db "number in binary form=$"
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
mov dx,offset b
mov ah,09h
int 21h 

sub bl,30h
mov cl,9
p:
dec cl
cmp cl,0
jz q
rol bl,01
jc d
mov dl,'0'
mov ah,02h
int 21h
jmp p
d:
mov dl,'1'
mov ah,02h
int 21h
jmp p 
q:
end start



 