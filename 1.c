#include <stdio.h>
#include <unistd.h>

int main() {
    int count = 0;

    while (1) {
        printf("Count: %d\n", count);
        count++;

        sleep(1);
    }

    return 0;
}