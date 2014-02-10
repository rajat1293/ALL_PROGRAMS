.model small
.code
.data  
start:
mov ah,01h
int 21h
mov bl,al ;bl
sub bl,30h
mov cl,01h
cmp cl,bl ;cl                                 
jz a
inc cl
cmp cl,bl
jz b
inc cl       ;bh
mov bh,01h   ;ch
mov ch,01h
m:mov ah,bh
add bh,ch 
cmp bl,cl
jz c         
mov ch,ah 
inc cl
jmp m                                 
a:
mov dl,31h
mov al,02h 
int 21h
jmp l
b:mov dl,31h
mov ah,02h
int 21h
jmp l
c:
mov dl,bh 
add dl,30h
mov ah,02h
int 21h
l:
end start                                