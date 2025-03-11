/**
 * Bellman-Ford 
 * Calcula la distancia mas corta
 * Devuelve 1 si hay un ciclo negativo 
 * Poner ar como un vector de aristas y w con un vector de pesos por cada arista
 * Complejidad: O(nm)
 */

pair<bool, vector<lld>> bellman_ford(vector<pair<int, int>> &ar, vector<lld> &w, int a) {
	vector<lld> d(n, LLONG_MAX >> 3);
	d[a] = 0;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j < m; j++) {
			if (d[ar[j].second] > d[ar[j].first] + w[j]) {
				if (i == n) return {1, {}};
				d[ar[j].second] = d[ar[j].first] + w[j];
			}
		}
	return {0, d};
}
