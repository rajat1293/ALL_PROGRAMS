.model small
.data
a db "enter the number of elements$"
b db "enter the elements$"
c db "sorted elements are$"
arr db 10 dup(?)

.code
start:

mov ax,@data
mov ds,ax
mov dx,offset a
call print
mov dl,32
call printch
call read  
sub al,30h
mov cl,al
mov bl,cl

mov si,offset arr
mov di,si

mov dl,10
call printch
mov dl,13
call printch
mov dx,offset b
call print
mov dl,32
call printch

e:
call read 

mov [si],al
inc si
mov dl,32
call printch
loop e

dec si
mov bp,di
mov cl,bl


f:
dec cl
cmp cl,0
jz i
mov di,bp 
h:
cmp di,si
jz f 
mov bh,[di]
cmp bh,[di+1]
jg g
inc di
jmp h

g:
xchg bh,[di+1] 
mov [di],bh
inc di
jmp h

jmp f

i:
mov cl,bl

mov dl,10
call printch
mov dl,13
call printch
mov dx,offset c
call print
mov dl,32
call printch


res:
mov dl,[bp]
call printch
inc bp
mov dl,32
call printch
loop res
     
jmp end

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

end:
end start