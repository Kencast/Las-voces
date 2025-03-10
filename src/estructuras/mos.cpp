#include <bits/stdc++.h>

using namespace std;
using lld = long long;
#define all(n) begin(n), end(n)

struct Query
{
    int l, r;
    int idx;
    // lld ord; // para usar con el hilbert
};

// ordena las queries para responder en O((N+Q)*sqrt(N))
void sort_queries_classic(vector<Query> &qs, int n)
{
    int const MO = int(sqrt(lld(n))) + 1;
    sort(all(qs), [MO](Query const &a, Query const &b)
         {
             int ba = a.l / MO, bb = b.l / MO;
             if (ba != bb)
                 return ba < bb;
             return ba & 1 ? a.r < b.r : a.r > b.r;
             // return a.r < b.r; // peor constante
         });
}

void answer_queries(vector<Query> const &qs)
{
    // TODO iniciar estado
    int l = 0, r = 0;
    forn(i, sz(qs))
    {
        while (l > qs[i].l)
        { /* TODO expandir izq */
            --l;
        }
        while (r < qs[i].r)
        { /* TODO expandir der */
            ++r;
        }
        while (l < qs[i].l)
        { /* TODO reducir izq */
            ++l;
        }
        while (r > qs[i].r)
        { /* TODO reducir der */
            --r;
        }
        // TODO guardar resultado
        // p.ej: ans[qs[i].idx] = estado_actual
    }
}