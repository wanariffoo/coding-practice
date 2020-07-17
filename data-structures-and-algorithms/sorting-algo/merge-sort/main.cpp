/*
    Merge sort
*/


#include <iostream>

using namespace std;

void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

void printArray(int* array, int size)
{
    for ( int i = 0 ; i < size ; i++ )
        cout << array[i] << " ";
    cout << endl;
}

void merge(int A[], int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            c[k] = A[i];
            k++;
            i++;
        }
        else
        {
            c[k] = A[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = A[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        A[i] = c[i];
    }
}

void mergeSort(int array[], int low, int high)
{
    if ( low < high ) 
    {
        int mid;

        mid = (low+high) / 2;

        mergeSort(array, low, mid);
        mergeSort(array, mid+1, high);

        merge(array, low, high, mid);
    }

    return;

}

int main()
{
    int n = 7;
    int array[n] = {38, 27, 43, 3, 19, 82, 10};

    // get the low and high indices
    int low = 0;
    int high = n-1;

    cout << "Before sorting : ";
    printArray(array, n);

    mergeSort(array, low, high);

    cout << "After sorting  : ";
    printArray(array, n);

}