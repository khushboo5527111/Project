#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 1000
#define MAX_LENGTH 101

int main() {
    int array_size, query_size;
    char strings[MAX_STRINGS][MAX_LENGTH];
    char queries[MAX_STRINGS][MAX_LENGTH];
    int results[MAX_STRINGS] = {0};

    scanf("%d", &array_size);
    for (int idx = 0; idx < array_size; idx++) {
        scanf("%s", strings[idx]);
    }

    scanf("%d", &query_size);
    for (int idx = 0; idx < query_size; idx++) {
        scanf("%s", queries[idx]);
    }

    for (int q = 0; q < query_size; q++) {
        int match_count = 0;
        for (int s = 0; s < array_size; s++) {
            if (strcmp(queries[q], strings[s]) == 0) {
                match_count++;
            }
        }
        results[q] = match_count;
    }

    for (int q = 0; q < query_size; q++) {
        printf("%d\n", results[q]);
    }

    return 0;
}
