.model small
.data
.code
start:
mov dl,48
mov cl,10

a:
mov ah,02h
int 21h
inc dl
loop a

end start