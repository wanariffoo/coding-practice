/*
Given an array,find the maximum j – i such that arr[j] > arr[i]
*/

#include <iostream>
#include <vector>

int maxDifference(std::vector<int> array)
{
    int max = 0;

    for ( int i = 0 ; i < array.size() ; i++ )
    {
        for ( int j = i+1 ; j < array.size() ; j++ )
        {
            if ( max < array[j] - array[i] && array[j] > array[i] )
                max = array[j] - array[i];
        }
    }
    return max;
}

int main()
{

    int N;

    std::cout << "Enter size of array : ";
    std::cin >> N;

    std::vector<int> arr(N);

    std::cout << "Key in numbers in the array ..." << std::endl;

    for ( int i = 0 ; i < arr.size() ; i++ )
        std::cin >> arr[i];

    std::cout << "Max difference = " << maxDifference(arr) << std::endl;

}