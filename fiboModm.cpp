#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> Matrix;

// Matrix multiplication with modulo
Matrix multiply(const Matrix& A, const Matrix& B, long long m) {
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

// Fibonacci calculation using matrix exponentiation
long long fibonacci(long long n, long long m) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    Matrix M = {{1, 1}, {1, 0}};
    M = power(M, n - 1, m);
    return M[0][0];
}

int main() {
    long long n, m;
    cin >> n >> m;
    cout << "F(" << n << ") % " << m << " = " << fibonacci(n, m) << endl;
    return 0;
}
