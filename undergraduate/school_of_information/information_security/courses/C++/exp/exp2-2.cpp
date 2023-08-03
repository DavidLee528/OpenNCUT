/*
 * @ Author: 李天昊
 * @ Description: 实验2-2
 * @ Date: 20210403
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>

using namespace std; 

class CSale {
private: 
    string num; 
    size_t quantity; 

    static double sm_discount; 
    static double sm_sum; 
    static size_t sm_total_quantity; 
    static double sm_avg_price; 
    const double PRICE = 22.5; 

public: 
    CSale() = default; 
    ~CSale(); 

    inline static void set_discount(double dis); 
    inline void set_sales_data(string n, size_t q); 
    static void Average(); 
    inline static void Display(); 

}; 

double CSale::sm_discount = 1.0; 
double CSale::sm_sum = 0.0; 
size_t CSale::sm_total_quantity = 0; 
double CSale::sm_avg_price = 0.0; 

CSale::~CSale() {
    --sm_total_quantity; 
    sm_sum -= quantity * PRICE * sm_discount; 
}

inline void CSale::set_discount(double dis) {
    sm_discount = dis; 
}

inline void CSale::set_sales_data(string n, size_t q) {
    num = n; 
    quantity = q; 
    sm_total_quantity += q; 
    sm_sum += quantity * PRICE * sm_discount; 
}

void CSale::Average() {
    sm_avg_price = sm_sum / sm_total_quantity; 
}

inline void CSale::Display() {
    Average(); 
    cout << "The actual price is " << sm_avg_price << ". " << endl; 
    cout << "The total sale revenue is " << sm_sum << ". " << endl; 
}

int main() {
    CSale s[3]; 
    cout << " > Set Discount: "; 
    double d; 
    cin >> d; 
    CSale::set_discount(d); 
    for (size_t i = 0; i != sizeof(s) / sizeof(CSale); ++i) {
        cout << " > Set Num and Quantity: " << endl; 
        string num; 
        size_t quan; 
        cin >> num >> quan; 
        s[i].set_sales_data(num, quan); 
    }
    CSale::Display(); 
    return 0; 
}
