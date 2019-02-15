#include "Metric.h"

Metric::Metric(const std::string &name) : mName(name) {}


std::string Metric::getName() const
{
	return mName;
}

