#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    char *ptrs, *revptrs;

    printf("Enter size of string: ");
    scanf("%d", &size);

    // Allocating memory, adding 1 to hold the null terminator
    ptrs = (char*) malloc((size + 1) * sizeof(char));
    revptrs = (char*) malloc((size + 1) * sizeof(char));

    // Check if memory allocation was successful
    if (ptrs == NULL || revptrs == NULL) {
        printf("Error! Memory not allocated.");
        return 1;
    }

    printf("Enter string: ");
    for(int i=0; i<size ;i++){
    scanf(" %c",&ptrs[i]);
    
    }
    // Reverse the string
    for (int i = 0; i < size; i++) {
        revptrs[i] = ptrs[size - i - 1];
    }

    printf("Reversed string: %s\n", revptrs);
    printf("Original string: %s\n", ptrs);

    // Deallocate memory
    free(ptrs);
    free(revptrs);

    return 0;
}
