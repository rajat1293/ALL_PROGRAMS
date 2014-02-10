.model small
.code
start:
mov cl,13d
mov bh,41h
mov bl,62h
print:mov dl,bh
mov ah,02h
int 21h
inc bh
inc bh   
mov dl,' '
mov ah,02h
int 21h
mov dl,bl
mov ah,02h
int 21h
inc bl
inc bl
mov dl,' '
mov ah,02h
int 21h
loop print
end start