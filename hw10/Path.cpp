#include "Path.h"
#include "Metric.h"



Path::~Path()
{
	mBase.erase(mBase.begin(), mBase.end());
}

std::ostream & operator<<(std::ostream &os, const Path &path)
{
	for (auto p : path.mBase) {
		os << "(" << p.first << ", " << p.second << ") ";
	}
	return os;
}

void Path::add(const Point & p) 
{
	mBase.emplace_back(p);
}

void Path::clear()
{
	mBase.clear();
}

size_t Path::size() const
{
	return mBase.size();
}

Point& Path::operator[](size_t i)
{
	return mBase[i];
}

const Point& Path::operator[](size_t i) const
{
	return mBase[i];
}
