#include <iostream>
#include <string>

using namespace std; 

class Bill {
private: 
	string idx;    // idx is short of index
	size_t amount; 
	double price; 
public: 
	// Constructor
	Bill(string _idx = "000", size_t _amount = 0, double _price = 0.0): 
	idx(_idx), amount(_amount), price(_price) {  }
	// Destructor
	~Bill() {  }
	// Calculate and show total price
	void Sum(); 
};

void Bill::Sum() {
	cout << "> Total price of " << idx << " is " << amount * price << ". " << endl; 
}

int main() {
	
	Bill b("001", 123, 99.9); 
	b.Sum(); 
	
	return 0; 
}
