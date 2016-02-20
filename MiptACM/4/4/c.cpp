#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int P = 1000000007;

class point {
public:
    long long x, y;
    point(long long x, long long y) : x(x), y(y) {}
    point() {}
};

const point Origin(0, 0);

long long dotProduct(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

long long crossProduct(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

bool operator < (point a, point b) {
    return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

bool operator == (point a, point b) {
    return (a.x - b.x == 0 &&  a.y - b.y == 0);
}

point operator + (point a, point b) {
    return point(a.x + b.x, a.y + b.y);
}

point operator - (point a, point b) {
    return point(a.x - b.x, a.y - b.y);
}

point f (point a){
    return (Origin < a ? a : Origin - a);
}


bool compPoint1(point a, point b) {
    return (crossProduct(f(a), f(b)) > 0 || (crossProduct(f(a), f(b)) == 0 &&
                    (abs(f(a).x) > abs(f(b).x) || abs(f(a).y) > abs(f(b).y))));
}

bool compPoint2(point a, point b) {
    return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

int main() {
    time_t begin = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    //cin >> n;
    n = 2000;
    vector<point> p(n);
    for (int i = 0; i < n; i++) {
        //cin >> p[i].x >> p[i].y;
        p[i].x = (rand() /*% 100000 - 50000*/) * (rand() /*% 100000 - 50000*/) % (int)1e9;
        p[i].y = (rand() /*% 100000 - 50000*/) * (rand() /*% 100000 - 50000*/)% (int)1e9;
    }
    vector<long long> pow(n + 1);
    pow[0] = 1;
    for (int i = 1; i <= n; i++)
        pow[i] = (pow[i - 1] * 2) % P;
    sort(p.begin(), p.end(), compPoint2);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i;
        for (; i < n - 1 && p[i] == p[i + 1]; i++);
        point v = p[i];
        //cout << "\npoint: " << p[l].x << " " << p[l].y << endl;
        vector<point> q(n);
        for (int j = 0; j < n; j++)
            q[j] = p[j] - v;
        for (int j = l; j <= i; j++)
            swap(q[j], q[j - l]);
        sort(q.begin() + i - l + 1, q.end(), compPoint1);
        int side1 = 0;
        int side2 = 0;
        for (int j = i - l + 1; j < n; j++) {
            if (q[j] < Origin)
                side2++;
            if (!(q[j] < Origin))
                side1++;
        }
        int k = i - l;
        for (int j = i - l + 1; j < n; j++) {
            for(; j < n - 1 && crossProduct(q[j], q[j + 1]) == 0; j++);
            int onLine = 0;
            for (int t = k + 1; t <= j; t++) {

                if (f(q[t]) == q[t]) {
                    side1--;
                    onLine++;
                }
                else
                    side2--;
            }
            //cout << side1 << " " << side2 << endl;
            ans = (ans + (((pow[i - l + 1] - 1) * (pow[onLine] - 1)) % P) *
                   ((pow[side1] + pow[side2]) % P)) % P;
            //cout << "prob: " << (((pow[i - l + 1] - 1) * (pow[onLine] - 1)) % P) *
            //       ((pow[side1] + pow[side2]) % P) << endl;
            //cout << "onLine: " << onLine << endl;
            //cout << "pow: " << (pow[side1] + pow[side2]) << endl;
            //cout << "(pow[i - l + 1] - 1): " << (pow[i - l + 1] - 1) << endl;

            for (int t = k + 1; t <= j; t++) {
                if (f(q[t]) == q[t])
                    side2++;
                else
                    side1++;
            }
            k = j;
        }
        ans = (ans + pow[i - l + 1] - 1) % P;
    }
    cout << ans << endl;
    time_t end = clock();
    cout << "time: " << (double)(end - begin) / CLOCKS_PER_SEC << endl;
    return 0;
}
