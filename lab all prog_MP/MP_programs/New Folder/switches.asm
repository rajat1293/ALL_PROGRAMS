.model small
.code
start:
mov cl,00  
xor ax,ax
mov al,00010000b
inc cl
y:
rcr al,01h
jc x
inc cl
jmp y
x:
mov dl,cl 
add dl,30h 
mov ah,02h
int 21h
end start