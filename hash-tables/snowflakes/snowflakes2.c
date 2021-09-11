#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000

typedef struct snowflake_node {
    int snowflake[6];
    struct snowflake_node *next;
} snowflake_node;

int code(int s[]) {
    return (s[0] + s[1] + s[2] + s[3] + s[4] + s[5]) % SIZE ;
}

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

int are_identical(int snow1[], int snow2[]) {
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

void identify_identical(snowflake_node *snowflakes[]) {
    snowflake_node *node1, *node2;
    int i;
    for (i = 0; i < SIZE; i++) {
        node1 = snowflakes[i];
        while (node1 != NULL) {
            node2 = node1->next;
            while (node2 != NULL) {
                if (are_identical(node1->snowflake, node2->snowflake)) {
                    printf("Twin snowflakes found.\n");
                    return;
                }
                node2 = node2->next;
            }
            node1 = node1->next;
        }
    }
    printf("No two snowflakes are alike.\n");
}

int main(void) {
    static snowflake_node *snowflakes[SIZE] = {NULL};
    snowflake_node *snow;
    int n, i, j, snowflake_code;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        snow = malloc(sizeof(snowflake_node));
        if (snow == NULL) {
            fprintf(stderr, "malloc error\n");
            exit(1);
        }
        for (j = 0; j < 6; j++) {
            scanf("%d", &snow->snowflake[j]);
        }
        snowflake_code = code(snow->snowflake);
        snow->next = snowflakes[snowflake_code];
        snowflakes[snowflake_code] = snow;
    }
    identify_identical(snowflakes);
    return 0;
}