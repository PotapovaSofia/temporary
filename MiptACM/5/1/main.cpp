
#define _GLIBCXX_DEBUG
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
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back 
#define mp make_pair 

const int maxN = (int)1e5;
const int undef = 1e9;
const int LN = 18;

struct seg_info {
	int sum, pref, suf, best;
	seg_info(){}
	seg_info(int x): sum(x), pref(x), suf(x), best(x) {}
	seg_info(int x, int y): sum(x), pref(y), suf(y), best(y) {}
	void print() {
		cout << "sum: " << sum << "pref: " << pref << "suf: " << suf << "best: " << best << endl;
	}
};

vector<seg_info> segtree[maxN];
vector<int> tree[maxN], path[maxN], uptree[maxN];
int sz[maxN], w[maxN], pa[LN][maxN], depth[maxN], path_num[maxN], path_cnt, path_no[maxN];

void dfs( int cur, int prev, int d = 0) {
	int x;
	pa[0][cur] = prev;
	for (int i = 1; i < LN; ++i) {
		pa[i][cur] = pa[i - 1][pa[i - 1][cur]]; 
	}
	depth[cur] = d;
	//cout << "depth: " << d << endl;
	sz[cur] = 1;
	for(int i = 0; i < tree[cur].size(); i++) if(tree[cur][i] != prev) {
	    dfs(tree[cur][i], cur, d + 1);
	    sz[cur] += sz[tree[cur][i]];
	}
}

int lca(int u, int v) {
	if (depth[u] < depth[v]){
		swap(u,v);
	}
	int diff = depth[u] - depth[v];
	//cout << "diff: " << diff << endl;
	for (int i = 0; i < LN; i++) {
		if ((diff >> i) & 1) {
			u = pa[i][u];
		}
	}
	//cout << u << " " << v << endl;
	if (u == v) {
		return u;
	}
	for (int i = LN - 1; i >= 0; i--)  {
		if(pa[i][u] != pa[i][v]) {
			u = pa[i][u];
			v = pa[i][v];
		}
	}
	return pa[0][u];
}

seg_info merge(seg_info a, seg_info b) {
	seg_info c;
	c.sum = a.sum + b.sum;
	c.suf = max(max(a.suf, (int)0) + b.sum, b.suf);
	c.pref = max(a.pref, a.sum + max(b.pref, (int)0));
	c.best = max(max(a.best, b.best), max(max(a.suf, (int)0) + b.pref, a.suf + max(b.pref, (int)0)));
	return c;
}

void build_tree(int cur, int i, int l, int r) {
	uptree[cur][i] = undef;
	if (r == l + 1) {
		segtree[cur][i] = seg_info(w[path[cur][l]]);
	} else {
		int m = (l + r) / 2;
		build_tree(cur, 2 * i + 1, l, m);
		build_tree(cur, 2 * i + 2, m, r); ////////////////////////////////////////////////
		segtree[cur][i] = merge(segtree[cur][2 * i + 1], segtree[cur][2 * i + 2]);
	}
}

void push_tree(int cur, int i, int length) {
	if (uptree[cur][i] != undef) {
		if (length != 1) {
			uptree[cur][2 * i + 1] = uptree[cur][2 * i + 2] = uptree[cur][i];
		}
		if (uptree[cur][i] > 0) {
			segtree[cur][i] = seg_info(uptree[cur][i] * length);
		} else {
			segtree[cur][i] = seg_info(uptree[cur][i] * length, uptree[cur][i]);
		}
		uptree[cur][i] = undef;
	}
}

void update_tree(int cur, int i, int l, int r, int a, int b, int val) {
	push_tree(cur, i, r - l);
	if (b <= l || a >= r) 
		return;
	if (l == a && b == r) {
		uptree[cur][i] = val;
		push_tree(cur, i, r - l);
	} else {
		int m = (l + r) / 2;
		update_tree(cur, 2 * i + 1, l, m, a, min(b, m), val);
		update_tree(cur, 2 * i + 2, m, r, max(a, m), b, val);
		segtree[cur][i] = merge(segtree[cur][2 * i + 1], segtree[cur][2 * i + 2]);
	}
}

seg_info get_tree(int cur, int i, int l, int r, int a, int b) {
	
	push_tree(cur, i, r - l);
	//cout << "get_tree: " << i <<" " << l << " " << r << " " << a << " " << b << " " << endl;;

	int m = (l + r) / 2;
	if (a == l && b == r) {
		return segtree[cur][i];
	}
	if (b <= m) {
		return get_tree (cur, 2 * i + 1, l, m, a, b);
	}
	if (a >= m) {
		return get_tree (cur, 2 * i + 2, m, r, a, b);
	}
	return merge(get_tree (cur, 2 * i + 1, l, m, a, m), get_tree (cur, 2 * i + 2, m, r, m, b));
}

void build_hld(int n) {
	//cout << "build_hld\n";
	path_cnt = 0;
	for (int cur = 0; cur < n; ++cur) {
		bool has_heavy = false;
		for (int i = 0; i < tree[cur].size(); ++i) if(tree[cur][i] != pa[0][cur]) {
			if (2 * sz[tree[cur][i]] >= sz[cur]) {
				has_heavy = true;
			}
			//cout << cur << " " << tree[cur][i] << " " << has_heavy << endl;
		}
		if (!has_heavy) {
			int x = cur;
			while (x != -1) {
				path[path_cnt].pb(x);
				path_num[x] = path[path_cnt].size() - 1;
				path_no[x] = path_cnt;
				if (2 * sz[x] >= sz[pa[0][x]]) {
					x = pa[0][x];
				} else {
					break;
				}
			}
			path_cnt++;
		}
	}
}

seg_info get_tree(int cur, int a, int b) {
	//cout << "get_tree: " << cur << " " << a << " " << b << endl;
	return get_tree(cur, 0, 0, path[cur].size(), a, b);
}

seg_info get_hld(int a, int b) {
	//cout << "get_hld: " << a << " " << b << endl;
	int cur = a;
	bool first_it = true;
	seg_info res;
	while (cur != -1) {
		seg_info new_res;

		if (path_no[cur] == path_no[b]) {
			new_res = get_tree(path_no[cur], path_num[cur], path_num[b] + 1);	
		} else {
			new_res = get_tree(path_no[cur], path_num[cur], path[path_no[cur]].size());
		}
		//cout << "new_res:  ";
		//new_res.print();
		if (first_it) {
			res = new_res;
			first_it = false;
		} else {
			res = merge(res, new_res);
		}
		//cout << "res:      ";
		//res.print();
		if (path_no[cur] == path_no[b]) {
			break;
		}
		cur = pa[0][path[path_no[cur]].back()];
	}
	return res;
}

void update_tree(int cur, int a, int b, int val) {
	//cout << "update_tree: " << a << " " << b << " " << val << endl;
	update_tree(cur, 0, 0, path[cur].size(), a, b, val);
}

void update_hld(int a, int b, int val) {
	int cur = a;	
	while (cur != -1) {
		//cout << "cur: " << cur << endl;
		if (path_no[cur] == path_no[b]) {
			update_tree(path_no[cur], path_num[cur], path_num[b] + 1, val);	
		} else {
			update_tree(path_no[cur], path_num[cur], path[path_no[cur]].size(), val);
		}
		if (path_no[cur] == path_no[b]) {
			break;
		}
		cur = pa[0][path[path_no[cur]].back()];
	}	
}

int main() {
	freopen("input.txt", "r", stdin);
	int n, q, x, y, v, k;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		w[i] = x;
	}
	for (int i = 1; i < n; ++i) {
		scanf("%d%d", &x, &y);
		tree[x - 1].pb(y - 1);
		tree[y - 1].pb(x - 1);
	}
	dfs(0, -1);
	build_hld(n);
	for (int i = 0; i < path_cnt; ++i) {
		segtree[i].resize(4 * path[i].size());
		uptree[i].resize(4 * path[i].size());
		build_tree(i, 0, 0, path[i].size());
/*
		cout << "path " << i << ": ";
		for (int j = 0; j < path[i].size(); ++j) {
			cout << path[i][j] << " ";
		}
		cout << endl;*/
	}
	/*
	cout << "weight: \n";
	for (int i = 0; i < path_cnt; ++i) {
		cout << "path " << i << endl;
		for (int j = 0; j < 4 * path[i].size(); ++j) {
			segtree[i][j].print();
		}
	}
	cout << endl;
*/
	for (int i = 0; i < q; ++i) {
		//cout << "query: " << i << endl;
		scanf("%d%d%d%d", &k, &x, &y, &v);
		x--; y--;
		int l = lca(x, y);
		//cout << "x: " << x << " y: " << y << " lca: " << l << endl;
		if (k == 1) {
			update_hld(x, l, v);
			update_hld(y, l, v);
			/*
			cout << "weight: \n";
			for (int i = 0; i < path_cnt; ++i) {
				cout << "path " << i << endl;
				for (int j = 0; j < 4 * path[i].size(); ++j) {
					segtree[i][j].print();
				}
			cout << endl;
			*/
				
		} else {
			seg_info res;
			if (y == l) {
				res = get_hld(x, l);
			} else if (x == l) {
				res = get_hld(y, l);
			} else {
				int u = y;
				int diff = depth[y] - depth[l] - 1;
				for (int i = 0; i < LN; i++) {
					if ((diff >> i) & 1) {
						u = pa[i][u];
					}
				}				
				//cout << "u: " << u << endl;		
				seg_info right_res = get_hld(y, u);
				swap(right_res.suf, right_res.pref);
				res = merge(get_hld(x, l), right_res);
			}
			printf("%d\n", res.best);			
		}
	}

	return 0;
}