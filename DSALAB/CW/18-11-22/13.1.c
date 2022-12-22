/*WAP to sort a set of numbers in ascending order using insertion sort, bubble sort, selection sort, quick sort, and heap sort.*/
#include<stdio.h>
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printArray(arr, n);
}
void bubbleSort(int arr[], int n)
{       
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
    printArray(arr,n);
}
void selectionSort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        if (min != i)
            swap(&arr[min], &arr[i]);
    }
    printArray(arr,n);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
    printArray(arr,N);
}
int main()
{
    int size, choice; 
    printf("Enter size of array- ");
    scanf("%d",&size);
    int arr[size];
    for (int i=0;i<size;i++)
    {
        scanf("%d", &arr[i]);
    }
    menu:
        printf("\n1)Insertion sort\n2)Bubble sort\n3)Selection sort\n4)Quick sort\n5)Heap sort\n6)Exit.\n");
        printf("Enter your choice- ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: insertionSort(arr, size);
                goto menu;
        case 2: bubbleSort(arr, size);
                goto menu;
        case 3: selectionSort(arr, size);
                goto menu;
        case 4: quickSort(arr, 0, size - 1);
                printArray(arr,size);
                goto menu;
        case 5: heapSort(arr, size);
                goto menu;
        case 6: break;
    }
    return 0;
}