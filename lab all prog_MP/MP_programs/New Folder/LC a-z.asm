.model small
.code
start:
mov cl,26d
mov bl,61h
print:mov dl,bl
mov ah,02h
int 21h
inc bl
mov dl,' '
mov ah,02h
int 21h
loop print
end start