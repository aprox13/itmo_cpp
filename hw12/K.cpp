#include <cstdio>
#include<string>
#include<vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <ext/rope>

int main() {
    std::cin.tie(nullptr);
    std::ostream::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::stringstream res;
    int n, m;
    size_t l, r;
    __gnu_cxx::rope<int> treap;

    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) { treap.push_back(i + 1); }
    for (int i = 0; i < m; ++i) {
        std::cin >> l >> r;
        auto sub = treap.substr(l - 1, r - l + 1);
        treap.erase(l - 1, r - l + 1);
        treap.insert(treap.mutable_begin(), sub);
    }
    for (auto it = treap.mutable_begin(); it != treap.mutable_end(); ++it) { res << *it << " "; }
    std::cout << res.str();
    return 0;
}