.model small
.data
a db "enter first number $"
b db "enter second number $"
c db "result is $"

.code
start:
mov ax,@data
mov ds,ax

mov dx,offset a
call print
call read
mov bl,al

mov dx,offset b
call print
call read

xchg bl,al

sub al,bl
mov ah,00h
aas
mov bl,al

mov dx,offset c
call print
mov dl,bl

add dl,30h
call printch
jmp end

read:
mov ah,01h
int 21h
ret

print:
mov ah,09h
int 21h
ret

printch:
mov ah,02h
int 21h
ret

end:

end start
