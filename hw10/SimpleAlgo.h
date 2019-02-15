#pragma once
#include "Algorithm.h"
class SimpleAlgo : public Algorithm
{
public:
	SimpleAlgo();
	
	std::vector<Path> getPaths(const size_t&, const std::vector<Point>&, const Metric&) const override;
};

