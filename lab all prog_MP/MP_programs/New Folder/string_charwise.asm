.model small
.data
a db "nitkkr$"
.code
start:
mov ax,@data
mov ds,ax
mov si,offset a
l:
mov dl,[si]
mov ah,02h
int 21h
inc si
cmp [si],'$'
jnz l
mov ah,09h
int 21h
end start