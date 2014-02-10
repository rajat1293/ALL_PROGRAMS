.model small 
.data
a db "no. is +ve$"
b db "no. is -ve$"
.code
start: 
mov ax,@data
mov ds,ax
mov ah,01h
int 21h
sub al,'0'
rol al,01h
jnc c
d: 
mov dx,offset b
mov ah,09h 
int 21h
jmp e
c: 
mov dx,offset a
mov ah,09h 
int 21h
e:
end start

