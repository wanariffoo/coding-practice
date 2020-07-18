// https://www.hackerrank.com/challenges/repeated-string/problem


/*
    input:
    epsxyyflvrrrxzvnoenvpegvuonodjoxfwdmcvwctmekpsnamchznsoxaklzjgrqruyzavshfbmuhdwwmpbkwcuomqhiyvuztwvq

    549382313570

    expected output : 16481469408
*/


#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {

    long counter = 0;
   

    // cout << n / s.length() * 3 << endl;
    // cout << count(s.begin(), s.end(), 'a' ) << endl;

    long multiply = n / s.length();

    // ( count the a's in the string * n ) 
    counter += ( count( s.begin(), s.end(), 'a' ) * multiply );

    // (count a in the remaining sub-string)
    // remaining numbers
    int remaining = n % s.length();
    // cout << "first = " << first * n  << endl;
    cout << "remaining = " << remaining << endl;
    // cout << "n = " << first*n + remaining << endl;

    
    counter += count( s.begin(), s.begin() + remaining, 'a' );

    return counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s = "epsxyyflvrrrxzvnoenvpegvuonodjoxfwdmcvwctmekpsnamchznsoxaklzjgrqruyzavshfbmuhdwwmpbkwcuomqhiyvuztwvq";

    // getline(cin, s);

    long n = 549382313570;
    // cin >> n;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    cout << result << "\n";
    fout << result << "\n";

    fout.close();

    return 0;
}
