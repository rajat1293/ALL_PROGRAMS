.model small 
.data       
start:
mov cl,13
mov dl,98
a:mov ah,02h
int 21h
sub dl,33
mov ah,02h
int 21h
add dl,34
inc dl    
loop a
end start
