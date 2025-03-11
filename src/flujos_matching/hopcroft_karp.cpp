/**
 * Fast bipartite matching
 * Kactl
 * Condiciones: G[i en {0...n - 1}] = {i -> j_1, i-> j_2}; vi btoa(m, -1); hopcroftKarp(g, btoa);
 * Despues de ejecucion, btoa[i] indicara con quien se matchea el nodo i del lado derecho con j del lado izquierdo
 * Retorna la cardinalidad del matching
 * Complejidad: O(\sqrt{V}E)
 */

#define vec vector
#define vi vec<lld>
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

namespace hopcroft {

	bool dfs(int a, int L, vec<vi>& g, vi& btoa, vi& A, vi& B) {
		if (A[a] != L) return 0;
		A[a] = -1;
		for (int b : g[a]) if (B[b] == L + 1) {
			B[b] = 0;
			if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
				return btoa[b] = a, 1;
		}
		return 0;
	}

	int hopcroftKarp(vec<vi>& g, vi& btoa) {
		int res = 0;
		vi A(g.size()), B(btoa.size()), cur, next;
		for (;;) {
			fill(all(A), 0);
			fill(all(B), 0);
			cur.clear();
			for (int a : btoa) if(a != -1) A[a] = -1;
			rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
			for (int lay = 1;; lay++) {
				bool islast = 0;
				next.clear();
				for (int a : cur) for (int b : g[a]) {
					if (btoa[b] == -1) {
						B[b] = lay;
						islast = 1;
					}
					else if (btoa[b] != a && !B[b]) {
						B[b] = lay;
						next.push_back(btoa[b]);
					}
				}
				if (islast) break;
				if (next.empty()) return res;
				for (int a : next) A[a] = lay;
				cur.swap(next);
			}
			rep(a,0,sz(g)) res += dfs(a, 0, g, btoa, A, B);
		}
	}
}
