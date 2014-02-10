.model small
.code
start:
mov cl,26d
mov bh,41h
print:mov dl,bh
mov ah,02h
int 21h
inc bh
mov dl,' '
mov ah,02h
int 21h
loop print
end start