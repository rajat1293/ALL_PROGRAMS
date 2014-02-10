.model small
.data
.code
start:
mov dl,96
mov cl,26

a:
call b
call c
call c
loop a
 
 jmp end
 
b:
sub dl,31
mov ah,02h
int 21h
add dl,32
ret

c:
mov ah,02h
int 21h
ret

end:
end start

