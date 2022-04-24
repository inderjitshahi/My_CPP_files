dosseg
.model small
.stack 100h
.data
quo db ?
rem db ?
.code
main proc
mov ax,@data
mov ds,ax
mov ax,15
mov bl,3
div bl

mov quo,al
mov rem,ah

mov dl,rem
add dl,48
mov ah,2
int 21h
 
mov dl, 4ch
int 21h
main endp
end main