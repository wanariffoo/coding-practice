// https://www.hackerrank.com/challenges/counting-valleys/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {

    int elev = 0;
    int last_elev;
    int valley = 0;

    for ( int i = 0 ; i < n ; i++ )
    {
        last_elev = elev;

        if ( s[i] == 'D' )
            elev--;
        else
            elev++;

        if ( last_elev == -1 && elev == 0 )
            valley++;
    }

    return valley;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
