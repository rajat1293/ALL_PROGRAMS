.model small
.data               
a db "enter number$"
b db "odd$"
c db "even$"  
.code
start: 
mov ax,@data
mov ds,ax 
mov dx,offset a
mov ah,09h
int 21h    
mov ah,01h
int 21h
rcr al,1
jc l
mov dx,offset c 
mov ah,09h
int 21h
jmp s
l:
mov dx,offset b
mov ah,09h
int 21h
s:
end start

    
            
