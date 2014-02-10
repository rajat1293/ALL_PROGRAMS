.model small
.data
a db "nitkkr$"
.code
start:
mov AX , @data   
mov DS,AX
mov DX,offset a
mov ah,09h;display whole string using 09h
int 21h
end start