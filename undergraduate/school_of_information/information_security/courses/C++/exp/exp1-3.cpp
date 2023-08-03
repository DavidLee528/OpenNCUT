/*
 * @ Author: 李天昊
 * @ Description: 实验1-3
 * @ Date: 20210330
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>
#include <cmath>

using namespace std; 

// =========================================================================================== //
//                                       CLASS START                                           //
// =========================================================================================== //

class CCube {
private: 
    double m_length; 
    double m_width; 
    double m_height; 
    double m_volume; 
    static size_t sm_nTotalVolume; 
    static size_t sm_nTotalNumber; 
public: 
    CCube(); 
    CCube(double l, double w, double h); 
    CCube(const CCube &r); 
    ~CCube(); 

    void set_value(istream &is = cin); 
    inline double get_volume(); 

    inline static void PrintTotal(); 
}; 

size_t CCube::sm_nTotalVolume = 0; 
size_t CCube::sm_nTotalNumber = 0; 

CCube::CCube() {
    m_volume = -1; 
}

CCube::CCube(double l, double w, double h) {
    if (l < 0) throw "Invalid Length Value"; 
    if (w < 0) throw "Invalid Width Value"; 
    if (h < 0) throw "Invalid Height Value"; 
    m_length = l; 
    m_width = w; 
    m_height = h; 
    m_volume = m_length * m_width * m_height; 
    ++sm_nTotalNumber; 
    sm_nTotalVolume += m_volume; 
}

CCube::CCube(const CCube &r): m_length(r.m_length), m_width(r.m_width), m_height(r.m_height) {  }

CCube::~CCube() { 
    --sm_nTotalNumber; 
    sm_nTotalVolume -= m_volume; 
}

void CCube::set_value(istream &is) {
    // 初次设置长宽高
    if (m_volume == -1) {
        ++sm_nTotalNumber; 
        m_volume = 0; 
    }
    // 从总体积中减去旧体积值
    sm_nTotalVolume -= m_volume; 
    cout << "> set length, width and height: "; 
    is >> m_length; 
    is >> m_width; 
    is >> m_height; 
    // 计算并累加新体积值
    m_volume = m_length * m_width * m_height; 
    sm_nTotalVolume += m_volume; 
}

inline double CCube::get_volume() {
    return m_volume; 
}

inline void CCube::PrintTotal() {
    cout << "The volume of " << sm_nTotalNumber << " cubes is " << sm_nTotalVolume << "." << endl; 
}

// =========================================================================================== //
//                                        CLASS END                                            //
// =========================================================================================== //

int main() {

    // 定义CCube类数组并打印初始数量和体积
    CCube c[3]; 
    CCube::PrintTotal(); 
    cout << endl; 

    for (size_t i = 0; i != 3; ++i) {
        // 输入长宽高并打印体积
        c[i].set_value(); 
        cout << "> " << c[i].get_volume() << endl; 
        // 打印累计数量和体积
        CCube::PrintTotal(); 
        cout << endl; 
    }
    return 0; 
}

