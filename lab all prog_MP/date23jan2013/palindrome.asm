.model small
  .data
  a db "123454321$"
  b db " p$"
  c db "not p$"
.code
start:
mov AX,@data
mov ds,ax
mov si,offset a
mov di ,offset a
mov bh ,[di]
l:
cmp [si] ,'$'
jz k
inc si
loop l
k:
dec si  
cmp [si] ,bh
 jnz t
mov dl,[si]
mov ah,02h
int 21h
mov dl,bh
  mov ah,02h
int 21h
 
    inc di
    mov bh,[di]
    cmp bh,'$'
    jz p
loop k
t:
mov dx,offset c
mov ah,09h
int 21h 
jmp s
p:
mov dx,offset b
mov ah,09h
int 21h
 s:
end start
 ;when bx was used didn't work ..now with bh works