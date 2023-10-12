#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>
#include <cmath>

using namespace std;

class Point2D{

	public:
		double x;
		double y;


		Point2D(double x2=0,double y2=0){
			x = x2;
			y = y2;
		}

		static double distance(const Point2D &a, const Point2D &b){
			double dist = sqrt((pow((a.x - b.x),2) + pow((a.y-b.y),2)));

			return dist;
		}
		
		friend bool operator==(const Point2D &a, const Point2D &b){
			return ((a.x == b.x) && (a.y == b.y));
                }

		friend bool operator!=(const Point2D &a, const Point2D &b){
			return ((a.x != b.x) || (a.y != b.y));
		
		}

		friend std::ostream& operator<<(std::ostream &out, const Point2D &p){
			out << p.x << " " << p.y << endl; 
			return out;
		}

    // ... definición de la clase Point2D.h ...  
};
#endif
