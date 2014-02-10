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
mov ah,00h
mov ah,bh
aad
rol al,01
jc n
jmp p

n:
mov dl,10
call printch
mov dl,13
call printch
mov dx,offset c
call print
jmp end

p:
mov dl,10
call printch
mov dl,13
call printch
mov dx,offset b
call print
jmp end

read:
mov ah,01
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