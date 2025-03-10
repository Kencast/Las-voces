/**
 * Segtree Lazy
 * Consultas y actualizaciones sobre rangos
 * Sacado de Don gato
 * Todas las operaciones son O(logn)
 * En ::zero(), poner return tipo correspondiente que equivale a nulo
 * Consultas de forma [l, r) indexado en 0
 */

struct Lazy { /* TODO */
	static Lazy zero() { /* TODO */ }
	bool is_zero() { /* TODO */ }
};
struct Mono { /* TODO */
	static Mono zero() { /* TODO */ }
	void apply_lazy(Lazy d, int l, int r) { /* TODO */ }
};

Lazy operator+ (Lazy a, Lazy b) { /* TODO */ }
Mono operator+ (Mono a, Mono b) { /* TODO */ }

struct SegtreeLazy {
	int len;
	vector<Mono> data;
	vector<Lazy> lazy;

	SegtreeLazy(int n) {
		len = bit_ceil(unsigned(n));
		data.assign(2*len, Mono::zero());
		lazy.assign(2*len, Lazy::zero());
	};

	SegtreeLazy(int n, vector<Mono> &a) {
		len = bit_ceil(unsigned(n));
		data.assign(2*len, Mono::zero());
		lazy.assign(2*len, Lazy::zero());
		for (int i = 0; i < n; ++i) data[i + len] = a[i];
		for (int i = len - 1; i >= 1; --i) data[i] = data[i*2] + data[i*2 + 1];
	}

	int ql, qr;
	void update(int l, int r, Lazy x) { ql = l; qr = r; updatw(1, 0, len, x); }
	Mono query(int l, int r) { ql = l; qr = r; return query(1, 0, len); }

	void push(int i, int l, int r) {
		if (lazy[i].is_zero()) return;
		if (i < len) {
			lazy[2*i] = lazy[2*i] + lazy[i];
			lazy[2*i + 1] = lazy[2*i + 1] + lazy[i];
		}
		data[i].apply_lazy(lazy[i], l, r);
		lazy[i] = Lazy::zero();
	}

	Mono query(int i, int l, int r) {
		if (r <= ql || qr <= l) return Mono::zero();
		push(i, l, r);
		if (ql <= l && r <= qr) return data[i];
		int m = (l + r)/2;
		return query(i*2, l, m) + query(i*2 + 1, m, r);
	}

	void update(int i, int l, int r, Lazy x) {
		if (l == r) return;
		push(i, l, r);
		if (r <= ql || qr <= l) return;
		if (ql <= l && r <= qr) {
			lazy[i] = lazy[i] + x;
			push(i, l, r);
			return;
		}
		int m = (l + r)/2;
		update(i*2, l, m, x); update(i*2 + 1, m, r, x);
		data[i] = data[2*i] + data[2*i + 1];
	}
};
