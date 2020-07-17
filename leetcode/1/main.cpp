/*
1. Two Sum
https://leetcode.com/problems/two-sum/

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].


*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> indices;

        for ( int i = 0 ; i < nums.size() ; i++ )
        {
            for ( int j = i+1; j < nums.size() ; j++ )
            {
                if ( nums[i] + nums[j] == target )
                {
                    indices.push_back(i);
                    indices.push_back(j);
                }
            }
        }

        return indices;

    }
};


int main()
{
    vector<int> array = { 2, 7, 11, 15 };
    int target = 9;

    Solution x;
    vector<int> answer = x.twoSum( array, target );

    for ( vector<int>::iterator it = answer.begin() ; it != answer.end() ; it++ )
        cout << *it << endl;
}
