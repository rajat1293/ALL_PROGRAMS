.model small
.data
.code
start:
mov dl,65
mov cl,26

a:
call b
call c
loop a
jmp end
b:
mov ah,02h
int 21h
add dl,32
ret

c:
mov ah,02h
int 21h
sub dl,31
ret 
end:
end start