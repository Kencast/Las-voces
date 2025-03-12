// Euclides extendido
//
// Encuentra x e y tal que ax + by = gcd(a, b) (no es unico)
// Assume a, b >= 0
// O(log(min(a, b)))
// Los dos codigos funcionan igual pero son implementaciones distintas

typedef long long ll;

tuple<ll, ll, ll> ext_gcd(ll a, ll b) {
    if (!a) return {b, 0, 1};
    auto [g, x, y] = ext_gcd(b%a, a);
    return {g, y - b/a*x, x};
}

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}
