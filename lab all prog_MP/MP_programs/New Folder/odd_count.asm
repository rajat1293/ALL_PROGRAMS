.model small 
.code
start: 
mov bh,30h 
mov bl,30h
a:
mov ah,01h
int 21h  
inc bl
cmp al,' '
jz e
sar al,01h
jnc a
odd: 
inc bh
jmp a

e: 
mov dl,bh 
mov ah,02h
int 21h 
sub bl,bh  
mov dl,bl 
sub dl,
mov ah,02h
int 21h

end start

