dosseg
.model small
.stack 100h
.data
.code
main proc
 mov ah,1  ;asking accumulator to take input
 int 21h   ;halting to take input
 mov dl,al ; moving data from accumulator to data register
mov ah,2   ;print  value of data register
int 21h
mov ah, 4ch
int 21h
main endp
end main