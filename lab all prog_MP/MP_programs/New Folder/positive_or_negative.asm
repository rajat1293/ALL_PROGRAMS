include emu8086.inc 
.model small
.data               
a db "enter number$"
b db "positeve$"
c db "negative$"  
.code
start: 
mov ax,@data
mov ds,ax 
mov dx,offset a
mov ah,09h
int 21h  
CALL scan_num
mov dl,0ah
mov ah,02h
int 21h 
mov ax,cx
rcl ax,01h
jc g
d:
PRINT 'positive'
jmp t
g:
PRINT 'negative'
RET
t:
DEFINE_SCAN_NUM
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS 
DEFINE_PRINT_STRING  

END 
   
