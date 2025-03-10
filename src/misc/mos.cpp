/**
 * Mo's
 * Robado de La pandilla
 * O((N+Q)*sqrt(N) + QlogQ)
 */

namespace mos {
	struct Query {
	    int l, r;
	    int idx;
	};

	void sort_queries(vector<Query> &qs, int n) {
	    int const MO = int(sqrt(lld(n))) + 1;
	    sort(all(qs), [MO](Query const &a, Query const &b) {
		     int ba = a.l/MO, bb = b.l/MO;
		     if (ba != bb) return ba < bb;
		     return ba&1 ? a.r < b.r : a.r > b.r;
		 });
	}

	void start(vector<Query> const &qs) {
	    // TODO iniciar estado
	    int l = 0, r = 0;
	    for (int i = 0; i < ssize(qs); ++i) {
		while (l > qs[i].l) { /* TODO expandir izq */
		    --l;
		}
		while (r < qs[i].r) { /* TODO expandir der */
		    ++r;
		}
		while (l < qs[i].l) { /* TODO reducir izq */
		    ++l;
		}
		while (r > qs[i].r) { /* TODO reducir der */
		    --r;
		}
		// TODO guardar resultado
		// p.ej: ans[qs[i].idx] = estado_actual
	    }
	}
}
