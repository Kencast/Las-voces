/**
 * Articulation Points
 * Encuentra los puntos de articulacion (vertices criticos) de un grafo
 * art[i] almacena el numero de nuevas componentes creadas al eliminar vertice i
 * si art[i] >= 1, entonces vertice i es punto de articulacion
 * O(n+m)
 */

namespace articulation {
    int n;
    vector<vector<int>> g;
    stack<int> s;
    vector<int> id, art;

    int dfs_art(int i, int& t, int p = -1) {
        int lo = id[i] = t++;
        s.push(i);
        for (int j : g[i]) if (j != p) {
            if (id[j] == -1) {
                int val = dfs_art(j, t, i);
                lo = min(lo, val);

                if (val >= id[i]) {
                    art[i]++;
                    while (s.top() != j) s.pop();
                    s.pop();
                }
                // if (val > id[i]) aresta i-j eh ponte
            }
            else lo = min(lo, id[j]);
        }
        if (p == -1 && art[i]) art[i]--;
        return lo;
    }

    void compute_art_points() {
        id = vector<int>(n, -1);
        art = vector<int>(n, 0);
        int t = 0;
        for (int i = 0; i < n; i++) if (id[i] == -1) 
            dfs_art(i, t, -1);
    }
};
