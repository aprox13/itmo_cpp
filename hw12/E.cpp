#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdio>


int main() {
    int n, k, A, B, C, a1, a2;
    scanf("%d%d%d%d%d%d%d", &n, &k, &A, &B, &C, &a1, &a2);
    if (n != 1) {
        std::vector<int> base(n);
        base[0] = a1;
        base[1] = a2;
        for (int i = 2; i < n; ++i) { base[i] = A * base[i - 2] + B * base[i - 1] + C; }
        std::nth_element(base.begin(), base.begin() + (k - 1), base.end());
        printf("%d", base[k - 1]);
    } else {
        printf("%d", a1);
    }
    return 0;
}
