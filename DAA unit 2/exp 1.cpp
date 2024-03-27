#include <stdio.h>

void copyString(char *src, char *dest) {
    if (*src == '\0') {
        *dest = '\0';
        return;
    }
    *dest = *src;
    copyString(src + 1, dest + 1);
}

int main() {
    char source[] = "Hello, World!";
    char destination[50];
    copyString(source, destination);
    printf("Copied string: %s\n", destination);
    return 0;
}

