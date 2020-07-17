/*
    Linear search
*/

#include<iostream>

using namespace std;

// practicing binary search and quicksort


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

// returns -1 if x is not found
int linearSearch( int *A, int low, int high, int x )
{
    int size = high - low + 1;
    
    for ( int i = 0 ; i < size ; i++ )
    {
        if ( x == A[i] )
            return i;
    }

    return -1;
}


int main()
{

    int array[10] = {1,6,4,3,5,8,7,2,9,0};

    int low = 0;
    int high = 9;

    cout << "Before sort : ";
    printArray(array, 10);

    quickSort(array, low, high);

    cout << "After sort : ";
    printArray(array, 10);

    cout << linearSearch( array, low, high, 4) << endl;

    
}

    