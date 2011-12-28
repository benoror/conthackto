char shellcode[] =     	"\xb8\x04\x00\x00\x00" 	//mov    $0x4,%eax
                		"\xbb\x01\x00\x00\x00" 	//mov    $0x1,%ebx
                		"\x68\x68\x6f\x6c\x61" 	//push   $0x616c6f68
                		"\x89\xe1"             	//mov    %esp,%ecx
                		"\xba\x04\x00\x00\x00" 	//mov    $0x4,%edx
                		"\xcd\x80"            	//int    $0x80
                		"\xb8\x01\x00\x00\x00" 	//mov    $0x1,%eax
                		"\xbb\x00\x00\x00\x00" 	//mov    $0x0,%ebx
                		"\xcd\x80";            	//int    $0x80

main() {
	void (*fp) (void);

	fp = (void *)shellcode;
	fp();
}
