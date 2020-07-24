// https://www.hackerrank.com/challenges/alternating-characters/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {

    int count = 0;
    char foo = s[0];

    // traverse the string, if the next character is the same, count++ and move to i++
    for ( int i = 1 ; i < s.length() ; i++ )
    {
        if ( s[i] == foo )
            count++;
        
        else
            foo = s[i];
    }

    return count;

}

int main()
{
    // string s = "BBBBB";
    string s = "ABABABAB";
    // string s = "BABABA";
    // string s = "AAABBB";

    


    int result = alternatingCharacters(s);

    cout << result << "\n";

    return 0;
}
