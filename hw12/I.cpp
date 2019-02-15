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

    std::unordered_map<std::string, std::string> container;
    std::string query, key;
    while (std::cin >> query){
        std::cin >> key;
        switch(query[0]){
            case 'p':
                std::cin >> container[key];// = value;
                break;
            case 'g':
                if(container.count(key) != 0)
                    res << container[key] << '\n';
                else
                    res << "none\n";
                break;
            default:
                container.erase(key);
                break;
                /*default:
                    test = true;*/
        }
        //  if ( test ) break;
    }
    std::cout << res.str();
    return 0;
}