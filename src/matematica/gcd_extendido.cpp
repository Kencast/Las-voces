// Euclides extendido
//
// Encuentra x e y tal que ax + by = gcd(a, b) (no es unico)
// Assume a, b >= 0
// O(log(min(a, b)))

typedef long long ll;

tuple<ll, ll, ll> ext_gcd(ll a, ll b) {
    if (!a) return {b, 0, 1};
    auto [g, x, y] = ext_gcd(b%a, a);
    return {g, y - b/a*x, x};
}