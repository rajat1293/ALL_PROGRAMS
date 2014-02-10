.model small
.data
.code
start:
mov dl,97
mov cl,26

a:
call b
call c
loop a

jmp end
b:
mov ah,02h
int 21h
sub dl,32 
ret

c:
mov ah,02h
int 21h
add dl,33
ret

end:
end start