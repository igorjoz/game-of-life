#include "Point.h"


Point::Point() : x{ 0 }, y{ 0 } {
}


Point::Point(int x, int y) : x{ x }, y{ y } {
}


Point::~Point() {
}


std::ostream& operator<<(std::ostream& os, const Point& point) {
	os << "(" << point.x << ", " << point.y << ")";
	return os;
}


bool Point::operator==(const Point& other) const {
	return x == other.x && y == other.y;
}


bool Point::operator!=(const Point& other) const {
	return !(*this == other);
}


Point& Point::operator=(const Point& other) {
	x = other.x;
	y = other.y;
	return *this;
}