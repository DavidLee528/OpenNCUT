/**
 * @file 长度可变的整型数组类.cpp
 * @author 李天昊(13121515269@163.com)
 * @brief 实现可变长数组类CArray(via Coursera)
 * @version 0.2
 * @date 2021-01-22
 */

#define NDEBUG
#include<iostream>
#include<cstring>

using namespace std; 

/**
 * @brief CArray类功能需求(仿照标准库类型vector):
 *  1. 实现push_back函数，向数组尾部压入一个整型数据
 *  2. 实现CArray对象之间的赋值操作
 *  3. 实现CArray对象长度(元素个数)查询功能
 *  4. 支持下标法元素访问
 */
class CArray {
    private:
        int size;   // 数组元素的个数
        int *ptr;   // 指向动态分配的数组
    public:
        CArray(int s = 0);  // 构造函数,缺省值为0
        CArray(CArray &a);  // 复制构造函数
        ~CArray();          // 析构函数
        void push_back(int v);                      // 在数组尾部添加一个元素v
        CArray & operator = (const CArray &a);      // 重载运算符，用于数组对象间的赋值
        int length();                               // 用以返回数组元素个数
        int & operator [] (int i);                  // 用以支持下标法元素访问
}; 

CArray::CArray(int s): size(s) {
    if (s == 0) ptr = nullptr;  // 若数组长度为零，则数组为空
    else ptr = new int[s];      // 若数组长度非零，则申请长度为s内存空间
}

CArray::CArray(CArray &a) {
    if (!a.ptr) {               // 判断参数a是否为空对象，若为空，则：
        ptr = nullptr;          // 1. 定义空指针
        size = 0;               // 2. 数组长度为0
        return ; 
    }                                           // 若非空，则：
    ptr = new int[a.size];                      // 1. 申请长度为a.size的内存空间
    memcpy(ptr, a.ptr, sizeof(int) * a.size);   // 2. 执行复制操作
    size = a.size;                              // 3. 同步复制size属性
}

CArray::~CArray() {
    if (ptr) delete [] ptr;     // 若数组非空，则回收内存空间
}

CArray & CArray::operator = (const CArray &a) {
    if (ptr == a.ptr) return *this;             // 当左值和右值相同时，直接返回this指针
    if (a.ptr == nullptr) {                     // 判断右值对象a的指针是否为空，若是，则：
        if (ptr) delete [] ptr;                 // 1. 若指针非空，则删除对应空间
        ptr = nullptr;                          // 2. 左值对象的ptr属性置为空
        size = 0;                               // 3. 左值对象的size属性置为零
        return *this;                           // 4. 返回this指针
    }
    if (size < a.size) {                        // 判断左值对象size属性是否小于右值对象，若是，则：
        if (ptr) delete [] ptr;                 // 1. 若左值对象ptr非空，则删除对应空间
        ptr = new int[a.size];                  // 2. 在左值对象ptr位置申请大小为a.size的内存空间
    }
    memcpy(ptr, a.ptr, sizeof(int) * a.size);   // 执行复制操作
    size = a.size;                              // 同步复制size属性
    return *this;                               // 返回this指针
}

void CArray::push_back(int v) {
    if (ptr) {                                      // 判断指针是否非空，若是，则：
        int *tmpPtr = new int[size + 1];            // 1. 创建临时指针保存size+1长的空间
        memcpy(tmpPtr, ptr, sizeof(int) * size);    // 2. 拷贝原数组
        delete [] ptr;                              // 3. 删除原数组内存空间
        ptr = tmpPtr;                               // 4. 对原数组进行赋值
    } else {                                        // 若否，则：
        ptr = new int[1];                           // 1. 申请长度为1的新内存空间
    }
    ptr[size++] = v;                                // 将变量v添加到数组尾后并自增size属性值
}

inline int CArray::length() {
    return size;    // 返回数组大小
}

inline int & CArray::operator [] (int i) {
    return ptr[i];  // 返回数组中i位置的元素
}


// 类的测试部分
int main() {
    #ifndef NDEBUG
    CArray a(9); 
    CArray b; 
    for (size_t i = 0; i < a.length(); ++i) {
        a[i] = i + 1; 
    }
    a.push_back(10); 
    b = a; 
    cout << "size of b: " << b.length() << endl; 
    cout << "CArray b: "; 
    for (size_t i = 0; i < b.length(); ++i) {
        cout << b[i] << ' '; 
    }
    cout << endl; 
    #endif
    return 0; 
}
