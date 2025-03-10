/**
 * Mod template
 * Kactl
 * Dependencia: algoritmo euclidiano extendido
 * Si mod es primo, invert se puede reemplazar con binexp(Mod, mod - 2)
 */

#include "euclid.cpp"

const lld mod = 998244353;

struct Mod {
	lld x;
	Mod(lld x) : x(x) {}
	Mod operator+(Mod b) const { return Mod((x + b.x)%mod); }
	Mod operator-(Mod b) const { return Mod((x - b.x + mod)%mod); }
	Mod operator*(Mod b) const { return Mod((x*b.x)%mod); }
	Mod operator/(Mod b) const { return *this*invert(b); }
	Mod invert(Mod a) const {
		lld x, y, g = euclid(a.x, mod, x, y);
		assert(g == 1); return Mod((x + mod) % mod);
	}
	Mod operator^(lld e) const {
		if (!e) return Mod(1);
		Mod r = *this^(e / 2); r = r*r;
		return e&1 ? *this*r : r;
	}
};
