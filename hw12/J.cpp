#include <cstdio>
#include<string>
#include<vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using ExtTree = __gnu_pbds::tree<
        int,
        __gnu_pbds::null_type,
        std::less<>,
        __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update
>;


int main() {
    std::cin.tie(nullptr);
    std::ostream::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::stringstream res;
    ExtTree tree;
    int n, query, x;
    std::cin >> n;
    for (int test = 1; test <= n; ++test) {
        std::cin >> query >> x;
        switch (query) {
            case -1:
                tree.erase(x);
                break;
            case 0:
                res << *tree.find_by_order(tree.size() - x) << '\n';
                break;
            default:
                tree.insert(x);
                break;
        }
    }
    std::cout << res.str();
    return 0;
}