.model small
.data
a db "enter the number $"
b db "factorial of number is $"

.code
start:
mov ax,@data
mov ds,ax

mov dx,offset a
call print
call read
sub al,30h
mov ah,00h
cmp al,01
jle d
mov bh,al
mov cl,al

 dec cl
c:

mov al,cl
mov ah,00h
mul bh

aam
cmp cl,1
jz d
aad
mov bh,al 
loop c
d:
mov bx,ax

mov al,bh
mov ah,00h
aaa
mov bh,al
mov ch,ah

mov dx,offset b
call print

mov dl,ch
add dl,30h
call printch
mov dl,bh
add dl,30h
call printch
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