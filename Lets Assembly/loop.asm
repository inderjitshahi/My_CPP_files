dosseg
.model small
.stack 100h
.data
.code
main proc
 
 mov cx,10  ;initializing counter register with 10 for loop 10 times
 mov bx,'0'


 l1:         ;loop starts here
mov dx,bx
mov ah,2
int 21h

mov bx,dx

mov dx,10
mov ah,2
int 21h

inc bx       ;increament dx
loop l1      ;loop ends here

mov ah, 4ch
int 21h
main endp
end main