// https://www.hackerrank.com/challenges/count-triplets-1/problem

/*

SOLUTION:

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {

    std::map<int, long> mp1, mp2;

    long iTripet = 0;
    for(int i = 0; i < arr.size(); ++i) {
        if ( mp2.find(arr[i]) != mp2.end() ) {
            iTripet += mp2[arr[i]];
        }
        if ( mp1.find(arr[i]) != mp1.end() ) {
            mp2[arr[i] * r] += mp1[arr[i]];
        }
        mp1[arr[i] * r]++;
    }

    return iTripet;

}

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {

    long count = 0;

    unordered_map<long, int> left_map;
    unordered_map<long, int> right_map;

    // filling in the right map with each element's count
    for ( int i = 2 ; i < arr.size() ; i++ )
        right_map[arr[i]]++;

    // filling in the first element in the left map
        left_map[arr[0]]++;


    // traverse through the array
    // evaluate the left side's a/r, and right side's a*r
    // if these two exist in the left and right maps, add count += (frequency of LHS * frequency of RHS)
    // update the frequency of the left and right map in each element
    for ( int i = 1 ; i < arr.size()-1 ; i++ )
    {
        int left_count = 0;
        int right_count = 0;
               
        // check if LHS exists
        if ( left_map.find(arr[i]/r) != left_map.end() )
            left_count = left_map[arr[i]/r];

        // check if RHS exists    
        if ( right_map.find(arr[i]*r) != right_map.end() )
            right_count = right_map[arr[i]*r];

        // cout << left_count << " " << right_count << endl;

        // add to count
        count += (left_count * right_count);
        // cout << "count: " << count << " " << left_count << "," << right_count << endl;

        // update frequency of left- and right-maps
        left_map[arr[i]]++;
        right_map[arr[i]]--;

    }

    return count;
}

int main()
{

    int n = 10000;

    long r = 1;

    // vector<long> arr = {1, 5, 5, 25, 125};
    // vector<long> arr = {1,3,9,9,27,81};
    vector<long> arr(n,1237);

    long ans = countTriplets(arr, r);

    cout << "ans = " << ans << "\n";


    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
