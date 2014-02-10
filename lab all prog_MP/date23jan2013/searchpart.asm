.model small
.data   
a db "nitkkr$"
b db "iii$"
c db "yes$"
.code
start:
mov ax,@data
mov ds,ax
mov si,offset a 
mov di,offset b
mov dh,di  
s:   
mov bh,[di] 
cmp [si],bh
jz k 
h:
mov di,dh
jmp s
k:
inc si
inc di
mov bh,[di]
cmp [di],'$'
jz l
cmp [si],'$'
jz m 
cmp [si],bh 
jnz h
loop k
l: 
mov si,offset c
mov dx,si
mov ah,09h
int 21h
m :
end start             