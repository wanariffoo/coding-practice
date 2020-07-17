/*

217. Contains Duplicate
https://leetcode.com/problems/contains-duplicate/

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true

Example 2:

Input: [1,2,3,4]
Output: false

Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        // sort vector
        sort(nums.begin(), nums.end());

        for ( int i = 1 ; i < nums.size() ; i++ )        
        {
            if ( nums[i] == nums[i-1] )   
                return false;
        }


        return true;
    }

    bool containsDuplicate_2(vector<int>& nums)
    {
        
        for ( int i = 0 ; i < nums.size() ; i++ )
        {
            for ( int j = i+1; j < nums.size() ; j++ )
            {
                if ( nums[i] == nums[j] )
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<int> array = {1,2,3,1};

    Solution sol;
    cout << sol.containsDuplicate( array ) << endl;

}