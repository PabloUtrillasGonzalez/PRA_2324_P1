#include <iostream>
#include <ostream>
#include "Shape.h"
#include <string>
#include <cmath>
#include "Point2D.h"
#include "Circle.h"

using namespace std;


        Circle::Circle(){
                this->center = Point2D(0.0,0.0);
                this->radius = 1;
                this->color = "red";

        }
        Circle::Circle(string color, Point2D center, double radius){
                this->color = color;
                this->center = center;
                this->radius = radius;

        }

        Point2D Circle::get_center()const{
                return center;
        }

        void Circle::set_center(Point2D p){
                center = p;
        }

        double Circle::get_radius()const{
                return radius;
        }

        void Circle::set_radius(double r){
                radius = r;
        }

        std::ostream&operator<<(std::ostream &out, const Circle &c){
                out << "[Circle: color = "<< c.color << "; center = " << c.center << "; radius = " << c.radius << "]";
                return out;
        }

        double Circle::area() const{
                return (pow(this->radius,2) * M_PI); // Radio^2 * PI
        }

        double Circle::perimeter() const{
                return ((radius*2) * M_PI); // Diametro por PI
        }

        void Circle::translate(double incX, double incY){
                // No idea que hace esto
                //this->center.translate(incX,incY);    
        }

        void Circle::print(){
                cout << "[Circle: color = "<< color << "; center = " << center << "; radius = " << radius << "]";
        }

