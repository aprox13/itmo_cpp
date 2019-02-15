#pragma once
#include "Metric.h"
class EvklidMetric :
	public Metric
{
public:
	EvklidMetric();

	double getWeight(const Point&, const Point&) const override;
};

