#include "ChairMetric.h"




ChairMetric::

ChairMetric::ChairMetric() : Metric("Chair metric")
{
}

double ChairMetric::getWeight(const Point& a, const Point& b) const
{
	return a == b? 0: 1;
}

