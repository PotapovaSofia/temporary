#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


string inverse(int number){
	string answer;
	int x, y;
	while(number) {
		x = number % 26;
		y = number / 26;
		number = y;
		answer.push_back(97 + x);
	}
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
	while(s[i] != '\n') {
	row.push_back(s[i]);
		i++;	
	}
	/*
	int num = 0;
	for(int j = 0; j < column.size(); j++) {
		num += stoi(column[j]) * pow(10, j);
	}
	*/
	string in_column = inverse(stoi(column));
	cout << in_column << row << endl;
}


void AA(string s) {

}

int main() {
	int n;
	cin >> n;
	vector<string> vct(n);
	for (int i = 0; i < n; i++) {
		cin >> vct[i];
		cout << vct[i];
	}
	cout << "hi";
	fflush(stdin);
	for (int i = 0; i < n; i++) {
		if (vct[i][0] == 'R'){
			cout << "hi";
			 RC(vct[i]);
		} else AA(vct[i]);
	}
	return 0;
}