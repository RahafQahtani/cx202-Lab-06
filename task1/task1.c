#include <stdio.h>
#include <stdlib.h>

// Takes input for vector x and y from the user
void input_vector(int size, int  ptrx[size], int  ptry[size]) {
    printf("Enter the elements of vector x:\n");
    for (int i = 0; i < size; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &ptrx[i]);
    }
        printf("Enter the elements of vector y:\n");
    for (int i = 0; i < size; i++) {
        printf("y[%d]: ", i);
        scanf("%d", &ptry[i]);
    }

}

int main()
{
	int size, i, *ptrx , *ptry ,*ptrz, a,b;
	printf("calculating z=ax+by\n");
	printf("Enter size of vector x and y: ");
	scanf("%d", &size);
	ptrx = (int*) malloc(size * sizeof(int));
	ptry = (int*) malloc(size * sizeof(int));
	ptrz = (int*) malloc(size * sizeof(int));

// if memory cannot be allocated
	if(ptrx== NULL) {
	printf("Error! memory not allocated.");
	return 1;
}
        if(ptry== NULL) {
        printf("Error! memory not allocated.");
        return 1;
}
        if(ptrz== NULL) {
        printf("Error! memory not allocated.");
        return 1;
}
 

// Take input forvector ptrx,ptry,ptrz
	input_vector(size, ptrx,ptry);
// take input a and b scalars 
       printf("Enter scalar a: ");
        scanf("%d", &a);
	printf("Enter scalar b: ");
	scanf("%d", &b);
//y=ax+by
        for (i= 0; i < size; i++) {
            ptrz[i] = a*ptrx[i] + b*ptry[i];
        }
    
	printf("Resulting matrix (z = ax * by):\n");
    	for (i = 0; i < size; i++) {
        printf("z[%d] = %d\n", i, ptrz[i]);
    }

// deallocating the memory
	free(ptrx);
	free(ptry);
	free(ptrz);

return 0;
}
