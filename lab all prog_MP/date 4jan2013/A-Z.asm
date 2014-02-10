 .model small
.code
start:
mov cl,255
mov bl,41h
l: 
mov dl,bl
mov ah,02h
int 21h
inc dl
mov bl,dl
mov dl,13
mov ah,02h
int 21h
mov dl,10
mov ah,02h
int 21h
loop l
end start
;runs for 'A' ,also for 65,also for 41h,
;all just mean the same
;even we can use binary with 1000001b
 ;0d is 12 \r and 0A is 10 \n                  