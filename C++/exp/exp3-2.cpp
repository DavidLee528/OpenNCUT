/*
 * @ Author: 李天昊
 * @ Description: 实验3-2
 * @ Date: 20210507
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>
#include <string>

using namespace std; 

class CDate {
private: 
    int d; 
    int m; 
    int y; 
public: 
    CDate(int _d, int _m, int _y): d(_d), m(_m), y(_y) {  }
    friend ostream & operator<<(ostream &os, CDate &d); 
}; 

ostream & operator<<(ostream &os, CDate &date) {
    os << date.d << "-" << date.m << "-" << date.y; 
    return os; 
}

class CTeacher {
private: 
    string m_name;      // 姓名
    CDate m_birthday;   // 出生日期
    string m_sex;       // 性别
    string m_address;   // 地址
    string m_phone_no;  // 电话号码
    string m_title;     // 职称
public: 
    CTeacher(
        const string &name, const CDate &birth, string sex, 
        const string &addr, const string &pho, const string &title): 
        m_name(name), m_birthday(birth), m_sex(sex), m_address(addr), m_phone_no(pho), m_title(title) {  }
protected: 
    void Display(ostream &os = cout); 
}; 

void CTeacher::Display(ostream &os) {
    os << " >> name:     " << m_name << endl; 
    os << "  | birthday: " << m_birthday << endl; 
    os << "  | sex:      " << m_sex << endl; 
    os << "  | address:  " << m_address << endl; 
    os << "  | phone:    " << m_phone_no << endl; 
    os << "  | title:    " << m_title << endl; 
}

class CCadre {
private: 
    string m_name;      // 姓名
    CDate m_birthday;   // 出生日期
    string m_sex;       // 性别
    string m_address;   // 地址
    string m_phone_no;  // 电话号码
    string m_post;      // 职务
public: 
    CCadre(
        const string &name, const CDate &birth, string sex, const string &addr, 
        const string &pho, const string &post): 
        m_name(name), m_birthday(birth), m_sex(sex), m_address(addr), m_phone_no(pho), m_post(post) {  }
protected: 
    string & get_post(); 
}; 

string & CCadre::get_post() {
    return m_post; 
}

class CTeacher_Cadre: public CTeacher, public CCadre {
private: 
    double m_wages; 
public: 
    CTeacher_Cadre(
        const string &name, const CDate &birth, string sex, const string &addr, 
        const string &pho, const string &title, const string &post, double wages): 
        CTeacher(name, birth, sex, addr, pho, title), CCadre(name, birth, sex, addr, pho, post), m_wages(wages) {  }
    void Show(); 
}; 

void CTeacher_Cadre::Show() {
    Display(); 
    cout << "  | post:     " << get_post() << endl; 
    cout << "  | wages:    " << m_wages << endl; 
}

int main() {
    CTeacher_Cadre tc("David", CDate(2002, 5, 28), "male", "Beijing, China", "13121515269", "title", "post", 12345.67); 
    tc.Show(); 
    return 0; 
}
