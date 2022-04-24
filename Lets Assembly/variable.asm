dosseg
.model small
.stack 100h
.data
var db 'apple$'
.code
main proc
 mov ax,@data
 mov ds,ax
 lea dx,var    ;lead effective address for whole string

 mov ah,9   ;printing string
 int 21h
; OR
; mov dx,offset var3 instead lea

mov ah, 4ch
int 21h
main endp
end main