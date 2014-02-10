.model small
.data
a db "enter the string $"
f db "string is not palindrom     $"
g db "string is palindrom      $"
h db 10 dup<?>
.code
start:
mov ax,@data
mov ds,ax
mov dx,offset a
call print

mov si,offset h
mov di,offset h

r:
call read
cmp al,36
jz de
mov [di],al
inc di
jmp r  
  
de:
dec di
mov dl,10
call printch
mov dl,13
call printch

p:


mov dl,[si]
mov bl,[di]
cmp dl,bl
jnz no
inc si
dec di
cmp si,di
jge yes
jmp p


yes:mov dx,offset g
call print
jmp e

no:
mov dx,offset f
        call print 
        jmp e

print:
mov ah,09h
int 21h 
ret
read:
mov ah,01h
int 21h
ret
printch:
mov ah,02h
int 21h
ret    
e:
end start