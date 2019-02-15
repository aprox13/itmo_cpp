#include <cstdio>
#include<string>
#include<vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <tuple>
#include <unordered_map>


int main() {
    std::cin.tie(nullptr);
    std::ostream::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::stringstream res;

    //bool test  = false;

    size_t n;
    std::cin >> n;
    std::vector<int> base(n);
    for (int i = 0; i < n; i++) {
        std::cin >> base[i];
    }

    size_t m;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        int k;
        std::cin >> k;
        auto first = std::lower_bound(base.begin(), base.end(), k);
        if (*first == k) {
            auto second = std::upper_bound(base.begin(), base.end(), k);
            second--;
            res << (first - base.begin()) + 1 << ' ' << 1 + (second - base.begin()) << '\n';
        } else {
            res << "-1 -1\n";
        }
    }

    std::cout << res.str();
    return 0;
}
