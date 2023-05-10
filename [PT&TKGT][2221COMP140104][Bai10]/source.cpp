#include <iostream>
using namespace std;

string longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string result;
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            result = text1[i - 1] + result;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return result;
}

int main() {
    string text1 = "ABCDAF";
    string text2 = "ACBCF";
    string lcs = longestCommonSubsequence(text1, text2);

    cout << "Chuoi chung dai nhat: " << lcs << endl;

    return 0;
}