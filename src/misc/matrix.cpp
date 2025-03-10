/**
 * Matriz
 * Sacado de Kactl
 * Producto con Matriz en O(N^3)
 * Producto con Vector en O(N^2)
 * Exponenciacion en O(N^3logP)
 */

#define rep(i, a, b) for (int i = (a); i < (b); ++i)

template <class T, int N>
struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};

    M operator*(const M &m) const {
        M a;
        rep(i, 0, N) rep(j, 0, N)
            rep(k, 0, N) a.d[i][j] += d[i][k]*m.d[k][j];
        return a;
    }

    array<T, N> operator*(const array<T, N> &vec) const {
        array<T, N> ret{};
        rep(i, 0, N) rep(j, 0, N) ret[i] += d[i][j]*vec[j];
        return ret;
    }

    M operator^(ll p) const {
        assert(p >= 0);
        M a, b(*this);
        rep(i, 0, N) a.d[i][i] = 1;
        while (p) {
            if (p&1) a = a*b;
            b = b*b;
            p >>= 1;
        }
        return a;
    }
};
