// https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem

#include <bits/stdc++.h>
#include <string>

using namespace std;

bool checkAnagram(string s1, string s2)
{
    int arr[26] = {0};

    for ( int i = 0 ; i < s1.length() ; i++ )
        arr[ s1[i] - 'a' ]++;

    for ( int i = 0 ; i < s2.length() ; i++ )
        arr[ s2[i] - 'a' ]--;

    for ( int i = 0 ; i < 26 ; i++ )
    {
        if ( arr[i] != 0 )   
            return false;
    }

    return true;
}


// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {

    int n = s.length();    
    int count = 0;


    for ( int len = 1 ; len < n ; len++ )
    {
        for ( int i = 0 ; i + len - 1 < n ; i++ )
        {
            string s1 = s.substr(i,len);

            for ( int j = i+1 ; j + (len-1) < n ; j++ )
            {
                string s2 = s.substr(j,len);

                if ( checkAnagram(s1,s2) )
                    count++;
                
            }
        }
    }    


    return count;

}

int main()
{

    string s = "cdcd";

    // string s = "ifailuhkqq";
    cout << s << endl;

    int result = sherlockAndAnagrams(s);

    cout << result << "\n";


    return 0;
}
