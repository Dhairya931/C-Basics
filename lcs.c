#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void printLCS(char *X, char *Y, int m, int n, int dp[m + 1][n + 1]) {
    int index = dp[m][n];
    char lcs[index + 1];
    lcs[index] = '\0'; // Null-terminate the LCS string

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Longest Common Subsequence: %s\n", lcs);
}

int lcs(char *X, char *Y, int m, int n) {
    int dp[m + 1][n + 1];

    // Build the DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Print the LCS
    printLCS(X, Y, m, n, dp);

    return dp[m][n];
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    int result = lcs(X, Y, m, n);

    printf("Length of Longest Common Subsequence: %d\n", result);

    return 0;
}
