.model small
.code
start:
mov ah,01h
int 21h
sub al,30h 
mov bl,al
mov ah,01h
int 21h
sub al,30h
mov ah,00h  
aad
div bl
mov bh,al
add bh,30h
mov dl,bh
mov ah,02h
int 21h
end start

