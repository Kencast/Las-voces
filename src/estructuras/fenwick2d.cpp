/**
 * Fenwick 2D
 * Cpalgorithms
 * Consulta y actualizacion en O(log^2(n))
 * Actualizaciones en punto
 * Consultas sobre rectangulos prefijos
 * Indexado en 0, consultas [0, r_i)
 */

struct FenwickTree2D {
	vector<vector<int>> bit;
	int n, m;

	FenwickTree2D(int n, int m) : n(n), m(m), bit(n, vector<int>(m)) {}

	// Consultar suma sobre [0, x) y [0, y)
	int get(int x, int y) {
		int ret = 0;
		for (; x > 0; x |= x - 1)
		for (; y > 0; y &= y - 1)
			ret += bit[x - 1][y - 1];
		return ret;
	}

	void add(int x, int y, int delta) {
		for (int i = x; i < n; i |= i + 1)
		for (int j = y; j < m; j |= j + 1)
			bit[i][j] += delta;
	}
};
