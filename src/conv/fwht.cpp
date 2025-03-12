/**
 * FWHT : Fast Walsh Hadamart Transform
 * Computes XOR, |, and & convolutions 
 *     or rather, their specific transforms/inverse transforms
 * O(nlongn)
 * n must be a power of 2
 */
template<char op, class T> vector<T> FWHT(vector<T> f, bool inv = false) {
	int n = f.size();
	for (int k = 0; (n-1)>>k; k++) for (int i = 0; i < n; i++) if (i>>k&1) {
		int j = i^(1<<k);
		if (op == '^') f[j] += f[i], f[i] = f[j] - 2*f[i];
		if (op == '|') f[i] += (inv ? -1 : 1) * f[j];
		if (op == '&') f[j] += (inv ? -1 : 1) * f[i];
	}
	if (op == '^' && inv) for (auto& i : f) i /= n;
	return f;
}
