#include <cstdio>
#include<string>
#include<vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <tuple>


using team = std::tuple<size_t, short, size_t>;

#define GET(tpl, idx) std::get<idx>(tpl)

struct TeamCMP {
    bool operator()(const team& first, const team& second) {

        short S1, S2;

        if ((S1 = GET(first, 1)) == (S2 = GET(second, 1))) {
            size_t T1, T2;
            if((T1 = GET(first, 2)) == (T2 = GET(second, 2))){
                return GET(first, 0) < GET(second, 0);
            }
            return T1 < T2;
        }
        return S1 > S2;
    }
};

int main() {
    std::cin.tie(nullptr);
    std::ostream::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::stringstream res;

    std::size_t n;
    std::cin >> n;
    std::vector<team> vec(n);

    short S;
    int T;
    for (auto i = 0; i < n; ++i) {
        std::cin >> S >> T;
        vec[i] = std::make_tuple(i + 1, S, T);
    }
    std::sort(vec.begin(), vec.end(), TeamCMP());

    for(auto i = 0; i < n; ++i){
        res << GET(vec[i], 0) << ' ';
    }

    std::cout << res.str();
    return 0;
}