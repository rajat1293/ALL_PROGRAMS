include emu8086.inc
 
CALL   scan_num      
MOV    bX, CX        
mov ax,1 
l:  
mul bx
dec bx
cmp bx,01
jnz l
CALL   print_num     
RET                 
DEFINE_SCAN_NUM
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS 

END 