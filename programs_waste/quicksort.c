#include<stdio.h>
main()
{
int numbers[100],arraysize,i;
printf("enter no. of elements");
scanf("%d",&arraysize);
printf("enter array elements");
for(i=0;i<arraysize;i++)
{
scanf("%d",&numbers[i]);
}
int q_sort(int numbers[],int,int);
q_sort(numbers,0,arraysize);
printf("array after sort");
for(i=0;i<arraysize;i++)
{
printf("%d",numbers[i]);
}
}
int q_sort(int numbers[], int left1, int right1)
{
  if(left1<right1)
  {
    int pivot,temp,j,k;
  pivot = numbers[left1];
  j=left1;
  k=right1;
  while (j < k)
  {
    while ((numbers[k] >= pivot) && (j < k))
      k--;
    while ((numbers[j] <= pivot) && (j < k))
      j++;

      temp=numbers[j];
      numbers[j]=numbers[k];
      numbers[k]=temp;
}
  temp=numbers[left1];
  numbers[left1]=numbers[k];
  numbers[k]=temp;
    q_sort(numbers, left1, k-1);
    q_sort(numbers, k+1, right1);
  }
}
