#include <stdio.h>
#include <stdlib.h>

// Define the TypeTag enumeration
typedef enum TypeTag {
    ADD,
    MUL,
    SUB,
    FIBO
} TypeTag;

typedef struct Node {
    TypeTag type;
    int value;
    
    union {
        struct {
            struct Node *arg1;
            struct Node *arg2;
        } operands;
    };
} Node;

typedef Node* (*OperationFunc)(void* arg1, void* arg2);

// Function to perform addition
Node *addFunc(void *arg1, void *arg2) {
    int a = *((int *)arg1);
    int b = *((int *)arg2);

    Node *result = (Node *)malloc(sizeof(Node));
    result->value = a + b;
    return result;
}

// Function to perform subtraction
Node *subFunc(void *arg1, void *arg2) {
    Node *a = (Node *)arg1;
    Node *b = (Node *)arg2;

    Node *result = (Node *)malloc(sizeof(Node));
    result->value = b->value - a->value;
    return result;
}

// Function to perform multiplication
Node *mulFunc(void *arg1, void *arg2) {
    int a = *((int *)arg1);
    int b = *((int *)arg2);

    Node *result = (Node *)malloc(sizeof(Node));
    result->value = a * b;
    return result;
}
#define MAX_SIZE 100

int memo[MAX_SIZE];

int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1 || n == -1)
        return 1;

    if (n > 1) {
        if (memo[n] == 0)
            memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return memo[n];
    } else {
        if (memo[n] == 0)
            memo[n] = fibonacci(n + 2) - fibonacci(n + 1);
        return memo[n];
    }
}
Node *fiboFunc(void *arg1, void *arg2) {
    Node *a = (Node *)arg1;

    Node *result = (Node *)malloc(sizeof(Node));

    result->value = fibonacci(a->value + 1);

    return result;
}

// Function that returns a function pointer based on the provided operation code
OperationFunc makeFunc(TypeTag type) {
    switch (type) {
        case ADD:
            return &addFunc;
        case SUB:
            return &subFunc;
        case MUL:
            return &mulFunc;
        case FIBO:
            return &fiboFunc;
        default:
            return NULL; // Invalid operation type
    }
}

int calc(Node* node) {
    if (node == NULL) {
        return 0;
    }

    switch (node->type) {
        case ADD:
        case MUL:
        case SUB:
        case FIBO:
            return node->value;
        default:
            return 0; // Unknown type
    }
}

int main() {

    int a = 10;
    int b = 6;
    
    void *arg1 = (void *)&a;
    void *arg2 = (void *)&b;

    int c = 5;
    int d = 4;
    void *arg3 = (void *)&c;
    void *arg4 = (void *)&d;

    Node *add = (*makeFunc(ADD))(arg1, arg2);
    Node *mul = (*makeFunc(MUL))(arg3, arg4);
    Node *sub = (*makeFunc(SUB))(mul, add);
    Node *fibo = (*makeFunc(FIBO))(sub, NULL);
   
    printf("add : %d\n", calc(add));
    printf("mul : %d\n", calc(mul));
    printf("sub : %d\n", calc(sub));
    printf("fibo : %d\n", calc(fibo));

   
    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}