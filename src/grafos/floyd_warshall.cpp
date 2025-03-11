/**
 * Floyd-Warshall
 * encuentra el camino mas corto entre cada 
 * par de vertices y detecta un ciclo negativo 
 * devuelve 1 si hay un ciclo negativo
 * d[i][i] debe ser 0 
 * para i != j, d[i][j] debe ser w si hay una arista 
 * (i, j) de peso w, INF en caso contrario. O(n^3)
 */

bool floyd_warshall(int n, vector<vector<int>> &d) {
	for (int k = 0; k < n; k++)
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	for (int i = 0; i < n; i++)
		if (d[i][i] < 0) return 1;

	return 0;
}
