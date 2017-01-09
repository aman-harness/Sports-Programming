struct Matrix {
	Matrix() {a[0][0] = a[1][1] = a[0][1] = a[1][0] = 0;}
	long long a[2][2];
};

Matrix operator *(const Matrix &A, const Matrix &B) {
	Matrix C;
	C.a[0][0] = C.a[0][1] = C.a[1][0] = C.a[1][1] = 0;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				C.a[i][j] += A.a[i][k] * B.a[k][j], C.a[i][j] %= MOD;
	return C;
}

long long pow(long long A, long long p) {
	long long C = 1;
	while (p) {
		if (p & 1)
			C = (C * A) % MOD;
		A = (A * A) % MOD;
		p >>= 1;
	}
	return C;
}

Matrix pow(Matrix A, long long p) {
	Matrix C;
	C.a[0][0] = C.a[1][1] = 1;
	while (p) {
		if (p & 1)
			C = C * A;
		A = A * A;
		p >>= 1;
	}
	return C;
}
