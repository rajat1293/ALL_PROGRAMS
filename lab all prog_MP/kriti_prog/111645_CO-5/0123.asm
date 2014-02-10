.model small 
.data       
start:
mov cl,10
mov dl,48   

a:mov ah,02h
int 21h  
inc dl
loop a
end start
