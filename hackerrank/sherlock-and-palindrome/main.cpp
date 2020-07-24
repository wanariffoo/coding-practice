// self-created
// similar to this below, but with palindrome
// https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem

#include <bits/stdc++.h>
#include <string>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndPalindromes(string s) {

    int n = s.length();    
    int count = 0;

    for ( int len = 1 ; len < n ; len++ )
    {
        for ( int i = 0 ; i + len - 1 < n ; i++ )
        {
            string s1 = s.substr(i,len);

            for ( int j = 0 ; j + i + len < n ; j++ )
            {
                string s2;

                for ( int k = 0 ; k < len ; k++ )
                    s2 += s[n-k-j-1];


                if ( s1 == s2 )
                    count++;
            }
        }
    }    
    

    return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s = "cdcd";
    // string s = "ifailuhkqq";
    cout << s << endl;

    int result = sherlockAndPalindromes(s);

    cout << result << "\n";


    return 0;
}
