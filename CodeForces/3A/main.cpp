#include <iostream>

using namespace std;

int main() {
    int table[8][8];
    char a, b;
    int x0, y0, x, y;
    cin >> a >> y;
    switch (a) {
        case ('a'): { x = 1; break; }
        case ('b'): { x = 2; break; }
        case ('c'): { x = 3; break; }
        case ('d'): { x = 4; break; }
        case ('e'): { x = 5; break; }
        case ('f'): { x = 6; break; }
        case ('g'): { x = 7; break; }
        case ('h'): { x = 8; break; }
    }
    cin >> b >> y0;
    switch (b) {
        case ('a'): { x0 = 1; break; }
        case ('b'): { x0 = 2; break; }
        case ('c'): { x0 = 3; break; }
        case ('d'): { x0 = 4; break; }
        case ('e'): { x0 = 5; break; }
        case ('f'): { x0 = 6; break; }
        case ('g'): { x0 = 7; break; }
        case ('h'): { x0 = 8; break; }
    }
    int k = 0;
    int x_ = x, y_ = y;
    while (true) {
        if (x_ == x0 && y_ == y0) break;
        if (x_ > x0) {
            x_--;
        } else if (x_ < x0) {
            x_++;
        }
        if (y_ > y0) {
            y_--;
        } else if (y_ < y0) {
            y_++;
        }
        k++;
    }
    cout << k << endl;

    while (true) {
        if (x == x0 && y == y0) break;
        if (x > x0) {
            x--;
            cout << "L";
        } else if (x < x0) {
            x++;
            cout << "R";
        }
        if (y > y0) {
            y--;
            cout << "D";
        } else if (y < y0) {
            y++;
            cout << "U";
        }
        cout << endl;
    }

    return 0;
}