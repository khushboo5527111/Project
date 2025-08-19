#include <stdio.h>
#define MAX 100000   // maximum queue size (safe upper bound)

// Two stacks
int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Utility functions for stack
void push1(int x) { stack1[++top1] = x; }
void push2(int x) { stack2[++top2] = x; }
int pop1() { return stack1[top1--]; }
int pop2() { return stack2[top2--]; }
int isEmpty1() { return top1 == -1; }
int isEmpty2() { return top2 == -1; }
int peek2() { return stack2[top2]; }

// Move all elements from stack1 to stack2
void transfer() {
    while (!isEmpty1()) {
        push2(pop1());
    }
}

// Enqueue operation
void enqueue(int x) {
    push1(x);
}

// Dequeue operation
void dequeue() {
    if (isEmpty2()) {
        transfer();
    }
    if (!isEmpty2()) pop2();
}

// Front/Peek operation
void front() {
    if (isEmpty2()) {
        transfer();
    }
    if (!isEmpty2()) {
        printf("%d\n", peek2());
    }
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int type, x;
        scanf("%d", &type);

        if (type == 1) {       // Enqueue
            scanf("%d", &x);
            enqueue(x);
        } 
        else if (type == 2) {  // Dequeue
            dequeue();
        } 
        else if (type == 3) {  // Print front
            front();
        }
    }
    return 0;
}
