#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr,size = 1,sum = 0, count = 0; 
    char choice; 

    // Allocate memory for one integer initially
    ptr = (int*) malloc(size * sizeof(int));
    // if memory cannot be allocated
    if (ptr == NULL) {
        printf("Error! Memory not allocated.");
        return 1;
    }

    // Prompt the user to input integer samples
    do {
        printf("Enter a sample integer value: ");
        scanf("%d", &ptr[count]);
        sum += ptr[count]; 
        count++;

        // to add more samples
        printf("Do you want to add more samples? (y/n): ");
        scanf(" %c", &choice);

        // reallocate memory for the additional integer
        if (choice == 'y' || choice == 'Y') {
            size++; // Increase size by 1
            ptr = (int*) realloc(ptr, size * sizeof(int));
        // if memory cannot be allocated
            if (ptr == NULL) {
                printf("Error! Memory not allocated.");
                return 1;
            }
        }
    } while (choice == 'y' || choice == 'Y');

    // Calculate the average (DC value) of the entered samples
    float average = (float)sum / count;

    // Print the entered samples
    printf("You entered the following samples: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\nCalculated average (DC value): %.2f\n", average);

    // Subtract the average from each sample to perform the DC shift
    printf("Final adjusted samples after DC shift:\n");
    for (int i = 0; i < count; i++) {
        ptr[i] -= (int)average; // Adjusted sample
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Deallocating the memory
    free(ptr);

    return 0;
}
