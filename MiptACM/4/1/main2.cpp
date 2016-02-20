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

vpll convex_hull (vpll points) {
	i64 xmin = points[0].x_;
	int min = 0;
	for (int i = 1; i < points.size(); ++i) {
		if ((points[i].x_ < xmin) || (xmin == points[i].x_ && points[i].y_ < points[min].y_)) {
			xmin = points[i].x_;
			min = i;
		}
	}
	swap(points[0], points[min]);
	p0 = points[0];
	sort(points.begin() + 1, points.end(), &cmp);
	vpll stack;
	stack.pb(points[0]);
	stack.pb(points[1]);
	stack.pb(points[2]);
	for (int i = 3; i < points.size(); ++i) {
		int n = stack.size();
		while (orientation(stack[n - 2], stack[n - 1], points[i])) {
			stack.pop_back();
			n = stack.size();
		}
		stack.pb(points[i]);
	}
	return stack;
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
	//freopen("input.txt", "r", stdin);
	int n, q;
	int x, y;
	cin >> n;
	set<pll> set_points;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		set_points.insert(mp(x, y));
	}

	vpll points (set_points.begin(), set_points.end());
	vpll chull, chull_top, chull_bottom;
	if (points.size() >= 3) {
		chull = convex_hull(points);
	
	//split into 2 ch
		vpll::iterator right = max_element(chull.begin(), chull.end()); 
		chull_top = vpll(right, chull.end());
		chull_top.pb(chull[0]);
		reverse(chull_top.begin(), chull_top.end());
		chull_bottom = vpll(chull.begin(), right + 1);
	}

	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> x >> y;
		if (points.size() == 1) {
			cout << points[0].x_ * x + points[0].y_ * y << endl;
		} else if (points.size() == 2) {
			i64 pmax = max(points[1].x_ * x + points[1].y_ * y, points[0].x_ * x + points[0].y_ * y);
			cout << pmax << endl;
		} else {	
			pll answer;
			if (y >= 0) {
				answer = find_max(mp(x, y), chull_top);
			} else {
				answer = find_max(mp(x, y), chull_bottom);
			}
			cout << answer.x_ * x + answer.y_ * y << endl;
		}

	}
	return 0;
}