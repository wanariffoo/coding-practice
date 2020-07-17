/*
1295. Find Numbers with Even Number of Digits
Easy

Given an array nums of integers, return how many of them contain an even number of digits.


Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.

Example 2:

Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


class Solution {
public:
    int findNumbers(vector<int>& nums) {
       
        int count_even = 0;

        // loop through each element
        for ( int i = 0 ; i < nums.size() ; i++ )
        {
            int count = 0;
            
            // count how many digits for each element
            for ( int n = nums[i] ; n > 0 ; n /= 10 )
                count++;

            // if digit is even, add to count_even
            if ( count % 2 == 0 )
                count_even++;

        }

        // return count_even
        return count_even;
    }
};

int main()
{

    vector<int> array = {555,901,482,1771};
    

    Solution sol;
    auto answer = sol.findNumbers(array);

    // output 
    cout << answer << endl;

}