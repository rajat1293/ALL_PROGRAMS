.model small
.data
a db "shattered dreams but still living$"
.code
start:
mov ax,@data
mov ds,ax
mov si,offset a

compare:
cmp [si],"$"
jz end
mov dl,[si]
mov ah,02h 
int 21h
inc si
jmp compare

end:
end start
