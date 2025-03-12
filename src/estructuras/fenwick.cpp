/**
 * Fenwick tree
 * Kactl
 * Todas las operaciones son O(log(n))
 * Indexado en 0
 * Consulta funciona sobre [0, r)
 * Lower_bound funciona iff todos los valores son no negativos
 *    Retorna la minima posicion i tal que query(i + 1) >= sum
 *    Si sum es nulo retorna -1 (por defecto)
 *    Si query(n) < sum, retorna n
 */

struct BIT {
	vector<lld> s;
	int n;

	BIT(int n) : n(n), s(n) {}
	void update(int pos, lld dif) {
		for (; pos < n; pos |= pos + 1) s[pos] += dif;
	}
	lld get(int pos) {
		lld res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
		return res;
	}
	int lower_bound(lld sum) {
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = bit_ceil(unsigned(n)); pw; pw >>= 1) {
			if (pos + pw <= n && s[pos + pw - 1] < sum)
				pos += pw, sum -= s[pos - 1];
		}
		return pos;
	}
};
