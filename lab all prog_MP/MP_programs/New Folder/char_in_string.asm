.model small
.data
a db "nitkkr$"
b db "true$"
c db "false$"
.code
start:
mov ax,@data
mov ds,ax
mov si,offset a
l:
inc si
cmp [si],'k'
jz m
cmp [si],'$'
jz n
loop l
m:
mov dx,offset b
mov ah,09h
int 21h
jmp end
n:
mov dx,offset c
mov ah,09h
int 21h
jmp end
end:
end start

