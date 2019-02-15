#pragma once
#include<string>

using Point = std::pair<int, int>;

class Metric
{
public:
	Metric(const std::string&);
	virtual double getWeight(const Point&, const Point&)  const = 0;
	std::string getName() const;

private:
	std::string mName;
};

