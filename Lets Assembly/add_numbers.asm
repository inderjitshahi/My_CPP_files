; program to subtract two numbers
dosseg
.model small
.stack 100h
.data
.code
main proc
 mov bl,3  ;move 3 to register bl
 mov cl,1   ;move 3 to register cl
 add bl,cl  ;register addresing mode i.e. take data from register
 add bl,48   ;since b1 will have 3+1=4 a character; converting it into 4+48=52 i.e. char '4'; also direct addressing mode is used
 mov dl,bl   ;mov data from bl to data register(dl)
 mov ah,2    ;print
 int 21h     ;halt
mov ah, 4ch
int 21h
main endp
end main