#include <cstdio>
#include<string>
#include<vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <tuple>
#include <unordered_set>


int main() {
    std::cin.tie(nullptr);
    std::ostream::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::stringstream res;

    bool test = false;

    std::unordered_set<int> container;
    //std::unordered_map<std::string, std::string> container;
    std::string query;
    int key;
    while (std::getline(std::cin, query)) {
        //std::cin >> key;
        //  std::cout << "query: '" << query << "'\n";
        key = 0;
        for (int i = 7; i < query.size(); i++) {
            key *= 10;
            key += (query[i] - '0');
        }
        switch (query[0]) {
            case 'i':
                //std::cin >> key;
                container.insert(key);// = value;
                break;
            case 'e':
                if (container.count(key) != 0)
                    res << "true\n";
                else
                    res << "false\n";
                break;
            case 'd':
                container.erase(key);
                break;
            default:
                test = true;
        }
       // if (test) break;
    }
    std::cout << res.str();
    return 0;
}