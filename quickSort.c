#include <stdio.h>
void swap(int *a, int *b)
{
int t = *a;
*a = *b;
*b = t;
}
int partition(int array[], int low, int high)
{
int pivot = array[high];
int i = (low - 1);
for (int j = low; j < high; j++)
{
if (array[j] <= pivot)
{
i++;
swap(&array[i], &array[j]);
}
}
swap(&array[i + 1], &array[high]);
return (i + 1);
}
void quickSort(int array[], int low, int high)
{
if (low < high)
{
int pi = partition(array, low, high);
quickSort(array, low, pi - 1);
quickSort(array, pi + 1, high);
}
}
void printArray(int array[], int size){
for (int i = 0; i < size; ++i)
{
printf("%d ", array[i]);
}
printf("\n");
}
int main()
{
int lim;
printf("Enter the number of elements you want to enter : ");
scanf("%d",&lim);
int data[lim];
printf("Enter the elements :\n");
for(int i = 0;i<lim;i++)
{
scanf("%d",&data[i]);
}
int n = sizeof(data) / sizeof(data[0]);
printf("Unsorted Array\n");
printArray(data, n);
quickSort(data, 0, n - 1);
printf("Sorted array in ascending order: \n");
printArray(data, n);
}

