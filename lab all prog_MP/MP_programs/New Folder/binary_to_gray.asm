;include emu8086.inc 
.model small
.code
start: 
mov cl,07
mov ah,01h
int 21h  
mov bh,al         
mov ah,01h
int 21h
mov bl,al
mov ax,bx 
sub ax,3030h
AAD 
mov bx,ax
 mov dl,13
 mov ah,02h         
 int 21h
 mov dl,10
 mov ah,02h
 int 21h    
rol bl,01
jc a
mov dl,30h
mov ah,02h
int 21h 
mov bh,dl
jmp l
a:
mov dl,31h
mov ah,02h
int 21h
mov bh,dl
l:
rol bl,01
jc d
mov dh,30h 
jmp e
d:
mov dh,31h
e:  
xor bh,dh 
mov dl,bh
add dl,30h
mov ah,02h
int 21h 
mov bh,dh
loop l
end start
          
     

