;program to print the single chaaecter
dosseg
.model small  ;assigning size of file/program
.stack 100h
.data   ;data segment

.code    ;code segment 
main proc
 mov dx,'a' ;sending character 'a' to data register
 mov ah,2   ;asking accumulator to print
 int 21h    ;halting the program for microprocessor to print a
 mov ah, 4ch ;terminating program
 int 21h
main endp
end main
