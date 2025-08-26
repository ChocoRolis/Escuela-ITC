#include <stdio.h>

int main() {
    char str[128];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    printf("You entered: %s", str);
    printf("size: %zu\n", sizeof(str));
    return 0;
}
