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
	/*
	 * return false if counterclock wise
	 * return true  if colinear or clock wise
	 */
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
	//cout << "min" << points[min].x_ << ' ' << points[min].y_ << endl;
	swap(points[0], points[min]);
	p0 = points[0];
	sort(points.begin() + 1, points.end(), &cmp);
	for (int i = 0; i < points.size(); ++i) {
		cout << points[i].x_ << " " << points[i].y_ << endl;
	}
	/*
	for (int i = 0; i < points.size(); ++i) {
		cout << points[i].x_ << " " << points[i].y_ << endl;
	}
	*/
	vpll stack;
	stack.pb(points[0]);
	stack.pb(points[1]);
	stack.pb(points[2]);
	for (int i = 3; i < points.size(); ++i) {
		int n = stack.size();
		//cout << "stack_size: " << n << endl;
		while (orientation(stack[n - 2], stack[n - 1], points[i])) {
			//cout << "pop\n";
			stack.pop_back();
			n = stack.size();
		}
		//cout << "push: " << points[i].x_ << ' ' << points[i].y_ << endl;
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
   		//cout << "m: " << m << endl;
      	if (((points[m + 1].x_ - points[m].x_) * v.x_ > - (points[m + 1].y_ - points[m].y_) * v.y_)) {
      		/*
      		cout << "1: " << (points[m + 1].x_ - points[m].x_) * v.x_ << endl;
      		cout << "2: " << (points[m + 1].y_ - points[m].y_) * v.y_ << endl;
      		cout << " lol " << (points[m + 1].x_ - points[m].x_) * v.x_ + (points[m + 1].y_ - points[m].y_) * v.y_ << endl;
         	*/
         	l = m + 1;    
         //	cout << "l: " << l << endl;
      	} else {
         	r = m;
      	} 
   	}
//   	cout << l << " " << r << endl;
   	return points[l];
}


int main () {
	//freopen("input.txt", "r", stdin);
	time_t begin = clock();
	int n, q;
	int x, y;
	n = 4;
	//cin >> n;
	set<pll> set_points;
	int delta_x = 1;
	int delta_y = 3;
	for (int i = 0; i < n; ++i) {
		//cin >> x >> y;
		x = delta_x * i;
		y = delta_y * i;
		//x = (rand() /*% 100000 - 50000*/) * (rand() /*% 100000 - 50000*/)% (int)1e9;
		//y = (rand() /*% 100000 - 50000*/) * (rand() /*% 100000 - 50000*/)% (int)1e9;
		assert(x >= -(int)1e9 && x <= (int)1e9);
		assert(y >= -(int)1e9 && y <= (int)1e9);
		set_points.insert(mp(x, y));
	}


	vpll points (set_points.begin(), set_points.end());
	
	vpll chull, chull_top, chull_bottom;
	if (points.size() >= 3) {
		chull = convex_hull(points);

	cout << "chull:" << endl;
	for (int i = 0; i < chull.size(); ++i) {
		cout << chull[i].x_ << " " << chull[i].y_ << endl;
	}

	//split into 2 ch
		vpll::iterator right = max_element(chull.begin(), chull.end()); 
		chull_top = vpll(right, chull.end());
		chull_top.pb(chull[0]);
		reverse(chull_top.begin(), chull_top.end());
		chull_bottom = vpll(chull.begin(), right + 1);
		//reverse(chull_bottom.begin(), chull_bottom.end());

		cout << "top:" << endl;
		for (int i = 0; i < chull_top.size(); ++i) {
			cout << chull_top[i].x_ << " " << chull_top[i].y_ << endl;
		}
		cout << "bottom:" << endl;
		for (int i = 0; i < chull_bottom.size(); ++i) {
			cout << chull_bottom[i].x_ << " " << chull_bottom[i].y_ << endl;
		}

	}
//	cout << endl;
	q = 1e5;
	//cin >> q;
	for (int i = 0; i < q; ++i) {
		//cin >> x >> y;
		x = (rand() /*% 100000 - 50000*/) * (rand() /*% 100000 - 50000*/) % (int)1e9;
		y = (rand() /*% 100000 - 50000*/) * (rand() /*% 100000 - 50000*/)% (int)1e9;
		assert(x >= -(int)1e9 && x <= (int)1e9);
		assert(y >= -(int)1e9 && y <= (int)1e9);
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
			/*
			pll ans1 = find_max(mp(x, y), chull_top);
			pll ans2 = find_max(mp(x, y), chull_bottom);
			pll answer;
			if (ans1.x_ * x + ans1.y_ * y > ans2.x_ * x + ans2.y_ * y) {
				answer = ans1;
			} else {
				answer = ans2;
			}*/
			//i64 mmax = (ans1.x_ * x + ans1.y_ * y, ans2.x_ * x + ans2.y_ * y);
			
			cout << answer.x_ * x + answer.y_ * y << endl;
			//cout << max(ans1.x_ * x + ans1.y_ * y, ans2.x_ * x + ans2.y_ * y) << endl;

			i64 pmax = points[0].x_ * x + points[0].y_ * y;
			int imax = 0;
			for (int i = 1; i < points.size(); ++i) {
				if (pmax < points[i].x_ * x + points[i].y_ * y) {
					pmax = points[i].x_ * x + points[i].y_ * y;
					imax = i;
					//printf("choose %lld %lld\n", points[i].x_, points[i].y_);
				}
				//pmax = max(points[i].x_ * x + points[i].y_ * y, pmax);
			}
			
			if (pmax != (answer.x_ * x + answer.y_ * y)) {
				cout << "found: " << answer.x_ << " " << answer.y_ << endl;
				cout << "value found: " << answer.x_ * x + answer.y_ * y << endl;
				cout << pmax << endl;
				cout << "right: " << points[imax].x_ << " " << points[imax].y_ << endl;
				//cout << answer.x_ * x + answer.y_ * y << endl;
				cout << "error: \nvct: " << x << " " << y << endl;
				exit(0);
			}

		}

	}
	time_t end = clock();
	cout << "time: " << (double)(end - begin) / CLOCKS_PER_SEC << endl;
	return 0;
}