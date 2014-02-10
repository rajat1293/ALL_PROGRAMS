.model small
.data
a db "$"
f db "    reverse of this string is     $"
.code
start:
mov ax,@data
mov ds,ax
mov dx,offset a
       call h
mov si,offset a
mov di,si

b:
mov dl,[si]
cmp dl,"$"
jz e
inc si
jmp b

e:
mov dx,offset f
call h
c:
cmp si,di
jz d
dec si
mov dl,[si]
mov ah,02h
int 21h


jmp c
   h:
   mov ah,09h
int 21h 
ret
d:
end start