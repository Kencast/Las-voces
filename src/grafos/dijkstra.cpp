/**
 * Dijkstra
 * Robado de bruno
 * O(mlog(n))
 * Si utilizas esa vara con pesos negativos me enojo
 * Para bfs 0-1, reemplazar cola de prioridad con un deque
 *    Si el peso de la arista es 1, meter al final, sino, al frente
 */

vector<lld> dijkstra(vector<vector<pair<int, lld>>> &adj, int v) {
	int n = adj.size();
	vector<lld> d(n, LLONG_MAX >> 3);
	d[v] = 0;
	priority_queue<pair<lld, int>> pq;
	pq.emplace(0, v);
 
	while (pq.size()) {
		auto [ndist, u] = pq.top(); pq.pop();
		if (-ndist > d[u]) continue;
 
		for (auto [idx, w] : adj[u]) if (d[idx] > d[u] + w) {
			d[idx] = d[u] + w;
			pq.emplace(-d[idx], idx);
		}
	}
	return d;
}
