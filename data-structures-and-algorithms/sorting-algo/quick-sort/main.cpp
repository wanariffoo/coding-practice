/*
    Quick sort
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


int partition( int *A, int low, int high )
{
    // define pivot, taking the end element
    int pivot = A[high];
    int pIndex = low;

    for ( int i = low ; i < high ; i++ )
    {
        if ( A[i] <= pivot )
        {
            swap( A[i], A[pIndex] );
            pIndex++;
        }
    }

    // set pivot to be at pIndex
    swap( A[pIndex], A[high] );

    return pIndex;
}


void quickSort(int *A, int low, int high)
{
    // return if number of elements in the sub-array is 1
    if ( low < high )
    {
        // partition
        int pIndex = partition( A, low, high );

        // quicksort LHS
        quickSort( A, low, pIndex - 1);

        // quicksort RHS
        quickSort( A, pIndex + 1, high );

    }

    return;
}



int main()
{
    // int n = 7;
    // int array[n] = {38, 27, 43, 3, 19, 82, 10};

    int n = 10;
    int array[10] = {3,5,4,7,6,8,7,6,5,4};

    // get the low and high indices
    int low = 0;
    int high = n-1;

    cout << "Before sorting : ";
    printArray(array, n);

    quickSort(array, low, high);

    cout << "After sorting  : ";
    printArray(array, n);

}