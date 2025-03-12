/**
 * Kruskal
 * Robado de si mismo
 * O(MlogN)
 */

#include "dsu.cpp"

pair<lld, vector<pair<int, int>>> kruskal(int n, int m, vector<pair<int, int>> &e, vector<lld> &w) {
	DSU dsu(n);

	vector<pair<int, int>> r;
	vector<int> ei(m);

	iota(all(ei), 0);
	sort(all(ei), [w](int i, int j) {
			return w[i] < w[j];
			});

	lld ans = 0;
	for (int i = 0; i < m; ++i) {
		auto [x, y] = e[ei[i]];
		lld c = w[ei[i]];
		if (dsu.join(x, y)) {
			r.emplace_back(x, y);
			ans += c;
		}
	}

	return {ans, r};
}
