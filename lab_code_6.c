// Reverse an Array:
#include <stdio.h>

int main()
{
    int A[5] = {10, 20, 30, 40, 50};
    int i, j, temp;
    i = 0;
    j = 4;
     while(i < j)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        i++;
        j--;
    }
    for(i = 0; i < 5; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}