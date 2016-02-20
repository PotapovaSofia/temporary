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
    std::vector<string> v;
    string s;
    int m = 0;
  /*
    while(getline(cin, s)) {
        m = max(m, (int)s.size());
        v.push_back(s);
    }
  */
    
    int d;
    cin >> d;
    for (int i = 0; i < d; ++i)
    {
        cin >> s;
        v.push_back(s);
        m = max(m, (int)s.size());
    }
    
    for (int i = 0; i < m+2; ++i)
    {
        cout << "*";
    }
    cout << endl;
    int cnt;
    for (int i = 0; i < v.size(); ++i)
    {
        int x = (int)v[i].size();
        cout << m << " " << x << endl;
        cout << "*";
        if((int)v[i].size() % 2) {
            for (int i = 0; i < (m - x) / 2 + (cnt % 2); ++i)
            {
                cout << "-";
            }
            cout << v[i];
            cnt++;
            for (int i = 0; i < (m - x) / 2 + (cnt % 2); ++i)
            {
                cout << "-";
            }           
        } else {
            for (int i = 0; i < (m - x) / 2; ++i)
            {
                cout << "-";
            }
            cout << v[i];
            for (int i = 0; i < (m - x) / 2; ++i)
            {
                cout << "-";
            }
        }
        cout << "*" << endl;
    }
    for (int i = 0; i < m+2; ++i)
    {
        cout << "*";
    }
    cout << endl;
    return 0;
}