.model small
.data
a db "enter first number$"
b db "enter second number$"
c db "quotient is $"
d db "remainder is $"

.code
start:
mov ax,@data
mov ds,ax

mov dx,offset a
call print
mov dl,32
call printch
call read
mov bl,al
sub bl,30h

mov dl,10
call printch
mov dl,13
call printch
mov dx,offset b
call print
mov dl,32
call printch
call read
sub al,30h
mov ah,00h
div bl
mov bh,ah
add bh,30h
mov bl,al 
add bl,30h

mov dl,10
call printch
mov dl,13
call printch
mov dx,offset c
call print
mov dl,32
call printch
mov dl,bl
call printch

mov dl,10
call printch
mov dl,13
call printch
mov dx,offset d
call print
mov dl,32
call printch
mov dl,bh 
call printch
jmp end

print:
mov ah,09h
int 21h
ret

printch:
mov ah,02h
int 21h
ret

read:
mov ah,01h
int 21h
ret

end:
end start