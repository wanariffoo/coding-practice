/*
709. To Lower Case
https://leetcode.com/problems/to-lower-case/
Easy

Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
 

Example 1:

Input: "Hello"
Output: "hello"

Example 2:

Input: "here"
Output: "here"

Example 3:

Input: "LOVELY"
Output: "lovely"


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;


class Solution {
public:
    string toLowerCase(string str) {
        
        string lower;
        
        // get difference of lower and upper case
        int diff = 'a' - 'A';
        
        // if char is upper case, add diff
                
        // NOTE: two solutions
    
        // for ( int i = 0 ; i < str.length() ; i++ )
        // {
        //     char foo = str[i];
        //     if ( foo >= 'A' && foo <= 'Z' )
        //         lower += (foo + diff);
        //     else
        //         lower += foo;
        // }
        
        
        for ( char c : str )
        {
            if ( c >= 'A' && c <= 'Z')
                lower += (c+diff);
            else
                lower += (c);
        }
        
        return lower;
    }
};

int main()
{
    string str = "Hello";

    Solution sol;
    auto answer = sol.toLowerCase(str);

    // output 
    cout << answer << endl;

}