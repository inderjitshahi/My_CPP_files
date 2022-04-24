dosseg
.model small
.stack 100h
.data
.code
main proc
mov ax,'1'
push ax   ;push ax into stack
mov bx,'2'
push bx

pop ax   ;assign top of satck ie,2 to ax
pop bx
;printing numbers
mov dx,ax
mov ah,2
int 21h

mov dx,bx
mov ah,2
int 21h

mov ah, 4ch
int 21h
main endp
end main