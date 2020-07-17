/*
    Bubble sort
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

void bubbleSort(int *array, int size)
{
        for ( int i = 0 ; i < size ; i++ )
        {
            for ( int j = i + 1; j < size ; j++ )
            {
                if ( array[i] > array[j] )
                    swap( array[i], array[j] );
            }
        }
}

int main()
{
    int n = 10;
    int array[n] = {3,6,5,4,7,8,9,0,1,5};

    cout << "Before sorting : ";
    printArray(array, n);

    bubbleSort(array, n);

    cout << "After sorting  : ";
    printArray(array, n);

}