#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int binpow (int a, int n) {
    if (n == 0) return 1;
    if ((n & 1) == 0) {
        int b = binpow(a, n >> 1);
        return (b * b);
    }
    else 
        return binpow(a, n - 1) * a;
}

string inverse(int number){
	string answer;
	int x;
	while (number != 0) {
		x = number % 26;
		number /= 26;
		if (x == 0) {
			number--;
			x = 26;
		}
		answer.insert(answer.begin(), 64 + x);
	}
	return answer;
}

int reinverse(string s) {
	int answer = 0;
	for(int i = 0; i < s.size(); i++) {
		int x = binpow(26, s.size() - i - 1) * (s[i] - 64);
		answer += x;
	}
	return answer;
}

void RC(string s) {
	string answer;
	string row, column;
	int i = 1;
	while(s[i] != 'C') {
		row.push_back(s[i]);
		i++;
	}
	i++;
	for(;i < s.size(); i++) {
		column.push_back(s[i]);
	}
	//int num = stoi(column);
	int num = 0;
    for(int j = 0; j < column.size(); j++) {
        num += binpow(10, column.size() - 1 - j) * (column[j] - 48);
    }
	string in_column = inverse(num);
	cout << in_column << row << endl;
}

void AA(string s) {
	string row, column;
	int i = 0;
	while (s[i] >= 65) {
		column.push_back(s[i]);
		i++;
	}
	for(; i< s.size(); i++) {
		row.push_back(s[i]);
	}
	int in_column = reinverse(column);
	cout << "R" << row << "C" << in_column << endl;
}

bool check(string s) {
	if (s[0] != 'R') 
		return false;
	if (s[1] > 64) 
		return false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'C')
			return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if(check(v[i])) {
			RC(v[i]);
		} else {
			AA(v[i]);
		}
	}
	return 0;
}