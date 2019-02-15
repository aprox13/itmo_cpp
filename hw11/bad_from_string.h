#pragma once
#include<exception>
#include<string>

class BadFromString : public std::exception {
public:
	BadFromString(const std::string& message);

	std::string what() noexcept;

private:
	std::string mMessage;
};