;input numbers from users  and add 
dosseg
.model small
.stack 100h
.data
.code
main proc
 mov ah,1
 int 21h
mov bl,al  ;saving the value of al to bl

mov ah,1
int 21h

add bl,al  
sub bl,48 
mov dl,bl

mov ah,2
int 21h
mov ah, 4ch
int 21h
main endp
end main