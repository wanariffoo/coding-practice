// https://www.hackerrank.com/challenges/staircase/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {

    for ( int i = 0 ; i < n ; i++ )
    {
        // number of spaces
        for ( int j = n - 1 - i; j > 0 ; j-- )
            cout << " "; // x = n - 2 - i

        // number of stairs
        for ( int k = 0; k < i + 1 ; k++ )
            cout << "#";  // x = n - 1 - i

        cout << endl;
    }

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
