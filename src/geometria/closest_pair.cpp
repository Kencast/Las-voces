/**
 * Kactl
 * Source: https://codeforces.com/blog/entry/58747
 * Time: O(n \log n)
 * Status: stress-tested
 * #pragma once
 */
#include <bits/stdc++.h>
#include "Point.h"

#define all(n) begin(n), end(n)
#define sz(x) (int)(x).size()

using lld = long long;
using namespace std;
typedef Point<lld> P;
pair<P, P> closest(vector<P> v) {
	assert(sz(v) > 1);
	set<P> S;
	sort(all(v), [](P a, P b) { return a.y < b.y; });
	pair<lld, pair<P, P>> ret{LLONG_MAX, {P(), P()}};
	int j = 0;
	for (P p : v) {
		P d{1 + (lld)sqrt(ret.first), 0};
		while (v[j].y <= p.y - d.x) S.erase(v[j++]);
		auto lo = S.lower_bound(p - d), hi = S.upper_bound(p + d);
		for (; lo != hi; ++lo)
			ret = min(ret, {(*lo - p).dist2(), {*lo, p}});
		S.insert(p);
	}
	return ret.second;
}