.model small
.data
a db "enter first number$"
b db "enter second number$"
c db "sum of two numbers is$"

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

mov dl,10
call printch
mov dl,13
call printch
mov dx,offset b
call print
mov dl,32
call printch
call read

add al,bl
mov ah,00h
aaa
mov bx,ax
add bx,3030h



mov dl,10
call printch
mov dl,13
call printch
mov dx,offset c
call print
mov dl,32
call printch
mov dl,bh
call printch
mov dl,bl
call printch

jmp end

print:
mov ah,09h
int 21h
ret

read:
mov ah,01h
int 21h
ret

printch:
mov ah,02h
int 21h
ret

end:
end start

