include emu8086.inc 
.model small
.data               
a db "enter number$" 
.code
start: 
mov ax,@data
mov ds,ax 
mov dx,offset a
mov ah,09h
int 21h  

 mov dl,13
 mov ah,02h
 int 21h
 mov dl,10
 mov ah,02h
 int 21h 
 
CALL scan_num

 mov dl,13
 mov ah,02h
 int 21h
 mov dl,10
 mov ah,02h
 int 21h 
  
mov ax,cx 
mov cl,00
t: 
cmp cl,8
jz e  
inc cl
rcl al,01h 
jnc p
PRINT '1'
jmp t 
p:
PRINT '0'  
jmp t

e:
DEFINE_SCAN_NUM
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS 
DEFINE_PRINT_STRING  

END 
   
