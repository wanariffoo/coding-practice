// https://www.hackerrank.com/challenges/30-review-loop/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<string> s;

    for ( int i = 0 ; i < n ; i++ )
    {
        string temp;
        cin >> temp;
        s.push_back(temp);

        string s1;
        string s2;

        for ( int j = 0 ; j < s[i].length() ; j++ )
        {
            // if even
            if ( j % 2 == 0 )
                s1 += s[i][j];
            else
                s2 += s[i][j];    
        }



        cout << s1 << " " << s2 << endl;
    }

    return 0;
}


