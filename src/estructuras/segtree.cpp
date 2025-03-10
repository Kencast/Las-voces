/**
 * Segment tree
 * De kactl
 * Indexado en 0, iterativo
 * Actualizacion en punto
 * Consultas de forma [l, r)
 * Complejidad: O(log N)
 */

struct Mono { /* TODO */
	static Mono zero() { /* TODO */ }
};

Mono operator+ (Mono a, Mono b) { /* TODO */ }

struct Tree {
    vector<Mono> s;
    int n;

    Tree(int n) : n(n), s(2*n, Mono::zero()) {}

    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = s[pos*2] + s[pos*2 + 1];
    }

    // [l, r)
    T query(int l, int r) {
        T lv = Mono::zero(), rv = Mono::zero();
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l&1) lv = lv + s[l++];
            if (r&1) rv = s[--r] + rv;
        }
        return lv + rv;
    }
};
