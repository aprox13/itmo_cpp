#pragma once
#include "Metric.h"
class ChairMetric :
	public Metric
{
public:
	ChairMetric();
	double getWeight(const Point&, const Point&) const override;
};

