#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const int N = 1000000;


int main () {
	std::vector<std::vector<char>> v;
	int n, m;
	char r;
	cin >> n >> m >> r;
	int ia, ib, jb;
	for (int i = 0; i < n; ++i)
	{
		std::vector<char> vg;
		for (int j = 0; j < m; ++j)
		{
			char c;
			cin >> c;
			vg.push_back(c);
		}
		v.push_back(vg);
	}
	vector<char> ans;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(v[i][j] == r) {
				if (i && v[i-1][j] != '.' && v[i-1][j] != r)
					ans.push_back(v[i][j]);
				else if (i != n-1 && v[i+1][j] != '.' && v[i-1][j] != r)
					ans.push_back(v[i][j]);
				else if (j && v[i][j-1] != '.' && v[i-1][j] != r)
					ans.push_back(v[i][j]);
				else if (j != m-1 && v[i][j+1] != '.' && v[i-1][j] != r)
					ans.push_back(v[i][j]);
			}
		}
	}
	sort(ans.begin(), ans.end());
	vector<char>::iterator it = unique(ans.begin(), ans.end());
	int sum = 0;
	for(vector<char>::iterator i = ans.begin(); i != it; i++) {
		sum++;
	}	
	cout << sum << endl;
	return 0;
}