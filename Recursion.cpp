// recursive factorial
int fact(int n) {
    if (n == 0) {
        return 1;
    }
    return fact(n - 1) * n;
}

// recursive power
int pow(int m, int n) {
    if (n == 0) {
        return 1;
    }
    return pow(m, n - 1) * m;
}

// recursive combination
int NCR(int n, int r) {
    if (n == r || r == 0) {
        return 1;
    }
    return NCR(n - 1, r - 1) + NCR(n - 1, r);
}

// recursive fibonacci
int F[a];
int fib(int n) {
    if (n <= 1) {
        F[n] = n;
        return n;
    }
    else {
        if (F[n - 2] == -1) {
            F[n - 2] = fib(n - 2);
        }
        if (F[n - 1] == -1) {
            F[n - 1] = fib(n - 2);
        }
        return F[n - 2] + F[n - 1];
    }
}

// recursive power of Hanoi
void TOH(int n, int A, int B, int C) {
    if (n > 0) {
        TOH(n - 1, A, C, B);
        cout << "A->C" << endl;
        TOH(n - 1, B, A, C);
    }
}