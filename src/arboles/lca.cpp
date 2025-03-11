/**
 * Binary lift para kesimo ancestro y lca
 * Robado de la pandilla
	vector<int> next(n);
	... inicializa next ...

	init_blift(&next[0], n);

	// j = next[next[...[i]...]]; (9 veces)
	int j = query_blift(i, 9);
 * O(nlogn) preprocesamiento
 * O(logn) consultas
 */

namespace blift {
	const lld LOG2N = 14;
	const lld MAXN = 1 << LOG2N;
	int bl[LOG2N][MAXN];

	// preprocesa saltos dado una funcion f: n -> n
	void init_blift(int* f, int n) {
		for (int x = 0; x < n; ++x) bl[0][x] = f[x];
		for (int k = 1; k < LOG2N; ++k)
		for (int x = 0; x < n; ++x) bl[k][x] = bl[k-1][bl[k-1][x]];
	}

	// kth jump
	int query_blift(int x, int t) {
		dforn(k, LOG2N) if (t & (1<<k)) x = bl[k][x];
		return x;
	}

	int padre[MAXN];
	int depth[MAXN];
	vec<vec<int>> adj;

	void dfs_lca(int u) {
		for(auto v : adj[u]) if(v != padre[u]){
			padre[v] = u;
			depth[v] = depth[u] + 1;
			dfs_lca(v);
		}
	}

	void init_lca(int root, int n) {
		depth[root] = 0;
		padre[root] = root;
		dfs_lca(root);
		init_blift(padre, n);
	}

	int query_lca(int u, int v) {
		int h = min(depth[u], depth[v]);
		u = query_blift(u, depth[u] - h);
		v = query_blift(v, depth[v] - h);
		if (u == v) return u;
		for (int k = LOG2N; k--;) {
			if (bl[k][u] != bl[k][v]) {
				u = bl[k][u];
				v = bl[k][v];
			}
		}
		return bl[0][u];
	}
}
