.model small
.data
a db "nit kurukshetra$"
.code
start:
mov ax,@data
mov ds,ax             
mov si,offset a
b: mov dl,[si]
mov ah,02h
int 21h
inc si
cmp [si],"$"
jnz b
end start