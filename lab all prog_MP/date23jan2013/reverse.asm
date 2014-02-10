.model small
.data
a db "nitkkr$"
.code
start:
mov AX,@data
mov ds,ax
mov si,offset a
mov di ,offset a
mov bx ,[di]
l:
cmp [si] ,'$'
jz k
inc si
loop l
k:
dec si  
cmp [si] ,bx
mov dl,[si]
mov ah,02h
int 21h
jz p
loop k
p:
end start