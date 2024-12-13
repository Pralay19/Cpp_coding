// n<10^10000
// For this kind of situation we will use Pisano Period
//Using Pisano period we will convert n to n % pi(m);
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> Matrix;

// Matrix multiplication with modulo
Matrix multiply(const Matrix &A, const Matrix &B, long long m) {
    int n = A.size();
    Matrix C(n, vector<long long>(n, 0)); // Initialize C with zeroes
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % m;
            }
        }
    }
    return C;
}

// Matrix exponentiation with modulo
Matrix power(Matrix M, long long n, long long m) {
    int size = M.size();
    Matrix result(size, vector<long long>(size, 0));

    // Initialize result as the identity matrix
    for (int i = 0; i < size; i++) {
        result[i][i] = 1;
    }

    while (n > 0) {
        if (n % 2 == 1) {
            result = multiply(result, M, m);
        }
        M = multiply(M, M, m);
        n /= 2;
    }
    return result;
}

// Calculate the Pisano period for a given m
long long getPisanoPeriod(long long m) {
    long long prev = 0, curr = 1, next;
    for (long long i = 0; i < m * m; i++) {
        next = (prev + curr) % m;
        prev = curr;
        curr = next;
        // Pisano period starts repeating with 0, 1
        if (prev == 0 && curr == 1) {
            return i + 1;
        }
    }
    return m * m; // Fallback, should never happen in a correct implementation
}

// Compute the n-th Fibonacci number modulo m using reduced n from Pisano period
long long fibonacci_large(const string &n, long long m) {
    if (n == "0") return 0;
    if (n == "1") return 1;

    // Get Pisano period for m
    long long pisano_period = getPisanoPeriod(m);
    

    // Reduce n modulo Pisano period
    long long reduced_n = 0;
    for (char digit : n) {
        reduced_n = (reduced_n * 10 + (digit - '0')) % pisano_period;
    }

    // Matrix exponentiation to get the Fibonacci number
    Matrix M = {{1, 1}, {1, 0}};
    if (reduced_n == 0) return 0;
    if (reduced_n == 1) return 1;
    M = power(M, reduced_n - 1, m);
    return M[0][0];
}

int main() {
    string n; // We'll use a string to handle large n
    long long m;
    cin >> n;
    cin >> m;

    cout << "F(" << n << ") % " << m << " = " << fibonacci_large(n, m) << endl;

    return 0;
}
