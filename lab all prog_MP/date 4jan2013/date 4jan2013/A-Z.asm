 .model small
.code
start:
mov cl,26
mov bl,41h
l: 
mov dl,bl
mov ah,02h
int 21h
inc dl
mov bl,dl
mov dl,0Dh
mov ah,02h
int 21h
mov dl,0Ah
mov ah,02h
int 21h
loop l
end start
