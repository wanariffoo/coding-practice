/*

1480. Running Sum of 1d Array
https://leetcode.com/problems/running-sum-of-1d-array/

Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.


Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].

Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]


*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


class Solution {
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        vector<int> ans;

        ans.push_back(nums[0]);

        for ( int i = 1 ; i < nums.size() ; i++ )
        {
            ans.push_back(nums[i] + ans[i-1]);
        }

        return ans;

    }
};

int main()
{
    vector<int> array = {3,1,2,10,1};

    Solution sol;
    auto answer = sol.runningSum(array);

    for ( vector<int>::iterator it = answer.begin() ; it != answer.end() ; it++ )
        cout << *it << " ";

    cout << endl;

}