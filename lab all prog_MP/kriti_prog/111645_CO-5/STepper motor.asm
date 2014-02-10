#start=stepper_motor.exe#
name "stepper"
steps_before_direction_change = 10h ; 32 (decimal)
jmp start
; half-step rotation  clock-wise:
datcw    db 0000_0011b
         db 0000_0110b    
         db 0000_1100b
         db 0000_1001b

; half-step rotation  counter-clock-wise:
datccw   db 0000_0011b
         db 0000_1001b    
         db 0000_1100b
         db 0000_0110b

; full-step rotation clock-wise:
datcw_fs db 0000_0011b
         db 0000_0110b    
         db 0000_1001b
         db 0000_0011b

; full-step rotation counter-clock-wise:
datccw_fs db 0000_0011b
          db 0000_1001b    
          db 0000_0110b
          db 0000_0000b


start:
mov bx, offset datcw ; start from clock-wise half-step.
mov si, 0
mov cx, 0 ; step counter

next_step:
; motor sets top bit when it's ready to accept new command
wait:   in al, 7     
        test al, 10000000b
        jz wait

mov al, [bx][si]
out 7, al

inc si

cmp si, 4
jb next_step
mov si, 0

inc cx
cmp cx, steps_before_direction_change
jb  next_step

mov cx, 0
add bx, 4 ; next bin data

cmp bx, offset datccw_fs
jbe next_step

mov bx, offset datcw ; return to clock-wise half-step.

jmp next_step



