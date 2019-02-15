#include <cstdio>
#include<string>
#include<queue>
#include <sstream>
#include <iostream>

int main() {
    std::cin.tie(nullptr);
    std::ostream::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    int m;
    std::queue<int> q;
    std::stringstream res;
    int n;
    char c;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        std::cin >> c;
        if (c == '+') {
            std::cin >> n;
            q.push(n);
        } else {
            res << (q.front()) << '\n';
            q.pop();
        }
    }
    std::cout << res.str();
    return 0;
}