// https://www.hackerrank.com/challenges/frequency-queries/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {

    vector<int> ans;

    // cout << queries[0][1] << endl;

    unordered_map<long, int> q_map;
    unordered_map<int, int> q_freq;


    for ( int i = 0 ; i < queries.size() ; i++ )
    {
        if ( queries[i][0] == 1 )
        {
            q_map[queries[i][1]]++;
            q_freq[q_map[queries[i][1]]]++; // add +1 frequency to the data
            q_freq[q_map[queries[i][1] - 1]]--; // minus -1 frequency to the old data

            if ( q_freq[q_map[queries[i][1] - 1]] < 0 ) // preventing it to getting to zero
                q_freq[q_map[queries[i][1] - 1]] = 0;
        }

        else if ( queries[i][0] == 2 )
        {
            q_map[queries[i][1]]--;
            q_freq[ q_map[queries[i][1]] ]--;
            q_freq[ q_map[queries[i][1]] + 1 ]++;

            if ( q_freq[q_map[queries[i][1] ]] < 0 ) // preventing it to getting to zero
                q_freq[q_map[queries[i][1] ]] = 0;

            if ( q_map[queries[i][1]] < 0 )
                q_map[queries[i][1]] = 0;

        }

        else // if queries[i][0] == 3
        {
            if ( q_freq.find(queries[i][1]) != q_freq.end() )
                ans.push_back(1);
            else
                ans.push_back(0);
            


            // for ( int j = 0 ; j < queries.size() ; j++ )
            // {
            //     if ( queries[i][1] == q_map[queries[j][1]] )
            //     {
            //         ans.push_back(1);
            //         j += queries.size(); // exit for loop
            //     }

            //     else if ( j == queries.size()-1 )
            //         ans.push_back(0);
            // }
        }
    }



    return ans;
}

int main()
{

    int q = 8;

    vector<vector<int>> queries;

    queries.resize(q);

    queries[0].push_back(1);
    queries[0].push_back(5);
    queries[1].push_back(1);
    queries[1].push_back(6);
    queries[2].push_back(3);
    queries[2].push_back(2);
    queries[3].push_back(1);
    queries[3].push_back(10);
    queries[4].push_back(1);
    queries[4].push_back(10);
    queries[5].push_back(1);
    queries[5].push_back(6);
    queries[6].push_back(2);
    queries[6].push_back(5);
    queries[7].push_back(3);
    queries[7].push_back(2);

    

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];

        if (i != ans.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

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
