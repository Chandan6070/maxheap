#include<stdio.h>
void main()
{
    int a[20];
    int Key;
    int i,n;
    printf("enter the size of heap:\n");
    scanf("%d",&n);
    printf("enter the heap element:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    heapSort(a, n);
    printf("Array after max heapification is:\n");
        printArray(a,n);


    printf("Enter the new element to be inserted into the heap:\n");
    scanf("%d",&Key);
            insertheap(a, n, Key);
            heapSort(a, n);




    printf("Array after inserting new element in the heap is:\n");
    printArray(a,n);
}
void maxheapify(int a[], int n, int i)
{

    int largest = i;
    int l = (2*i)+1 ;
    int r = (2*i) + 2;

     if (l < n && a[l] > a[largest])
        largest = l;

     if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i)
    {
        int temp;
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        maxheapify(a, n, largest);

    }
}
void heapSort(int a[], int n)
{

    for (int i = (n / 2) - 1; i >=0; i--)
        {
        maxheapify(a, n, i);
        }
    for (int i=n-1; i>0; i--)
    {
        int temp;
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        maxheapify(a, i, 0);
    }
}
void insertheap(int a[], int n, int Key)
{
    n =n + 1;
    a[n-1] = Key;

    for (int i = (n / 2) - 1; i >= 0; i--)
    {
      maxheapify(a, n, i);
    }
}


void printArray(int a[], int n)
{

    for (int i = n-1; i>=0; i--)
        printf("%d\t", a[i]);
    printf("\n");
}


