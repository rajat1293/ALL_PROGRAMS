.model small
.code
start:
mov cx,256d
mov bl,00h
print:mov dl,bl
mov ah,02h
int 21h
inc bl
mov dl,' '
mov ah,02h
int 21h
loop print
end start