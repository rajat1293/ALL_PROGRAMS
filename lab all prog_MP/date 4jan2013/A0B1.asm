.model small
.code
start: 
mov cx,260
mov bl,65    
mov bh,48
l:
mov dl,bl
mov ah,02h
int 21h
inc dl
mov bl,dl
mov dl,bh
mov ah,02h
int 21h 
cmp bl,91
jz m
s: 
mov dl,0Dh
mov ah,02h
int 21h
mov dl,0Ah
mov ah,02h
int 21h
loop l 
jmp x
m:inc bh
mov bl,65
jmp s
x:
end start