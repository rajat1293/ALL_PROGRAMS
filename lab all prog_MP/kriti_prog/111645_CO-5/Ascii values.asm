.model small 
.data       
start:
mov cl,255
mov dl,0    

a:mov ah,02h
int 21h
mov dh,dl
mov dl,32
int 21h
mov dl,dh  
inc dl
loop a
end start
