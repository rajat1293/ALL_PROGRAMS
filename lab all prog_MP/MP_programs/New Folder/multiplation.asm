.model small
.code
start:
mov ah,01h
int 21h 
sub al,30h 
mov bh,al
mov ah,01h
int 21h
sub al,30h
mov ah,00h
mul bh 
aam
mov bx,ax 
add bx,3030h   
mov dl,bh
mov ah,02h
int 21h  
mov dl,bl
mov ah,02h
int 21h
end start
