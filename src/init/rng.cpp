// Utilizar este codigo para valores aleatorios porque rand() es muy pequeno
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

// [l, r]
int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
