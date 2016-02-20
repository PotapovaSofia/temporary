#include <iostream>

using namespace std;

int main() {
    string c;
    int k = 0, l = 0;
    while (getline(cin , c)) {
        switch (c[0]) {
            case ('+'): {
                k++;
                break;
            }
            case ('-'): {
                k--;
                break;
            }
            default: {
                size_t pos = c.find(':');
                l += k*(c.length() - pos - 1);
                break;
            }
        }
    }
    cout << l << endl;
    return 0;
}