#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};


struct Stack {
struct Node* top;
};

void push(struct Stack* stack, int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = stack->top;
stack->top = newNode;
printf("Pushed %d onto the stack.\n", value);
}

int pop(struct Stack* stack) {
if (stack->top == NULL) {
printf("Stack is empty. Cannot pop.\n");
return -1;
}

struct Node* temp = stack->top;
int poppedValue = temp->data;
stack->top = temp->next;
free(temp);
printf("Popped %d from the stack.\n", poppedValue);
return poppedValue;
}

int main() {
struct Stack stack;
stack.top = NULL;

int choice, value;

while (1) {
    printf("\nStack Operations:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(&stack, value);
            break;
        case 2:
            pop(&stack);
            break;
        case 3:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

return 0;
}