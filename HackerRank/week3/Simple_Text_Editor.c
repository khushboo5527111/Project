#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int top;
    int size;
} Stack;

void init(Stack *st, int n) {
    st->data = (char **)malloc(n * sizeof(char *));
    st->top = -1;
    st->size = n;
}

int empty(Stack *st) {
    return st->top == -1;
}

void expand(Stack *st) {
    st->size *= 2;
    st->data = (char **)realloc(st->data, st->size * sizeof(char *));
}

void push(Stack *st, const char *s) {
    if (st->top == st->size - 1) expand(st);
    st->data[++st->top] = strdup(s); // duplicate string
}

char *pop(Stack *st) {
    if (empty(st)) return NULL;
    return st->data[st->top--];
}

int main() {
    int q;
    scanf("%d", &q);

    char text[1000001] = "";
    Stack st;
    init(&st, q);

    for (int i = 0; i < q; i++) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            char w[1000001];
            scanf("%s", w);
            push(&st, text);
            strcat(text, w);
        } 
        else if (op == 2) {
            int k;
            scanf("%d", &k);
            push(&st, text);
            int len = strlen(text);
            if (len >= k) text[len - k] = '\0';
        } 
        else if (op == 3) {
            int k;
            scanf("%d", &k);
            if (k > 0 && k <= strlen(text))
                printf("%c\n", text[k - 1]);
        } 
        else if (op == 4) {
            char *prev = pop(&st);
            if (prev != NULL) {
                strcpy(text, prev);
                free(prev);
            }
        }
    }

    while (!empty(&st)) free(pop(&st));
    free(st.data);
    return 0;
}
