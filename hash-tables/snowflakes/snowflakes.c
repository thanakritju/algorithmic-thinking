#include <stdio.h>
#define SIZE 100000

int identical_right(int snow1[], int snow2[], int start) {
    int offset;
    for (offset = 0; offset< 6; offset++) {
        if (snow1[offset] != snow2[(start + offset) % 6]) {
            return 0;
        }
    }
    return 1;
}

int identical_left(int snow1[], int snow2[], int start) {
    int offset;
    for (offset = 0; offset < 6; offset++) {
        int offset2 = start - offset;
        if (offset2 < 0) {
            offset2 = offset2 + 6;
        }
        if (snow1[offset] != snow2[offset2]) {
            return 0;
        }
    }
    return 1;
}

int are_indentical(int snow1[], int snow2[]) {
    int start;
    for (start = 0; start < 6; start ++) {
        if (identical_right(snow1, snow2, start)) {
            return 1;
        }
        if (identical_left(snow1, snow2, start)) {
            return 1;
        }
    }
    return 0;
}

void identify_identical(int snowflakes[][6], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (are_indentical(snowflakes[i], snowflakes[j])) {
                printf("Twin snowflakes found.\n");
                return;
            }
        }
    }
    printf("No two snowflakes are alike.\n");
}

int main(void) {
    static int snowflakes[SIZE][6];
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < 6; j++) {
            scanf("%d", &snowflakes[i][j]);
        }
    }
    identify_identical(snowflakes, n);
    return 0;
}