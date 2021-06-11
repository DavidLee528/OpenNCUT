#include <iostream>

using namespace std; 

const size_t MAX_CONTAINER_SIZE = 100; 

/* =========================================== */
/*          BASE CLASS - CContainer            */
/* =========================================== */

class CContainer {
protected: 
    double radius; 
public:
    CContainer(double r): radius(r) {  }
    // Calculate surface area
    virtual double Area() = 0; 
    // print surface area
    virtual void printArea() = 0; 
}; 

/* =========================================== */
/*           DERIVED CLASS - CCube             */
/* =========================================== */

class CCube: public CContainer {
public: 
    CCube(double r): CContainer(r) {  }
    virtual double Area(); 
    virtual void printArea(); 
}; 

double CCube::Area() {
    return 6 * radius * radius; 
}

void CCube::printArea() {
    cout << "> Cube surface area is " << Area() << endl; 
}

/* =========================================== */
/*           DERIVED CLASS - CBall             */
/* =========================================== */

class CBall: public CContainer {
private: 
    const double PI = 3.1415926; 
public: 
    CBall(double r): CContainer(r) {  }
    virtual double Area(); 
    virtual void printArea(); 
};

double CBall::Area() {
    return 4 * PI * radius * radius; 
}

void CBall::printArea() {
    cout << "> Ball surface area is " << Area() << endl; 
}

/* =========================================== */
/*         DERIVED CLASS - CCylinder           */
/* =========================================== */

class CCylinder: public CContainer {
private: 
    const double PI = 3.1415926; 
    double height; 
public: 
    CCylinder(double r, double h): CContainer(r), height(h) {  }
    virtual double Area(); 
    virtual void printArea(); 
}; 

double CCylinder::Area() {
    return (2 * PI * radius *radius) + (height * 2 * PI * radius); 
}

void CCylinder::printArea() {
    cout << "> Cylinder surface area is " << Area() << endl; 
}

// CContainer *pContainers[MAX_CONTAINER_SIZE]; 

int main() {

    CContainer* p = nullptr;

    p = new CCube(123.456); 
    p->printArea(); 
    
    p = new CBall(123.456); 
    p->printArea(); 

    p = new CCylinder(123.456, 78.90); 
    p->printArea(); 

    return 0; 
}

