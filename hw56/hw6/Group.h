#pragma once

#include <iostream>
#include <vector>
#include <string>

typedef std::vector<std::string> vstr;

class Group{
    vstr group;
public:
    Group(const vstr& students);

    Group operator+(std::string student);
    Group operator-(std::string student);
    Group operator+();
    Group operator-();





    friend std::ostream& operator<<(std::ostream& os, const Group& g){
        int num = 1;
        for(const auto& name: g.group){
            os << num++ << ". " << name << std::endl;
        }
        return os;
    }

private:
};