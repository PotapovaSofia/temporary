#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;


int main () {
	pair<int, int> w1[100010], w2[100010];
	int cnt1, cnt2;
	vector<pair<int,int> > answer;
	int sum;
	int n, v;
	cin >> n >> v;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		if (t == 1) {
			cin >> w1[cnt1].first;
			w1[cnt1++].second = i;
		}
		if (t == 2) {
			cin >> w2[cnt2].first;
			w2[cnt2++].second = i;
		}
	}
	sort (w1, w1 + cnt1);
	sort (w2, w2 + cnt2);
	cnt1--;
	cnt2--;
	if (v % 2) {
		answer.push_back(w1[cnt1--]);
		v--;
	}
	while(v && cnt1 >= 0 && cnt2 >= 0) {
		if ((w1[cnt1].first + w1[cnt1-1].first) > w2[cnt2].first) {
			v -= 2;
			answer.push_back(w1[cnt1--]);
			answer.push_back(w1[cnt1--]);
		} else {
			v -= 2;
			answer.push_back(w2[cnt2--]);
		}	
	}
	if (v) {
		while (cnt1 >= 0) {
			v--;
			answer.push_back(w1[cnt1--]);
		}
		while (cnt2 >= 0) {
			v -= 2;
			answer.push_back(w2[cnt2--]);
		}
	}
	for (int i = 0; i < answer.size(); ++i)
	{
		sum += answer[i].first;
	}
	cout << sum << endl;
	if (sum) {
		for (int i = 0; i < answer.size(); ++i) {
			cout << answer[i].second + 1 << " ";
		}	
	}
	cout << endl;
	return 0;
}