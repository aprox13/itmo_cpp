#include <cstdio>
#include<string>
#include<vector>
#include <algorithm>
#include <sstream>
#include <iostream>

int main() {
    std::cin.tie(nullptr);
    std::ostream::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::stringstream res;

    unsigned n;
    unsigned i;
    std::cin >> n;

    std::vector<int> p(n);//{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(i = 0; i < n; i++){
        p[i] = i + 1;
    }
    do {
        for (i = 0; i < n; i++) {
            res << p[i] << ' ';
        }
        res << '\n';
    } while (std::next_permutation(p.begin(), p.begin() + n));

    std::cout << res.str();
    return 0;
}