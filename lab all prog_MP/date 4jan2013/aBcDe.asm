.model small
.code
start:
mov cl,13
mov bl,42h;66
mov bh,61h;97
l: 
mov dl,bh
mov ah,02h
int 21h
;inc dl
;inc dl
;mov bh,dl
add bh,2
mov dl,0Dh
mov ah,02h
int 21h 
mov dl,0Ah
mov ah,02h
int 21h 
mov dl,bl
mov ah,02h
int 21h
inc dl
inc dl 
mov bl,dl
mov dl,0Dh
mov ah,02h
int 21h
mov dl,0Ah
mov ah,02h
int 21h
loop l
end start