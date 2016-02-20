#include <cstdio>
#include <math.h>
#include <iostream>

int main() {
    double m, n, a;
    scanf("%lf%lf%lf", &m, &n, &a);

    std::cout << (long long)(ceil(n/a)*ceil(m/a));
    return 0;
}