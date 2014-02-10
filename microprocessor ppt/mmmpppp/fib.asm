.model small
.data
a db "fibonacci series is $"
b db "enter number of terms $"
.code
start:
mov ax,@data
mov ds,ax

mov dx,offset b
call print
call read
mov bh,al
call read
mov bl,al
mov ax,bx
sub ax,3030h
aad

mov cl,al
mov dx,offset a
call print
mov dl,48
call printch
mov dl,48
call printch
mov dl,32
call printch
mov dl,48
call printch
mov dl,49
call printch
mov bl,48
mov bh,49
         
sub cl,2       
cmp cl,0
jle end        
c: 
mov dl,32
call printch
mov al,bl
mov ah,00h
aaa
mov ch,ah
mov dh,al
mov al,bh
mov ah,00h
aaa
mov bl,ah 
mov dl,al
add dh,dl
mov al,dh
mov ah,00h
aaa
mov dh,al
add ch,bl
add ch,ah
mov al,dh
mov ah,ch
aad
mov bl,al

mov dl,ch
add dl,30h
call printch
mov dl,dh
add dl,30h
call printch
xchg bl,bh
mov ch,00h
mov dh,00h
loop c
jmp end

read:
mov ah,01h
int 21h
ret

print:
mov ah,09h
int 21h
ret

printch:
mov ah,02h
int 21h
ret

end:
end start