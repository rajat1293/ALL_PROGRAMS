.model small
.data
a db "nitkkr$"
.code
start:
mov Ax,@data
mov ds,ax
mov si,offset a
l:  
cmp [si],'$'
Jz k
mov dl,[si]
mov ah,02h
int 21h
inc si
jmp l
k:
end start