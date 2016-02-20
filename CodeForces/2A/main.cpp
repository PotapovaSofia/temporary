#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>

#define mp make_pair
using namespace std;

int main() {
    int n, score;
    string name;
    vector<pair<string, int>> game;
    map<string, int> players;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> name >> score;
        game.push_back(mp(name, score));
        std::pair<std::map<string,int>::iterator,bool> ret = players.insert(mp(name, score));
        if(!ret.second) {
            ret.first->second += score;
        }
    }

    int max = 0;
    for (auto w: players) {
        if (w.second >= max) {
            max = w.second;
        }
    }
    vector<string> winners;
    for (auto w: players) {
        if (w.second == max) {
            winners.push_back(w.first);
        }
    }
    //cout << winner << max;
    if (winners.size() > 1) {
        players.clear();
        for (auto g: game) {
            if (find(winners.begin(), winners.end(), g.first) != winners.end()) {
                std::pair<std::map<string, int>::iterator, bool> ret = players.insert(mp(g.first, g.second));
                if (!ret.second) {
                    ret.first->second += g.second;
                }
                if (ret.first->second >= max) {
                    cout << ret.first->first;
                    break;
                }
            }
        }
    } else {
        cout << winners[0];
    }
    return 0;
}