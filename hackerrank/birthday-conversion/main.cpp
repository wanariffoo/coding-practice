// https://www.hackerrank.com/challenges/time-conversion/problem

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {

    // determine if it's AM or PM
    string ampm = s.substr(s.length() - 2);
    string output = s.substr(0,8);
    string s_hour = s.substr(0,2);

    int hour = stoi(s_hour);

    // if it's PM convert s[0] and s[1] to int
    if ( ampm == "PM" && hour != 12 )
    {
        // add 12
        hour = (hour + 12) % 24;

        // change output[0] and [1]
        stringstream ss;
        ss << hour;

        output[0] = ss.str()[0];
        output[1] = ss.str()[1];
    }
    
    // if it's midnight
    else if ( ampm == "AM" && hour == 12 )
    {
        output[0] = '0';
        output[1] = '0';
    }
    
    return output;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
