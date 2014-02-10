.model small
.data
.code
start:
mov dl,65
mov cl,26

a:
mov ah,02h 
int 21h
inc dl
loop a


end start