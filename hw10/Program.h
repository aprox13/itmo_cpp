#pragma once
#include "Algorithm.h"
#include "Metric.h"
#include "Path.h"
#include<vector>
#include<string>
#include<iostream>

/**
	Input arguments:
	-k:
		elements in path(default: 10)
		type: size_t
	-algo:
		Algorithm name(default: simple)
		available:
			simple - SimpleAlgo class
	-metric:
		Metric name(default: chair)
		available: 
			chair - Chair Metric class
			ev - Evklid
	-source
		Source file path. File format:
		n - count of points
		2*n numbers - x, y coordinates
*/
class Program
{
public:
	Program(const std::vector<std::pair<std::string, std::string>>&);

	std::vector<Path> getResult();
	static void help();

private:

	const char*  mKArgName = "-k";
	const char*  mSourceFileName = "-source";
	const char*  mAlgorithmName = "-algo";
	const char*  mMetricName = "-metric";
	const size_t DEFAULT_K = 10;

	Algorithm*   mAlgorithm;
	Metric*      mMetric;
	std::string  mSource;
	size_t       mK;
	bool         mWasAssert;

	std::vector<std::pair<int, int>> mPoints;

	void assertProgram(const std::string&);
	void setAlgo(const std::string&);
	void setMetric(const std::string&);
	void setK(const std::string&);
	void setSource(const std::string&);
	void read();
};

