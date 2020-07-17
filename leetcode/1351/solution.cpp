/*

1351. Count Negative Numbers in a Sorted Matrix
Easy

Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 

Return the number of negative numbers in grid.

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int count = 0;

        // get negative numbers in each row
        for ( int i = 0 ; i < grid.size() ; i++ )
        {
            for ( int j = 0 ; j < grid[i].size() ; j++ )
            {
                if ( grid[i][j] < 0 )
                    count++;
            }
        }
        
        return count;

    }
};

int main()
{

    vector<vector<int>> grid = {
        {4,3,2,-1},
        {3,2,1,-1},
        {1,1,-1,-2},
        {-1,-1,-2,-3}
        };
    

    Solution sol;
    auto answer = sol.countNegatives(grid);

    // output 
    cout << answer << endl;

}