#start=traffic_lights.exe#

name "traffic"
     
      mov ax,ar
      out 4,ax
      mov si,offset gr
    y:  
      
       mov ax,[si]
       out 4,ax
       
       
       mov cx,4ch
       mov dx,4b40h
       mov ah,86h
       int 15h
       
       add si,2
       cmp si,sa
       jb y
       
       mov si,offset gr
       jmp y
     
       
gr  dw  0000_0011_0000_1100b
yr  dw  0000_0110_1001_1010b
rg  dw  0000_1000_0110_0001b

sa = $
 ar  equ 0000_0010_0100_1001b            