// Bellman-Ford 
// Calcula la distancia más corta 
// entre a y todos los vértices y detecta un ciclo negativo 
// Devuelve 1 si hay un ciclo negativo 
// No es necesario representar el gráfico,solo almacena las aristas 
// O(nm)

int n, m;
int d[MAX];
vector<pair<int, int>> ar; // vector de aristas
vector<int> w;              // pesos de las aristas

bool bellman_ford(int a) {
	for (int i = 0; i < n; i++) d[i] = INF;
	d[a] = 0;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j < m; j++) {
			if (d[ar[j].second] > d[ar[j].first] + w[j]) {
				if (i == n) return 1;

				d[ar[j].second] = d[ar[j].first] + w[j];
			}
		}

	return 0;
}