/*
Implement wildcard pattern matching with support for '?' and '*' for strings A and B.
'?' : Matches any single character.
'*' : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
   public:
    bool isMatch(string A, string B) {
        int n = A.size();
        int m = B.size();

        if (n == 0)
            return (m == 0);

        if (n == 1 && m == 1 && B[0] == '?')
            return 1;

        //to remove consecutive *
        string temp = "";
        temp += B[0];
        for (int i = 1; i < m; i++) {
            if (B[i - 1] == '*' && B[i] == '*')
                continue;
            else
                temp += B[i];
        }

        m = temp.length();
        B = temp;

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        // bool dp[n+1][m+1];
        // memset(dp,false,sizeof(dp));
        dp[0][0] = true;

        for (int i = 1; i <= m; i++)
            if (B[i - 1] == '*')
                dp[0][i] = dp[0][i - 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (A[i - 1] == B[j - 1] || B[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (B[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};

/*
Regular Expression II
Implement regular expression matching with support for '.' and '*'. '.' Matches any single character. '*' Matches zero or more of the preceding element. The matching should cover the entire input string (not partial).
*/

int isMatch(const string s, const string p) {
    int n = s.length();
    int m = p.length();

    bool dp[n + 1][m + 1];
    /*
        dp[i][j]:=does s[0.....i] match with p[0.....j]
    */
    memset(dp, false, sizeof dp);
    dp[0][0] = true;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*') {        //p=abcd* dekhna hai?
                dp[i][j] = dp[i][j - 2];       //p=abc match tha kya
                if (s[i - 1] == p[j - 2])      //s=abc p=abc*
                    dp[i][j] |= dp[i - 1][j];  //s=ab p=abc* matched char ko hata //ke math tha kya
            } else
                dp[i][j] = false;
        }
    }

    return dp[n][m];
}
