; program to take 2 numbers from user and add them
dosseg
.model small
.stack 100h
.data
.code
main proc
mov ah,1   ;input 1
int 21h
mov bl,al   ;string data from al to bl

mov ah,1
int 21h

add bl,al
sub bl,48   ;as ascii character

mov dl,bl

mov ah,2
int 21h

mov ah, 4ch
int 21h
main endp
end main