/*
    Selection sort
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

void selectionSort(int *A, int n)  
{  
    int i, j, min_id;
  
    // One by one move boundary of unsorted subarray  
    for (int i = 0; i < n - 1 ; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_id = i;  

        for (int j = i + 1 ; j < n ; j++)
        {
            if (A[j] < A[min_id])  
                min_id = j;  
        }
  
        // Swap the found minimum element with the first element  
        swap(A[min_id], A[i]);  
    }  
}


int main()
{

    int n = 10;
    int array[10] = {3,5,4,7,6,8,7,6,5,4};

    // get the low and high indices
    int low = 0;
    int high = n-1;

    cout << "Before sorting : ";
    printArray(array, n);

    selectionSort(array, n);

    cout << "After sorting  : ";
    printArray(array, n);

}