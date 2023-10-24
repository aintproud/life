#include <stdio.h>

int main() {
    printf("\033[0;31m"); // Set color to red
    printf("This text is in red color.\n");
    printf("\033[0m"); // Reset color to default

    return 0;
}