.model small
.data
a db "enter the number $"
b db "binary form is $"
.code

start:
mov ax,@data
mov ds,ax

mov cl,08
mov dx,offset a
call print
call read
mov bh,al
sub bh,30h

mov dl,10
call printch
mov dl,13
call printch
mov dx,offset b
call print

c:
mov al,bh

rol al,01
mov bh,al
jc one

mov dl,48
call printch


d:
loop c

jmp end

one:
mov dl,49
call printch
jmp d

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