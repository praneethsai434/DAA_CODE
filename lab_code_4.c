// Find the Largest Element in an Array
#include <stdio.h>

int main()
{
    int A[5] = {10, 25, 7, 40, 15};
    int i, max;

    max = A[0];

    for(i = 1; i < 5; i++)
    {
        if(A[i] > max)
        {
            max = A[i];
        }
    }

    printf("Largest = %d", max);

    return 0;
}