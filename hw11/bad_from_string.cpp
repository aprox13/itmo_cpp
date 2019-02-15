#include "bad_from_string.h"


BadFromString::BadFromString(const std::string& message) : mMessage(message) {}

std::string BadFromString::what() noexcept {
	return mMessage;
}