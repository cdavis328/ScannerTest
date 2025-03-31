#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void pop_ret() {
    __asm__("pop %rdi; ret");
}

void vuln() {
    char buffer[64];
    char input[128];  // Extra buffer to hold user input before copying
    read(0, input, 127); 
    strcpy(buffer, input); // Still vulnerable to overflow!
    printf("/bin/sh", buffer); // Potential format string vulnerability
    pop_ret();
}

int main() {
    setbuf(stdout, NULL);
    vuln();
    return 0;
}
