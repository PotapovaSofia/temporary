#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <ctime>
#include <assert.h>

using namespace std;

typedef long long i64;
typedef pair<int, int> pii;
typedef pair<i64, i64> pll;
typedef vector<pair<i64, i64> > vpll;
#define ft first 
#define sd second 
#define pb push_back 
#define mp make_pair 
const int mod = 1e9 + 7;

struct point {
		i64 x, y;
		int w;
		point(): x(0), y(0), w(0) {};
		point(i64 x_, i64 y_, int w_): x(x_), y(y_), w(w_) {};
		point(const point &another) {
			x = another.x;
			y = another.y;
			w = another.w;
		}
};

point a;
pii b;

inline i64 vct_mult(pii p1, pii p2) {
	return (i64)p1.ft * p2.sd - (i64)p1.sd * p2.ft;
}

inline bool in_top(pii p) {
	return p.sd > 0 || p.sd == 0 && p.ft > 0;
}

struct cmp {
	inline bool operator() (pii left, pii right) {
		if (in_top(left) == in_top(right)) {
			return vct_mult(left, right) > 0;
		}
		return in_top(left);
	}
};

int main () {
	time_t begin = clock();
	int n, x, y, w;
	scanf("%d", &n);
	map<pii, int> P;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x, &y);
		P[mp(x, y)] += 1;
	}
	vector<point> points;
	for (auto a :P) {
		points.emplace_back(a.ft.ft, a.ft.sd, a.sd);
	}
	vector<i64> pow2(n + 1);
	pow2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pow2[i] = pow2[i - 1] * 2 % mod;
	}
	n = points.size();
	i64 prob = 0;
	for (auto p :points) {
		prob = (prob + pow2[p.w] - 1) % mod;
	}
	for (int i = 0; i < n; ++i) {
		a = points[i];
		map<pii, vector<pair<i64, int>>, cmp> M;
		for (int j = 0; j < n; ++j) if (i != j) {
			pii b(points[j].x - a.x, points[j].y - a.y);	
			i64 dist = (i64)b.ft * b.ft + (i64)b.sd * b.sd; 
			M[b].pb(mp(dist, points[j].w));
			pii b_(-b.ft, -b.sd);
			M[b_].size();
		}
		b = M.begin()->ft;
		i64 s1 = 0, s2 = 0;
		for (int j = 0; j < n; ++j) {
			i64 mult = vct_mult(b, mp(points[j].x - a.x, points[j].y - a.y));
			if (mult > 0) {
				s1 += points[j].w;
			} else if (mult < 0) {
				s2 += points[j].w;
			}
		}
		for (auto vct :M) {
			int to_s1 = 0, to_s2 = 0;
			for (auto v :vct.sd) {
				to_s1 += v.sd;
			}
			pii vct_(-vct.ft.ft, -vct.ft.sd);
			for (auto v :M[vct_]) {
				to_s2 += v.sd;
			}
			if (vct.ft != M.begin()->ft) {
				s1 -= to_s1;
				s2 -= to_s2;
			}
			i64 predp = ((pow2[s1] + pow2[s2]) * (pow2[a.w] - 1)) % mod;
			if (in_top(vct.ft)) {
				int W = 0;
				sort(vct.sd.begin(), vct.sd.end());
				for (auto p :vct.sd) {
					prob = prob + pow2[W] * predp % mod * (pow2[p.sd] - 1);		
					W += p.sd;
					
					
				}
			} else {
				break;
			}
			s1 += to_s2;
			s2 += to_s1;
			prob = prob % mod;
		}
	}
	cout << prob << endl;
	return 0;
}