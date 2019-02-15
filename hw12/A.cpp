#include <cstdio>
#include<string>
#include<vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <tuple>
#include <fstream>
#include <set>


int main() {
    std::cin.tie(nullptr);
    std::ostream::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::stringstream res;

  //  std::ifstream in("test.in");
    bool test = false;

    std::set<int> container;
    std::string query;
    int key;
    while (std::cin >> query) {
        std::cin >> key;
        switch (query[0]) {
            case 'i': {
                container.insert(key);// = value;
                break;
            }
            case 'e': {
                if (container.count(key) != 0)
                    res << "true\n";
                else
                    res << "false\n";
                break;
            }
            case 'd': {
                container.erase(key);
                break;
            }
            case 'p': {
                if (container.empty()) {
                    res << "none\n";
                    break;
                }
                auto it = container.lower_bound(key);
                if (it == container.begin()) {
                    res << "none\n";
                    break;
                }
                res << *(--it) << '\n';
                break;
            }
            case 'n': {
                if (container.empty()) {
                    res << "none\n";
                    break;
                }
                auto next = container.upper_bound(key);
                if (next == container.end()) {
                    res << "none\n";
                    break;
                }
                res << *next << '\n';
                break;
            }
          /*  default:
                test = true;*/
        }
 //       if (test) break;
    }
    std::cout << res.str();
    return 0;
}