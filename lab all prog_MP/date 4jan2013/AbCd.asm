.model small
.code
start:
mov cl,13
mov bl,41h
mov bh,62h
l:
mov dl,bl
mov ah,02h
int 21h
inc dl
inc dl 
mov bl,dl
mov dl,0Dh
mov ah,02h
int 21h
mov dl,0Ah
mov ah,02h
int 21h
mov dl,bh
mov ah,02h
int 21h
inc dl
inc dl
mov bh,dl
mov dl,0Dh
mov ah,02h
int 21h
mov dl,0Ah
mov ah,02h
int 21h
loop l
end start