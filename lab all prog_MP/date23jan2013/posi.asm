.model small
.data               
a db "enter number$"
b db "positive$"
c db "negative$"  
.code
start: 
mov ax,@data
mov ds,ax 
mov dx,offset a
mov ah,09h
int 21h 
mov ah,01h
int 21h 
mov bl,'-'
cmp al,bl
jz k
mov dx,offset b 
mov ah,09h
int 21h
jmp s:
k:
mov ah,01h
int 21h
mov dx,offset c 
mov ah,09h
int 21h
s:
end start

