.model small
.data
a db "enter 1st number$"
b db "enter second number$"
c db "result$"    
.code
start:
mov ax,@data
mov ds,ax 
mov dx,offset a
mov ah,09h
int 21h 
mov ah,01h 
int 21h   
mov ch,al
mov ah,01h 
int 21h   
mov  cl,al 
mov dx,offset b
mov ah,09h
int 21h
mov ah,01h 
int 21h   
mov bh,al
mov ah,01h 
int 21h
mov ah,bh
add al,cl   
AAA
mov bl,al
mov al,ah
mov ah,00h
mov cl,ch
mov ch,00h
add al,cl
aaa
mov cx,ax  
mov dx,offset c
mov ah,09h
int 21h
add cx,3030h
mov dl,ch
mov ah,02h
int 21h
mov dl,cl
mov ah,02h
int 21h
add bl,30h
mov dl,bl
mov ah,02h
int 21h
end start
          

