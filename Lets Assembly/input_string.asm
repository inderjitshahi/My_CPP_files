dosseg
.model small
.stack 100h
.data
s db 100 dup('$')
.code
main proc
mov ax,@data
mov ds,ax
mov si,offset s

l1:
mov ah,1
int 21h
cmp al,13
je programend
mov [si],al
inc si
jmp l1   ;jump to l1 so that to continue taking input

programend:
mov dx,offset s
mov ah,9
int 21h
mov ah, 4ch
int 21h
main endp
end main