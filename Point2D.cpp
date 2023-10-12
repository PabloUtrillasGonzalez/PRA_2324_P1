#include <ostream>
#include <cmath>
#include "point2D.h"

using namespace std;

Point2D::Point2D(double x=0.0,double y=0.0) : x(x), y(y) {}

double Point2D::Point2D::distance(const Point2D &a, const Point2D &b){
	double dist = sqrt((pow((a.x - b.x),2) + pow((a.y-b.y),2)));
	return dist;
}

bool operator==(const Point2D &a, const Point2D &b){
	return ((a.x == b.x) && (a.y == b.y));
}

bool operator!=(const Point2D &a, const Point2D &b){
	return ((a.x != b.x) || (a.y != b.y));
}

std::ostream& operator<<(std::ostream &out, const Point2D &p){
	out << p.x << " " << p.y << endl;
	return out;
}
