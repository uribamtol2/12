#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int number;
    char title[20];
};

int main(void) {
    struct Book *p;

    p = (struct Book *)malloc(2 * sizeof(struct Book));

    if (p == NULL) {
        printf("memory alloc error!\n");
        return -1;
    }

    p->number = 1;
    strcpy(p->title, "C Programming");

    (p + 1)->number = 2;
    strcpy((p + 1)->title, "electronics");

    printf("%i: %s\n", p->number, p->title);
    printf("%i: %s\n", (p+1)->number, (p+1)->title);

    free(p);

    return 0;
}