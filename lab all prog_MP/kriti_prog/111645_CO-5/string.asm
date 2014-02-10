.model small
.data
a db "nit kurukshetra$"
.code
start:
mov ax,@data
mov ds,ax             
mov si,offset a
b: mov bl,[si]              
cmp bl,"$"
jz z 
mov dl,bl
mov ah,02h
int 21h
inc si
jmp b
z:
end start