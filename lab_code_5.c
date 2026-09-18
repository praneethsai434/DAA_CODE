//Find Sum and Average of Array Elements:
#include <stdio.h>

int main()
{
    int A[5], i, sum = 0;
    float average;

    for(i = 0; i < 5; i++)
    {
        scanf("%d", &A[i]);
        sum = sum + A[i];
    }

    average = (float)sum / 5;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f", average);

    return 0;
}