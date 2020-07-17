/*

1431. Kids With the Greatest Number of Candies
https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

Given the array candies and the integer extraCandies, where candies[i] represents the number of candies that the ith kid has.

For each kid check if there is a way to distribute extraCandies among the kids such that he or she can have the greatest number of candies among them. Notice that multiple kids can have the greatest number of candies.

Example 1

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 


Example 2

Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<bool> ans;

        // getting the max value in the array
        int max = *max_element(candies.begin(), candies.end());

        for ( int i = 0 ; i < candies.size() ; i++ )
        {
            if ( candies[i] + extraCandies >= max )
                ans.push_back(true);

            else
                ans.push_back(false);
        }

        return ans;
    }
};

int main()
{
    vector<int> array = {2,3,5,1,3};
    int n = 3;


    Solution sol;
    auto answer = sol.kidsWithCandies(array, n);



    // output 
    for ( vector<bool>::iterator it = answer.begin() ; it != answer.end() ; it++ )
        cout << *it << " ";

    cout << endl;

}