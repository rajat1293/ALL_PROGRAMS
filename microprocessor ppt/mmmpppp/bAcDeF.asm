.model small
.data
.code
start:
mov dl,98
mov cl,13

a:
call b
call c
loop a

jmp end

b:
mov ah,02h
int 21h
sub dl,33
ret

c:
mov ah,02h
int 21h
add dl,35
ret

end:
end start