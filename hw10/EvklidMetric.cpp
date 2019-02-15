#include "EvklidMetric.h"

#include<cmath>


EvklidMetric::EvklidMetric() : Metric("Evklid metric") {}

double EvklidMetric::getWeight(const Point& a, const Point& b) const
{
	auto first = a.first - b.first;
	auto second = b.second - a.second;
	return sqrt(first * first + second * second);
}




