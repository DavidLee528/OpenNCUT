#include <iostream>

using namespace std; 

/* ============================================================== */
/*                      BASE CLASS - Shape                        */
/* ============================================================== */

class Shape {
protected: 
	double length; 
public: 
	Shape(double _length): length(_length) {  }
	virtual double area() const = 0; 
};

/* ============================================================== */
/*                  DERIVED CLASS - Rectangle                     */
/* ============================================================== */

class Rectangle: public Shape {
private: 
	double height; 
public: 
	// Constructor
	Rectangle(double _length = 0.0, double _height = 0.0): 
	Shape(_length), height(_height) {  }
	// Destructor
	~Rectangle() {  }
	// Calculate Area
	virtual double area() const; 
};

double Rectangle::area() const {
	return length * height; 
}

/* ============================================================== */
/*                    DERIVED CLASS - Square                      */
/* ============================================================== */

class Square: public Shape {
public: 
	// Constructor
	Square(double _length = 0.0): Shape(_length) {	}
	// Destructor
	~Square() {	}
	// Calculate Area
	virtual double area() const; 
};

double Square::area() const {
	return length * length; 
}



// Calculate and show area on screen
void ShowArea(const Shape *rhs) {
	cout << "The area is " << rhs->area() << ". " << endl; 
}

int main() {
	
	Shape *s = NULL; 
	
	s = new Rectangle(1.2, 3.4); 
	ShowArea(s); 
	
	s = new Square(5.6); 
	ShowArea(s); 
	
	return 0; 
}
