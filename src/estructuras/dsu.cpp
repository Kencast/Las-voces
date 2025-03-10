/**
 * Disjoin Set Union/Union Find: Para unir componentes
 * Complejidad: Amortizado O(1), sino O(log(n))
 * Probado: No
 */

struct DSU {
	vector<int> p, r;
	int n;

	DSU(int n) : n(n), p(n), r(n) {
		iota(all(p), 0);
	}

	int find(int a) {
		return p[a] == a ? a : (p[a] = find(p[a]));
	}

	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return 0;
		if (r[a] < r[b]) swap(a, b);
		p[b] = a;
		if (r[a] == r[b]) ++r[a];
		return 1;
	}
};
