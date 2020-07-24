// https://www.hackerrank.com/challenges/ctci-making-anagrams/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {

    int count[26] = {0};

    // traverse through a get frequency of all alphabets
    for ( auto c : a )
        count[ c - 'a']++;

    // for ( int i = 0 ; i < 26 ; i++ )
    //     cout << count[i] << " ";

    //     cout << endl;

    for ( auto c : b )
        count[ c - 'a']--;



    int sum = 0;

    // sum up the count
    for ( int i = 0 ; i < 26 ; i++ )
    {
        if ( count[i] != 0 ) sum += abs(count[i]);
    }

    return sum;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
