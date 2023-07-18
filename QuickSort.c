#include <stdio.h>
#include <stdlib.h>
int partition(int A[], int low, int high)
{
    int i, j, pivot, temp;
    i = low + 1;
    pivot = A[low];
    j = high;
    while (i <= j)
    {
        while (A[i] <= pivot)
            i++;
        while (A[j] > pivot)
            j--;

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
void quickSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = partition(A, low, high);
        quickSort(A, low, mid - 1);
        quickSort(A, mid + 1, high);
    }
}
int main()
{
    int n;
    int i;
    int A[10];
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter array elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
	printf("Before Quick sort:\n");
	for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    quickSort(A, 0, n - 1);
	printf("After Quick sort:\n");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
}
