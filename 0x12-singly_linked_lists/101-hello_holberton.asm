section .data
; Define data section
hello db "Hello, Holberton,", 10, 0 ; Message with newline and null-terminator
format db "%s", 0                ; Format string for printf

section .text
; Define text section
global main
extern printf

main:
; Main function
push rbp
mov rdi, format         ; Set format string
mov rsi, hello          ; Set message
call printf             ; Call printf
pop rbp
ret                     ; Return

