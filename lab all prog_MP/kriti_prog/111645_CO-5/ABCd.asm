.model small 
.data
start
mov cl,26
mov dl,65
a:mov ah,02h
int 21h
inc dl
loop a
end start
