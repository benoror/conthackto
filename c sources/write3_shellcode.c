char shellcode[] =     	"\x31\xc0" 				//xor    %eax,%eax		;xoreamos %eax para que inicialice en cero
                		"\x89\xc3" 				//mov    %eax,%ebx		;%ebx = 0
                		"\x89\xc2" 				//mov    %eax,%edx		;%edx = 0
                		"\xb0\x04"				//mov    $0x4,%al		;%al = 4						(Syscall write)
                		"\xb3\x01" 				//mov    $0x1,%bl		;%bl = 1 						(stdout)
                		"\x68\x68\x6f\x6c\x61" 	//push   $0x616c6f68	;"hola"
                		"\x89\xe1" 				//mov    %esp,%ecx		;%ecx apunta a "hola"
                		"\xb2\x04" 				//mov    $0x4,%dl		;%dl = 4						(4 caracteres)
                		"\xcd\x80" 				//int    $0x80			;interruptor
                		"\x31\xc0" 				//xor	 %eax,%eax		;reestablecemos %eax en cero
                		"\x89\xc3" 				//mov    %eax,%ebx		;reestablecemos %ebx en cero	(exit(0))
                		"\xb0\x01" 				//mov    $0x1,%al		;%al = 1 						(Syscall exit)
                		"\xcd\x80";				//int    $0x80			;interruptor

main() {
	void (*fp) (void);

	fp = (void *)shellcode;
	fp();
}
