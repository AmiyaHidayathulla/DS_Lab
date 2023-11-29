#include <stdio.h>
void main()
{
int n,i,temp,j;
printf("Enter the number of elements : ");
scanf("%d",&n);
int array[n];
printf("Enter the elements of the array : ");
for(i=0;i<n;i++)
{
scanf("%d",&array[i]);
}
printf("The given unsorted array is: ");
for(i=0;i<n;i++)
{
printf("%d ",array[i]);
}
for(i=1;i<n;i++)
{
temp=array[i];
j=i-1;
while (j>=0&&array[j]>temp)
{
array[j+1]=array[j];
j--;
}
array[j+1]=temp;
}
printf("\nSorted array : ");
for (i=0;i<n;i++)
{
printf("%d ",array[i]);
}
}
