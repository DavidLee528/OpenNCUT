/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 
 * @ E-mail: 13121515269@163.com
 */
#include <iostream>
#include <cmath>

using namespace std; 

/* ============================================================== */
/*                        CLASS - CPoint                          */
/* ============================================================== */

class CPoint {
private: 
	double x; 
	double y; 
public: 
	// Constructor
	CPoint(double _x, double _y): x(_x), y(_y) {  }
	// Destructor
	~CPoint() {	}
	// Calculate distance between points in parameter
	friend double Distance(const CPoint &lhs, const CPoint &rhs); 
	// Overload the operator "<<" in order to make better display
	friend ostream & operator<<(ostream &os, const CPoint &rhs); 
};

double Distance(const CPoint &lhs, const CPoint &rhs) {
	return sqrt(pow(lhs.x - rhs.x, 2) + pow(lhs.y - rhs.y, 2)); 
}

ostream & operator<<(ostream &os, const CPoint &rhs) {
	os << "(" << rhs.x << ", " << rhs.y << ")"; 
}


/* ============================================================== */
/*                       CLASS - CCircle                          */
/* ============================================================== */

class CCircle {
private: 
	double radius; 
	CPoint point; 
	static double PI; 
public: 
	// Constructor
	CCircle(double _x = 0.0, double _y = 0.0, double _radius = 0.0): 
	point(CPoint(_x, _y)), radius(_radius) {  }
	// Destructor
	~CCircle() {  }
	// Calculate Area
	double Area() {
		return PI * radius * radius; 
	}
	// Calculate P2P distance by using function "Distance"
	double PointToPoint(const CPoint &rhs) {
		return Distance(rhs, point); 
	}
	// Show circle area
	void ShowArea(ostream &os = cout) {
		os << "> The area is " << Area() << ". " << endl; 
	}
	// Show the distance between circle centre point and parameter point
	void ShowDistance(const CPoint &lhs, ostream &os = cout) {
		os << "> The distance between " << lhs << " and "; //
		os << point << " is " << PointToPoint(lhs) << endl; 
	}
};

double CCircle::PI = 3.14; 


// main

int main() {
	
	// Init objects
	CCircle c(1, 2, 5); 
	CPoint p(7, 10); 
	
	// Test
	c.ShowArea(); 
	c.ShowDistance(p); 

	return 0; 
}



//Student *p=new Student;
//fstream
//多级继承 error_category
// const int hour {}
// 成员函数（）  最右端   
// void D ::f()
