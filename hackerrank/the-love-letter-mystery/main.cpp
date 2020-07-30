// 

#include <bits/stdc++.h>

using namespace std;

// Complete the theLoveLetterMystery function below.
int theLoveLetterMystery(string s) {

    // check each char with the one on the opposite side
    // if not the same, find the difference int diff = abs(s[] - s[])

    int count = 0;
    int n = s.length();

    for ( int i = 0 ; i < n/2 ; i++ )
    {
        if ( s[i] != s[n-1-i] )
        {
            int diff = abs(s[i] - s[n-1-i] );
            count += diff;
        }
    }

    return count;

}

int main()
{

    // string s = "abc";
    // string s = "abcba";
    // string s = "abcd";
    string s = "cba";



    int result = theLoveLetterMystery(s);

    cout << result << "\n";


    return 0;
}
