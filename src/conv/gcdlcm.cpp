/**
 * GCD/LCM convolution
 * https://codeforces.com/blog/entry/119082
 * Todo O(nlogn)
 * MultipleZetaTransform se puede utilizar para contar la cantidad de cada divisor
 * PrimeEnumerate provee todos los primos de interes
 */

template<typename T>
void DivisorZetaTransform(vector<T>& v) {
	const int n = (int)v.size() - 1;
	for (int p : PrimeEnumerate(n)) {
		for (int i = 1; i * p <= n; i++)
			v[i * p] += v[i];
	}
}

template<typename T>
void DivisorMobiusTransform(vector<T>& v) {
	const int n = (int)v.size() - 1;
	for (int p : PrimeEnumerate(n)) {
		for (int i = n / p; i; i--)
			v[i * p] -= v[i];
	}
}

template<typename T>
void MultipleZetaTransform(vector<T>& v) {
	const int n = (int)v.size() - 1;
	for (int p : PrimeEnumerate(n)) {
		for (int i = n / p; i; i--)
			v[i] += v[i * p];
	}
}

template<typename T>
void MultipleMobiusTransform(vector<T>& v) {
	const int n = (int)v.size() - 1;
	for (int p : PrimeEnumerate(n)) {
		for (int i = 1; i * p <= n; i++)
			v[i] -= v[i * p];
	}
}

template<typename T>
vector<T> GCDConvolution(vector<T> A, vector<T> B) {
    MultipleZetaTransform(A);
    MultipleZetaTransform(B);
    for (int i = 0; i < A.size(); i++) A[i] *= B[i];
    MultipleMobiusTransform(A);
    return A;
}

template<typename T>
vector<T> LCMConvolution(vector<T> A, vector<T> B) {
    DivisorZetaTransform(A);
    DivisorZetaTransform(B);
    for (int i = 0; i < A.size(); i++) A[i] *= B[i];
    DivisorMobiusTransform(A);
    return A;
}
