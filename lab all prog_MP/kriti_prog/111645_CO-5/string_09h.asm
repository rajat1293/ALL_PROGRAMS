.model small
.data
a db "nitkurukshetra$"
.code
start:
mov ax,@data
mov ds,ax             
mov dx,offset a
mov ah,09h
int 21h
end start