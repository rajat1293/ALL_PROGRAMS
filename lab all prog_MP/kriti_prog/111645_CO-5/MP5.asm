.model small 
.data       
start:
mov cl,0
mov dl,48   

a:mov ah,02h
int 21h  
inc dl    
inc cl
cmp cl,10
jnz a
end start
