include emu8086.inc
mov dl,'0'
mov ah,02h
int 21h 
mov dl,' '
mov ah,02h
int 21h  
mov dl,'1'
mov ah,02h
int 21h  
mov dl,' '
mov ah,02h
int 21h 
mov bx,1 
mov cx,1    
l:
mov ax,cx
call print_num    
mov dx,cx
add cx,bx
mov bx,dx
mov dl,' '
mov ah,02h
int 21h    
cmp cx,21
jne l  
DEFINE_SCAN_NUM
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS
end
