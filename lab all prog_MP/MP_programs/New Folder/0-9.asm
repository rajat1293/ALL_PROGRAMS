.model small
.code
start:
mov cx,10d
mov bl,30h
print:mov dl,bl
mov ah,02h
int 21h
inc bl
mov dl,' '
mov ah,02h
int 21h
loop print
end start