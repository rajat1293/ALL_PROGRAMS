.model small     
.data
a db "error mouse driver are not dectected$"
b db "mouse driver is dectected$"
.code
start: 
mov ax,@data
mov ds,ax
mov ax,00h
int 33h
cmp ax,00h
jne ender 
  mov dx,offset a
 mov ah,09h
 int 21h
ender:
 mov dx,offset b
 mov ah,09h
 int 21h
z: 
end start
