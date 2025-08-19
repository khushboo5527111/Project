char* isBalanced(char* s) {
    int len = strlen(s);
    char* stack = malloc(len);  // stack for brackets
    int top = -1;               // stack pointer

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;   // push
        } else {
            if (top == -1) {
                free(stack);
                return "NO";    // closing bracket without match
            }

            char open = stack[top--];  // pop

            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                free(stack);
                return "NO";    // mismatch
            }
        }
    }

    char* result;
    if (top == -1) {
        result = "YES";
    } else {
        result = "NO";
    }

    free(stack);
    return result;
}
