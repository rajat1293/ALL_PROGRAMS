include emu8086.inc 
.model small
.data               
a db "enter 1st number$"
b db "enter second number$"
c db "result$"  
.code 
mov ax,@data
mov ds,ax 
mov dx,offset a
mov ah,09h
int 21h  
CALL scan_num 
mov bx,cx
CALL scan_num
add bx,cx
mov ax,bx
CALL print_num
RET

DEFINE_SCAN_NUM
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS 

END 
   

