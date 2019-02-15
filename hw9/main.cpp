#include <iostream>
#include <tuple>
#include <algorithm>

void print_values() {}

template<class T, class... Args>
void print_values(const T& value, const Args& ... args) {
    std::cout << typeid(value).name() << ": " << value << std::endl;
    print_values(args...);
}


template<int FirstIndex, int SecondIndex, class... T>
auto to_pair(const std::tuple<T...>& t) -> decltype(std::make_pair(std::get<FirstIndex>(t), std::get<SecondIndex>(t))) {
    return std::make_pair(std::get<FirstIndex>(t), std::get<SecondIndex>(t));
}

int main() {
    std::cout << "Task #1" << std::endl;
    print_values(1, "mama", 2.5f, 2.5, 10l, static_cast<char>(48));
    std::cout << "\nTask #2\n";
    auto t = std::make_tuple(0, 3.5, "Hello");
    std::pair<double, char const*> p = to_pair<1, 2>(t);
    std::cout << p.first << " " << p.second << std::endl;
    return 0;
}