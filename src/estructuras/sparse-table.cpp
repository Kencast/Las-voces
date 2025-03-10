/**
 * Min Sparse Table
 * O(nlogn) construccion y O(1) consulta
 * MAXN corresponde al maximo y MAXN2 = floor(log2(MAXN))
 */

namespace sparse {
	int m[MAXN2 + 1][MAXN], n;
	void build(int n2, int *v) {
		n = n2;
		for (int i = 0; i < n; i++) m[0][i] = v[i];
		for (int j = 1; (1 << j) <= n; j++)
		for (int i = 0; i + (1 << j) <= n; i++)
		m[j][i] = min(m[j - 1][i], m[j - 1][i + (1 << (j - 1))]);
	}
	// [l, r]
	int query(int l, int r) {
		int j = bit_width(unsigned(r - l + 1));
		return min(m[j][l], m[j][r - (1 << j) + 1]);
	}
}
