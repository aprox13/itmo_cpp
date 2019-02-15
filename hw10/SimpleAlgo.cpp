#include "SimpleAlgo.h"
#include <algorithm>


SimpleAlgo::SimpleAlgo() : Algorithm("SimpleAlgorithm") {}

std::vector<Path> SimpleAlgo::getPaths(const size_t& k, const std::vector<Point>& points, const Metric &metric) const
{
	std::vector<int> permutation(points.size()), answer(points.size());
	std::vector<Path> result;
	double length = -1;
	int size = 1;
	for (size_t i = 0; i < points.size(); ++i) {
		permutation[i] = i;
	}
	do {
		double currentLength = 0;
		for (size_t i = 0; i < permutation.size() - 1; ++i) {
			if (size == k) {
				size = 1;
				continue;
			}
			++size;
			currentLength += metric.getWeight(points[permutation[i]], points[permutation[i + 1]]);
		}
		if (length == -1) {
			length = currentLength;
			answer = permutation;
		}
		else {
			if (length > currentLength) {
				length = currentLength;
				answer = permutation;
			}
		}
		size = 1;
	} while (std::next_permutation(permutation.begin(), permutation.end()));
	size = 0;
	Path temporary;
	for (size_t i = 0; i < answer.size(); ++i) {
		if (size == k) {
			result.push_back(temporary);
			temporary.clear();
			size = 0;
		}
		++size;
		auto p = points[answer[i]];
		temporary.add(p);
	}
	if (temporary.size() > 0) {
		result.push_back(temporary);
	}
	return result;
}

