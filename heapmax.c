#include<stdio.h>
void main()
{
    char a[20];
    char Key[20];
    int i,n,k;
    printf("enter the size of heap:\n");
    scanf("%d",&n);
    printf("enter the heap character:\n");
    for(i=0;i<n;i++)
    {
        scanf("%c",&a[i]);

    }
    heapSort(a, n);
    printf("Array after max heapification is:\n");
        printArray(a,n);


     printf("Enter the new character to be inserted into the heap:\n");
     for(i=0;i<n;i++)
    {
        scanf("%c",&Key[i]);
    }
        insertheap(Key, n, a);

    printf("Array after inserting new character in the heap is:\n");
    printArray(a,n);
}
void maxheapify(char a[], int n, int i)
{

    int largest = i;
    int l = 2*i ;
    int r = (2*i) + 1;

     if (l < n && a[l] > a[largest])
        largest = l;

     if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i)
    {
        char temp;
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        maxheapify(a, n, largest);

    }
}
void heapSort(char a[], int n)
{

    for (int i = (n / 2) - 1; i >=0; i--)
    {
        maxheapify(a, n, i);
    }
    for (int i=n-1; i>0; i--)
    {
        char temp;
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        maxheapify(a, i, 0);
    }
}
void insertheap(char a[], int n, char Key[])
{
    n = n + 10;
    for(int i=0;i<n;i++)
    {
       a[n - 1] = Key[i];
       maxheapify(a, n, n-1);

    }

}
void printArray(char a[], int n)
{
    for (int i = n-1; i >=0; i--)
        printf("%c\t", a[i]);
    printf("\n");
}

