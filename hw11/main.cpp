#include<iostream>
#include<typeinfo>
#include<sstream>
#include "bad_from_string.h"

struct G {
	int a;
};

template<class T>
T from_string(const std::string & s)
{
	if (s.empty()) { throw BadFromString("Source string is empty"); }
	T result;
	std::istringstream stream(s);
	stream >> std::noskipws;
	stream >> result;
	if (stream.fail() || stream.peek() != std::char_traits<char>::eof()) {
		throw BadFromString("Error while converting '" + s + "' to " + typeid(T).name());
	}
	return result;
}


template<class T>
void test(const std::string& s) {
	std::cout << "Converting '" + s + "' to " + typeid(T).name() << " -> ";
	try {
		std::cout << "Result: " << from_string<T>(s) << std::endl; 
	}
	catch (BadFromString& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}


void chapter(const std::string& name) {
	std::cout << "\n##\n" << name << "\n##\n\n";
}


int main() {


	chapter("int");
	test<size_t>("+10");
	test<int>("10");
	test<int>(" 10");
	test<int>("10 ");
	test<int>("100000000000000000000000000000000000000000000000000000000000000000000000000");
	test<int>("10.0");
	test<unsigned>("-1");

	chapter("std::string");
	test<std::string>("");
	test<std::string>(" ");
	test<std::string>(" aba");
	test<std::string>("aba");

	chapter("char");
	test<char>(" ");
	test<char>("10");
	test<char>("a");


	chapter("double");
	test<double>("10");
	test<double>(" 10");
	test<double>("10.1");


	

	system("pause");
	return 0;
}