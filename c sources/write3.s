.globl main
main:

xor    %eax,%eax
mov    %eax,%ebx
mov    %eax,%edx
mov    $0x4,%al
mov    $0x1,%bl
push   $0x616c6f68
mov    %esp,%ecx
mov    $0x4,%dl
int    $0x80

xor    %eax,%eax
mov    %eax,%ebx
mov    $0x1,%al
int    $0x80
