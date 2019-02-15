#pragma once
#include"Metric.h"
#include"Path.h"
#include<vector>

using Point = std::pair<int, int>;

class Algorithm
{
public:
	Algorithm(const std::string& name);

	virtual std::vector<Path> getPaths(const size_t&, const std::vector<Point>&, const Metric&) const = 0;
	std::string getName() const;
private:
	std::string  mName;
};

