// Ensure gcc is installed in your system
// Just run gcc <fillename>
// then run ./a.out


#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

// Multiply 2x2 matrices under modulo
vector<vector<long long>> multiply(const vector<vector<long long>> &A, const vector<vector<long long>> &B) {
    vector<vector<long long>> C(2, vector<long long>(2));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            C[i][j] = (A[i][0] * B[0][j] % MOD + A[i][1] * B[1][j] % MOD) % MOD;
    return C;
}

vector<vector<long long>> matrix_pow(vector<vector<long long>> M, long long power) {
    vector<vector<long long>> result = {{1, 0}, {0, 1}};
    while (power > 0) {
        if (power % 2 == 1) result = multiply(result, M);
        M = multiply(M, M);
        power /= 2;
    }
    return result;
}
// Returns the n-th Fibonacci number modulo MOD
long long fibonacci(long long n) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n == 1) return 1;
    vector<vector<long long>> F = {{1, 1}, {1, 0}};
    F = matrix_pow(F, n - 1);
    return F[0][0];
}
int main() {
    long long n;
    cout << "Enter n: ";
    if (!(cin >> n)) {
        cout << "Invalid input!\n";
        return 0;
    }
    if (n < 0) {
        cout << "n must be non-negative.\n";
        return 0;
    }
    cout << "Fibonacci(" << n << ") modulo " << MOD << " = " << fibonacci(n) << "\n";
    return 0;
}
