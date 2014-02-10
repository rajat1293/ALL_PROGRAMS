;Program to add two 2-digit numbers
.model small

.data
a db "Enter a number: $"
b db "The sum is: $"

.code
start:

MOV AX,@data
MOV DS,AX

MOV DX,offset a
MOV AH,09h
Int 21h
MOV AH,01h
Int 21h
MOV BH,AL
MOV AH,01h
Int 21h
MOV BL,AL

MOV DL,0AH
MOV AH,02h
Int 21h
mov dl,13
mov ah,02h
int 21h

MOV DX,offset a
MOV AH,09h
Int 21h
MOV AH,01h
Int 21h
MOV CH,AL
MOV AH,01h
Int 21h

MOV AH,00
ADD AL,BL
AAA
MOV CL,AL
MOV AL,AH
MOV AH,00
ADD AL,BH
ADD AL,CH
AAA
MOV CH,AL
MOV BH,AH

MOV DL,0AH
MOV AH,02h
Int 21h
mov dl,13
mov ah,02h
int 21h

MOV DX,offset b
MOV AH,09h
Int 21h
MOV DL,BH
ADD DL,48
MOV AH,02h
Int 21h
MOV DL,CH
ADD DL,48
MOV AH,02h
Int 21h
MOV DL,CL
ADD DL,48
MOV AH,02h
Int 21h

MOV AH,4CH
Int 21h
end start
