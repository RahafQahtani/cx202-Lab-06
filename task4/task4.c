#include <stdio.h>
#include <stdlib.h>

int main() {
    int *stack; 
    int size = 0; 
    char command; 

    // Allocate memory for one element
    stack = (int*) malloc(sizeof(int));
    // if memory cannot be allocated
    if (stack == NULL) {
        printf("Error! memory not allocated.");
        return 1;
    }

    while (1) {
        // Prompt the user to enter a command
        printf("Enter a command (p: push, o: pop, d: display, e: exit): ");
        scanf(" %c", &command);

        // if command is 'p', push an integer onto the stack
        if (command == 'p') {
            int value; // Variable to store the value to be pushed
            printf("Enter an integer to push: ");
            scanf("%d", &value);
            size++; // Increase stack size
            stack = (int*) realloc(stack, size * sizeof(int));
            // if memory cannot be allocated
            if (stack == NULL) {
                printf("Error! memory not allocated.");
                return 1;
            }
            stack[size - 1] = value; // Add value to the stack

        // if command is 'o', pop an integer from the stack
        } else if (command == 'o') {
            if (size == 0) {
                printf("Stack is empty, cannot pop.\n");
            } else {
                printf("Popped value: %d\n", stack[size - 1]);
                size--; // Decrease stack size
                if (size > 0) {
                    stack = (int*) realloc(stack, size * sizeof(int));
                    // if memory cannot be allocated
                    if (stack == NULL) {
                        printf("Error! memory not allocated.");
                        return 1;
                    }
                } else {
                    free(stack); // Free memory if stack is empty
                    stack = NULL;
                }
            }

        // if command is 'd', display the current contents of the stack
        } else if (command == 'd') {
            if (size == 0) {
                printf("Stack is empty.\n");
            } else {
                printf("Current stack: ");
                for (int i = size - 1; i >= 0; i--) {
                    printf("%d ", stack[i]);
                }
                printf("\n");
            }

        // if command is 'e', terminate the program
        } else if (command == 'e') {
            break;

        // invalid command
        } else {
            printf("Invalid command! Please enter a valid command.\n");
        }
    }

    // 
    free(stack);
    printf("Exiting the program. All memory has been freed.\n");

    return 0;
}
