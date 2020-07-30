// https://www.hackerrank.com/challenges/special-palindrome-again/problem

/*

    Condition 1 : all characters are the same, e.g., "aaaaaaaaaa"
    Condition 2 : all characters are the same expect the one in the middle, e.g. "aabaa"
*/

#include <bits/stdc++.h>

using namespace std;


bool isPalindrome(string s)
{   
    for ( int i = 0 ; i < s.length() / 2 ; i++ )
    {
        if ( s[i] != s[s.length()-i-1 ] )
            return false;
    }

    return true;
}


bool isSpecial(string s)
{   
    char foo = s[0];
    for ( int i = 0 ; i < s.length() / 2 ; i++ )
    {
        if ( s[i] != foo || s[s.length()-i-1 ] != foo )
            return false;
        // if ( s[i] != s[s.length()-i-1 ] || s[i] != foo || s[s.length()-i-1 ] != foo )
    }

    return true;
}


// Complete the substrCount function below.
long substrCount(int n, string s) {

    // count of the length is already initially added
    long ans = s.length();

    // 
    string temp;

    int cond2_count = 0;
    // checking Condition 2
    for ( int i = 1 ; i < s.length() - 1 ; i++ )
    {
        for ( int j = 1 ; s[i-j] == s[i+j] && i >= j ; j++ )
            cond2_count++;

    }

    cout << cond2_count << endl;

    return ans;



    // NOTE: below works but not optimal

    // long ans = 0;
    // string temp;

    // for ( int len = 1; len < n + 1; len++)
    // {
    //     for ( int i = 0 ; i < s.length() + 1 - len ; i++ )
    //     {
    //         temp = s.substr(i,len);
    //         if ( isSpecial(temp) ) 
    //         {
    //             ans++;
    //             cout << temp << endl;
    //         }
    //     }
    // }

    // return ans;
}

int main()
{
    int n = 5;
    string s = "asasa";
    // int n = 7;
    // string s = "abcbaba";
    // int n = 4;
    // string s = "aaaa";

    long result = substrCount(n, s);

    cout << result << "\n";

    // string s = "assa";
    // cout << isPalindrome(s) << "\n";

    return 0;
}
