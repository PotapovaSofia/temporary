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

bool check(int a, int b, int c) {
	if (a + b > c && a + c > b && b + c > a)
		return true;
	return false;
}

int main () {
	int a, b, c, l, ans = 0;
	bool flag = false;
	cin >> a >> b >> c >> l;
	for (int x = 0; x <= l; ++x)
	{
		for (int y = 0; y <= l - x; ++y) 
		{
			for (int z = 0; z <= l - x - y; ++z)
			{
				if (check(a+x, b+y, c+z)) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;	
	
	return 0;
}
