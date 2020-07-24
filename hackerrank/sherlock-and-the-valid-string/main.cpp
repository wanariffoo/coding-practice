// https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {

    // create an array to count the frequency of each alphabet

    // get difference between m and n
        // m : number of times for all alphabets
        // n : odd one
    // if abs(m-n) > 1, cout "NO", else "YES"


    // create an array to count the frequency of each alphabet
    int freq[26] = {0};

    for ( auto c : s )
        freq[ c-'a' ]++;

    // get difference between m and n
    int foo = 0;
    int count = 0;

    for ( int i = 0 ; i < 26 ; i++ )
    {
        if ( freq[i] != 0 && foo == 0 ) // fill in initially
        {
            foo = freq[i];
        }
        
        else if ( freq[i] != 0 && foo != 0 && count == 0) // one permitted
        {
            // cout << "second" << endl;
            if ( abs( foo - freq[i] ) >= 1 ) count++;
        }

        else if ( freq[i] != 0 && foo != 0 && count != 0)
        {
            if ( abs( foo - freq[i] ) >= 1 ) return "NO";
        }

    }


    // for ( int i : freq )
    //     cout << i << " ";

    //     cout << endl;





    return "YES";


}

int main()
{

    string s = "aabbccddeefghi";

    string result = isValid(s);

    cout << result << "\n";


    return 0;
}
