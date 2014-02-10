.model small
.data
a db "enter the number$"
b db "number is positive$"
c db "number is negative$"

.code
start:
mov ax,@data
mov ds,ax

mov dx,offset a
call print
mov dl,32
call printch
call read
mov bh,al
call read
mov bl,al
call read

cmp bh,045
jz n
jmp p

p:
mov dl,10
call printch
mov dl,13
call printch
mov dx,offset b
call print
jmp end

n:
mov dl,10
call printch
mov dl,13
call printch
mov dx,offset c
call print
jmp end
   
printch:
mov ah,02h
int 21h
ret
print:
mov ah,09h
int 21h
ret
read:
mov ah,01h
int 21h
ret
end:
end start