/**
 * De kactl
 * Description: Zero-indexed max-tree. Bounds are inclusive to the left and exclusive to the right.
 * Can be changed by modifying T, f and unit.
 * Time: O(\log N)
 * Status: stress-tested
 */
struct Tree {
    typedef int T;
    static constexpr T unit = INT_MIN;
    T f(T a, T b) { return max(a, b); } // (any associative fn)

    vector<T> s;
    int n;

    Tree(int n = 0, T def = unit) : n(n), s(2*n, def) {}

    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos*2], s[pos*2 + 1]);
    }
    // [l, r)
    T query(int l, int r) {
        T lv = unit, rv = unit;
        for (l += n, r += n; l < r; l /= 2, r /= 2)
        {
            if (l&1) lv = f(lv, s[l++]);
            if (r&1) rv = f(s[--r], rv);
        }
        return f(lv, rv);
    }
};
