0ol9.model small
.data
a db "nitkkr$"
.code
start:
mov ax,@data
mov ds,ax
mov si,offset a
l:  
inc si
cmp [si],'$'
jnz l
m:
dec si
mov dl,[si]
mov ah,02h
int 21h

cmp si,offset a
jnz m
end start