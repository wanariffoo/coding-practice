/*

1389. Create Target Array in the Given Order
https://leetcode.com/problems/create-target-array-in-the-given-order/

Given two arrays of integers nums and index. Your task is to create target array under the following rules:

   * Initially target array is empty.
   * From left to right read nums[i] and index[i], insert at index index[i] the value nums[i] in target array.
   * Repeat the previous step until there are no elements to read in nums and index.

Return the target array.

It is guaranteed that the insertion operations will be valid.

Example 1:

Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
Output: [0,4,1,3,2]
Explanation:
nums       index     target
0            0        [0]
1            1        [0,1]
2            2        [0,1,2]
3            2        [0,1,3,2]
4            1        [0,4,1,3,2]

Example 2:

Input: nums = [1,2,3,4,0], index = [0,1,2,3,0]
Output: [0,1,2,3,4]
Explanation:
nums       index     target
1            0        [1]
2            1        [1,2]
3            2        [1,2,3]
4            3        [1,2,3,4]
0            0        [0,1,2,3,4]

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index)
    {
        // create empty array
        vector<int> array;

        // insert at index[i] the value nums[i]
        for ( int i = 0 ; i < nums.size() ; i++ )
            array.insert ( array.begin() + index[i], nums[i] );
        
        // return arry
        return array;
    }
};

int main()
{

    vector<int> nums = {1,2,3,4,0};
    vector<int> index = {0,1,2,3,0};

    Solution sol;
    auto answer = sol.createTargetArray(nums, index);

    // output 
    for ( int i = 0 ; i < answer.size() ; i++ )
        cout << answer[i] << " ";
        
    cout << endl;

}