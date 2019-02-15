#pragma once
#include<vector>
#include<iostream>


using Point = std::pair<int, int>;

class Path
{
public:

	Path() = default;
	~Path();

	void add(const Point&);
	void clear();
	size_t size() const;
	
	Point& operator[](size_t i);
	const Point& operator[](size_t i) const;

	friend std::ostream& operator<<(std::ostream&, const Path&);

private:
	std::vector<Point> mBase;
};

