#include "Algorithm.h"



Algorithm::Algorithm(const std::string& name) : mName(name) {}


std::string Algorithm::getName() const
{
	return mName;
}
