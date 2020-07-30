// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/

/*

Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".

*/
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    string freqAlphabets(string s) {
        
        // is s[i+2] == '#'?
        // if yes, it's between j and z
        // if no, it's between a and i
        
        // get difference between a and j
        int atoj = 'j' - 'a';

        string ans = "";
        
        for ( int i = 0 ; i < s.length() ; i++ )
        {
            if ( i+2<s.length() && s[i+2] == '#' )
            {
                int temp = stoi(&s[i]);

                // converting to int
                ans += (temp+96);
                i += 2;
            }

            else
            {
                int temp = s[i];
                // cout << temp << endl;
                ans += (temp + 48);
            }
        }
        
        
        // cout << test << endl;
        
        
        return ans;
        
        

        // string ans="";
        // for(int i=0;i<s.length();) {
        //     if(i+2<s.length() && s[i+2]=='#') {
        //         int ss=(s[i]-'0')*10+(s[i+1]-'0');
        //         ans+=char(ss+'a'-1);
        //         i+=3;
        //     }
        //     else {
        //         ans+=char(s[i]-'0'-1+'a');
        //         ++i;
        //     }
        // }
        // return ans;
        
    }
};

int main()
{

    // string s = "10#11#12";
    string s = "21#523#12#22#611#71910#721#18#8";

    Solution sol;
    auto answer = sol.freqAlphabets(s);

    // output 
    cout << answer << endl;

}