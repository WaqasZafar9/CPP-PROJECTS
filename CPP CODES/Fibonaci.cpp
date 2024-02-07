#include <iostream>
using namespace std;

int fib(int n, int dp[]) {
    if (n <= 1) {
        return n;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    int dp[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = -1;
    }

    cout << "Fibonacci series up to " << n << ": ";
    for (int i = 0; i <= n; i++) {
        cout << fib(i, dp) << " ";
    }
    cout << endl;

    return 0;
}
