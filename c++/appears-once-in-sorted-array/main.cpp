/*

source: https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array/0

Find the element that appears once in sorted array 

Given a sorted array A, size N, of integers; every element appears twice except for one. Find that element that appears once in array.

Input:
The first line of input consists of T, the number of the test cases. T testcases follow. Each testcase contains two lines of input.
The first line of each test case contains the size of the array, and the second line has the elements of the array.

Output:
For each testcase, in a new line, print the number that appears only once in the array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 ≤ A[i] ≤ 1017

Example:
Input:
1
11
1 1 2 2 3 3 4 50 50 65 65
Output:
4

*/

#include <iostream>
#include <vector>


using namespace std;

// Finds the element that appears only once in a sorted array
template<typename T>
T findOneElement (vector<T> array)
{
    T temp = array[0];

    for (int i = 1; i < array.size() - 1; ++i)
    {
        if ( array[i] != array[i-1] && array[i] != array[i+1])
            return array[i];
    }

    // if the for loop cannot find the only-once, it would be the first or last component of the array
    if( array[0] != array[1] )
        return array.front();
    
    else
        return array.back(); 
}


int main()
{

    int T;              // number of test cases
    int N;              // size of array
    vector<int> A;      // array

    cout << "Input:" << endl;
    cin >> T;
    cin >> N;

    if ( T == 0 || T > 107 || N == 0 || N > 107)
    {
        cout << "Error" << endl;
        return 1;
    }

    A.resize(N);

    for ( int i = 0 ; i < N ; ++i )
        cin >> A[i];

    cout << "Output:" << endl;
    cout << findOneElement(A) << endl;


}
