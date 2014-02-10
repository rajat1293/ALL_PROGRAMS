.model small

.data
.code
start:
mov dl,0
mov cx,256

a:
mov ah,02h
int 21h
inc dl
loop a  

end start