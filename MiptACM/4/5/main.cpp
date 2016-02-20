#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>
#include <ctime>
#include <assert.h>

using namespace std;

typedef long long i64;
typedef pair<int, int> pii;
typedef pair<i64, i64> pll;
typedef vector<pair<i64, i64> > vpll;
#define x_ first 
#define y_ second 
#define pb push_back 
#define mp make_pair 

vector<vpll> chulls;
vpll points;

pll p0;

i64 dist(pll p1, pll p2) {
	return (p1.x_ - p2.x_) * (p1.x_ - p2.x_) + (p1.y_ - p2.y_) * (p1.y_ - p2.y_);
}

bool orientation(pll p, pll q, pll r) {
	return ((q.y_ - p.y_) * (r.x_ - q.x_) >= (q.x_ - p.x_) * (r.y_ - q.y_));
}

bool cmp (pll p1, pll p2) {
	if (orientation(p0, p1, p2)) {
		if ((p1.y_ - p0.y_) * (p2.x_ - p1.x_) == (p1.x_ - p0.x_) * (p2.y_ - p1.y_)) {
			return (dist(p0, p2) >= dist(p0, p1)) ? 1 : 0;
		}
		return 0;
	}
	return 1;
}

void build(i, l, r) {
	if (l + 1 == r) {
		chulls[i] = points[l];
		return;
	}
	int m = (l + r) / 2;
	build(2 * i, l, m);
	build(2 * i + 1, m, r);
	chulls[i] = chulls[2 * i + 1];
	n = chulls[i].size();
	for (int j = chulls[2 * i].size() - 1; j >= 0; --j) {
		while (orientation(chulls[i][n - 2], chulls[i][n - 1], chulls[2 * i][j])) {
			chulls[i].pop_front();
			n = chulls[i].size();
		}
		chulls[i].push_front(points[i]);
	}
}

inline pll find_max (pll v, vpll &points) {
	int l = 0;
   	int r = points.size() - 1;
   	int m;
   	while (l < r) {
   		m = (l + r)/2;
      	if (((points[m + 1].x_ - points[m].x_) * v.x_ > - (points[m + 1].y_ - points[m].y_) * v.y_)) {
           	l = m + 1;    
      	} else {
         	r = m;
      	} 
   	}
   	return points[l];
}


int main () {
	freopen("input.txt", "r", stdin);
	int k, m;
	int x1, y1, x2, y2;
	cin >> k >> m;
	set<pll> set_points;	
	for (int i = 0; i < k; ++i) {
		cin >> x1 >> y1;
		set_points.pb(mp(x1, y1));
	}
	points = vpll(set_points.begin(), set_points.end());
	build(1, 0, points.size());
	for (int i = 0; i < m; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		//vpll chull = stree.get_ch(mp(x1, y1), mp(x2, y2));

		pll answer;
		if ((x1 - x2) >= 0) {
			answer = find_max(mp(y2 - y1, x1 - x2), chull)
		} else {
			answer = find_max(mp(y2 - y1, x2 - x1), chull)
		}
		if (answer > (x1 - x2) * y1 + (y2 - y1) * x1) {
			cout << "Y" << endl;
		} else {
			cout << "N" << endl;
		}
	}

	return 0;
}