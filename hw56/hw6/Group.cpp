#include"Group.h"
#include <algorithm>


Group::Group(const vstr& students) {
    group = vstr();
    for(const auto& i: students){
        group.push_back(i);
    }

}

Group Group::operator+(std::string student) {
    group.push_back(student);
    return *this;
}

Group Group::operator-(std::string student) {
    for(auto& name: group){
        if(name == student){
            name = "";
            return *this;
        }
    }
}

Group Group::operator-() {
    if (group.back().empty()) {
        group.erase(group.begin() + group.size());
    }
    return *this;
}

Group Group::operator+() {
    group.push_back("");
    return *this;
}