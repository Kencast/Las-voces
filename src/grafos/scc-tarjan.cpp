/**
 * SCC con Tarjan
 * Robado de bruno
 * O(n + m)
 */

struct Tarjan {
    vector<vector<int>> g;
    stack<int> s;
    vector<int> vis, comp;
    vector<int> id;

    Tarjan(int len, vector<vector<int>> &adj) {
        g = adj;
        vis.assign(len, 0);
        comp.assign(len, 0);
        id.assign(len, 0);
    }
    // si desea comprimir un ciclo o encontrar un puente en un grafo no dirigido
    // coloque un if en el dfs para evitar regresar al padre del arbol DFS
    int dfs(int i, int &t) {
        int lo = id[i] = t++;
        s.push(i);
        vis[i] = 2;

        for (int j : g[i]) {
            if (!vis[j]) lo = min(lo, dfs(j, t));
            else if (vis[j] == 2) lo = min(lo, id[j]);
        }
        // El borde de un padre es un puente (en el caso no dirigido)
        if (lo == id[i]) while (1) {
                int u = s.top();
                s.pop();
                vis[u] = 1, comp[u] = i;
                if (u == i) break;
        }

        return lo;
    }

    void tarjan(int n) {
        int t = 0;
        for (int i = 0; i < n; i++) vis[i] = 0;
        for (int i = 0; i < n; i++) if (!vis[i]) dfs(i, t);
    }
};
