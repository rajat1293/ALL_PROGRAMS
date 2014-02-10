.model small
.data
a db "cahc$" 
b db "true$"
c db "false$"
.code
start:
mov ax,@data
mov ds,ax
mov si,offset a 
mov di,offset a
l:  
inc si
cmp [si],'$'
jnz l
m:
dec si 
cmp [di],'$'
jz o 
mov ah,[di] 
inc di
cmp [si],ah
jnz n
cmp [si],ah
jz m
o:
mov dx,offset b
mov ah,09h
int 21h
jmp end
n:
mov dx,offset c
mov ah,09h
int 21h
jmp end
end:
end start