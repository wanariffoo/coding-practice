/*
    Binary search
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
int binarySearch( int *A, int low, int high, int x )
{
    if ( low < high )
    {
        int mid = ( (high-low) / 2 ) + low;

        // if x == mid
        if ( x == A[mid])
            return mid;

        // if target x is smaller than the middle
        if ( x < A[mid] )
            return binarySearch( A, low, mid-1, x );

        else
            return binarySearch( A, mid+1, high, x );        
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

    cout << binarySearch( array, low, high, 11) << endl;

    
}

    