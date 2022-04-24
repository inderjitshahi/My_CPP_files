dosseg
.model small
.stack 100h
.data
arr db 2,3,1,6,7,8
.code
main proc
 mov ax,@data
 mov ds,ax
mov si,offset arr     ;assing address arr[0] to si
mov cx,6
 l1:
mov dx,[si]   ;moving value strores at address si to dx
add dx,48
mov ah,2
int 21h
inc si   ;increameting array for next address
 loop l1

mov ah, 4ch
int 21h
main endp
end main