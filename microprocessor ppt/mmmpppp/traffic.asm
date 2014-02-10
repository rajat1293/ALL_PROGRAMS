

#start=Traffic_Lights.exe#





mov ax,all_red
out 4,ax 

mov si,offset situation

next:
mov ax,[si]
out 4,ax

mov cx,4Ch
mov dx,4B40H
mov ah,86h
int 15h

add si,2
cmp si,sit_end
jb next
mov si,offset situation
jmp next



 
              ;FEDC_BA98_7654_3210

situation dw   0000_0100_1001_0010b
s1        dw   0000_0101_0001_0100b
s2        dw   0000_1000_1010_0010b
s3        dw   0000_0000_0100_0001b
s4        dw   0000_1000_0110_0001b
s5        dw   0000_0100_0101_0001b
s6        dw   0000_0110_0001_1000b

sit_end = $


all_red   equ  0000_0010_0100_1001b
                               