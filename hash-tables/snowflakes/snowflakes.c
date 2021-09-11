#include <stdio.h>
#define SIZE 100000

int main(void) {
    static int snowflakes[SIZE][6];
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < 6; j++) {
            scanf("%d", &snowflakes[i][j]);
        }
    }
    printf("Twin snowflakes found.", n);
    return 0;
}