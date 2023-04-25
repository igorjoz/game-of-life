#pragma once


#include <iostream>


class Point
{
public:
	int x;
	int y;

	Point();
	Point(int x, int y);

	~Point();

	friend std::ostream& operator<<(std::ostream& os, const Point& point);

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;

	Point& operator=(const Point& other);
};

