.model small
.data
a db "i am the whole one$"
.code
start:
mov ax,@data
mov ds,ax

mov dx,offset a
mov ah,09h
int 21h

end start