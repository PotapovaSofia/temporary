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
	int n, s, x ,y;
	char c;
	bool flag = false;
	cin >> n >> s;
	std::vector<pair<int, int>> B;
	std::vector<pair<int, int>> S;
	for (int i = 0; i < n; ++i)
	{
		cin >> c >> x >> y;
		if (c == 'B') {
			for (int i = 0; i < B.size(); ++i)
			{
				if(B[i].first == x) {
					B[i].second += y;
					flag = true;
				}
			}
			if (!flag) {
				B.push_back(make_pair(x, y));	
			} else {
				flag = false;
			}
			
		} else if (c == 'S') {
			for (int i = 0; i < S.size(); ++i)
			{
				if(S[i].first == x) {
					S[i].second += y;
					flag = true;
				}
			}
			if (!flag) {
				S.push_back(make_pair(x, y));	
			} else {
				flag = false;
			}
		}
	}
	if (B.size() > 0) {
		sort(B.begin(), B.end());
		reverse(B.begin(), B.end());
	}
	if (S.size() > 0) {
		sort(S.begin(), S.end());
	}
	
	int k = s > S.size() ? S.size() : s;
	if (S.size() > 0) {
		for (int i = k - 1; i >= 0; --i)
		{
			cout << "S" << " " << S[i].first << " " << S[i].second << endl;
		}
	}	
	k = s > B.size() ? B.size() : s;
	for (int i = 0; i < k; ++i)
	{
		cout << "B" << " " << B[i].first << " " << B[i].second << endl;
	}
	
	
	return 0;
}
