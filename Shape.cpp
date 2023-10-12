#include <string>
#include "Shape.h"

using namespace std;

        Shape::Shape(){}

        Shape::Shape(string color){
		if(color == "red" || color == "green" || color == "blue"){
			Shape* s1 = new Shape();
	                s1->color = color;
		}else{
			throw invalid_argument("Color incorrecto");
		}

	}

        string Shape::get_color() const{
		return color;
	}

        void Shape::set_color(string c){
		string color = c;
	}
