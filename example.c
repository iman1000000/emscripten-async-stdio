#include "stdio_async.h"

int main(int argc, char *argv []) {
    printf("one plus one is %d\n", 1+1);
    putchar('#');
    putchar('\n');
    puts("enter some text:");
    char arr[10];
    while (1) {
        char arr[10];
        if (fgets(arr, 10, stdin) == NULL) {
            puts("EOF");
        } else {
            puts(arr);
        }
    }
    return 0;
}
