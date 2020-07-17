/*

1470. Shuffle the Array
https://leetcode.com/problems/shuffle-the-array/

Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].

 

Example 1:

Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7] 
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].

Example 2:

Input: nums = [1,2,3,4,4,3,2,1], n = 4
Output: [1,4,2,3,3,2,4,1]



*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) 
    {
        vector<int> ans;

        for ( int i = 0 ; i < n ; i++ )
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[i+n]);
        }

        return ans;
    }
};

int main()
{
    vector<int> array = {1,2,3,4,4,3,2,1};
    int n = 4;


    Solution sol;
    auto answer = sol.shuffle(array, n);



    // output 
    for ( vector<int>::iterator it = answer.begin() ; it != answer.end() ; it++ )
        cout << *it << " ";

    cout << endl;

}