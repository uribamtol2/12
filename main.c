#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int number;
    char title[30];
};

int main(void) {
    int i;
    struct Book **bookshelf;

    // 동적 할당
    bookshelf = (struct Book **)malloc(3 * sizeof(struct Book *));

    for (i = 0; i < 3; i++) {
        bookshelf[i] = (struct Book *)malloc(10 * sizeof(struct Book));
    }

    bookshelf[1][3].number = 5;
    strcpy(bookshelf[1][3].title, "C++ programming");

    (bookshelf[2] + 4)->number = 3;
    strcpy((bookshelf[2] + 4)->title, "Communications");

    printf("book (1,3) : %i, %s\n",
        (bookshelf[1] + 3)->number,
        (bookshelf[1] + 3)->title);

    // 메모리 해제
    for (i = 0; i < 3; i++) {
        free(bookshelf[i]);
    }

    free(bookshelf);

    return 0;
}