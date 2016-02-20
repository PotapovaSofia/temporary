#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main () {
	int d, sumTime;
	cin >> d >> sumTime;
	vector<pair<int, int>> mums;
	for (int i = 0; i < d; ++i)
	{
		int x, y;
		cin >> x >> y;
		mums.push_back(make_pair(x, y));
	}
	vector<int> schedule(d);
	for (int i = 0; i < d; ++i)
	{
		schedule[i] = mums[i].first;
	}
	int need = sumTime;
	for (int i = 0; i < d; ++i)
	 {
	 	need -= schedule[i];
	 } 
	if (need < 0) {
		cout << "NO";
		return 0;
	}
	int delta;
	for (int i = 0; i < d; ++i)
	{
		delta = min(need, mums[i].second - schedule[i]);
		schedule[i] += delta;
		need -= delta;
	}
	if (need > 0) {
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 0; i < d; ++i)
	{
		cout << schedule[i] << " ";
	}
	cout << endl;
	return 0;
}