#include <iostream>
#include <ostream>
#include "Shape.h"
#include <string>
#include <cmath>
#include "Point2D.h"

using namespace std;

class Circle : public Shape{
	private:

	Point2D center;
	double radius;	



	public:
	
	Circle(){
		this->center = Point2D(0.0,0.0);
		this->radius = 1;
		this->color = "red";

	}
	Circle(string color, Point2D center, double radius){
		this->color = color;
		this->center = center;
		this->radius = radius;

	}

	Point2D get_center()const{
		return center;
	}

	void set_center(Point2D p){
		this->center = p;
	}

	double get_radius()const{
		return radius;
	}

	void set_radius(double r){
		this->radius = r;
	}

	friend std::ostream&operator<<(std::ostream &out, const Circle &c){
		out << c.get_center() << " " << c.get_radius();
		return out;
	}

        double area() const override{
		return (pow(this->radius,2) * M_PI); // Radio^2 * PI
	}

        double perimeter() const override{
		return ((radius*2) * M_PI); // Diametro por PI
	}

        void translate(double incX, double incY) override{
		// No idea que hace esto
		//this->center.translate(incX,incY);	
	}

        void print() override{
		cout << "Circulo con Radio:" << radius << " y Centro:" << center;
	}
};
