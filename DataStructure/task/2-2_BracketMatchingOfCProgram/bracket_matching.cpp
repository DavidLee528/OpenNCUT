#define NDEBUG
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <functional>
#include <map>
#include <fstream>

using namespace std; 

/**
 * @description: 删除C风格注释，包括行注释与块注释
 * @param {vector<string>&} src 源代码
 * @return {vector<string>} 去除注释后的代码
 */
vector<string> remove_comments(const vector<string> &src) {
    vector<string> ret { }; 
    string curr_line {""}; 
    bool isComment {false}; 
    for (auto line : src) {
        if (!isComment) curr_line = "";  
        string::size_type i {0}; 
        string::size_type len {line.length()}; 
        while (i < len) {
            if (!isComment && i < len - 1 && line.at(i) == '/' && line.at(i + 1) == '*') {
                isComment = true; 
                ++i; 
            } else if (isComment && i < len - 1 && line.at(i) == '*' && line.at(i + 1) == '/') {
                isComment = false; 
                ++i; 
            } else if (!isComment && i < len - 1 && line.at(i) == '/' && line.at(i + 1) == '/') {
                break; 
            } else if (!isComment) {
                curr_line += line.at(i); 
            }
            ++i; 
        }
        if (!isComment && !curr_line.empty()) ret.push_back(curr_line); 
    }
    return ret; 
}

/**
 * @description: 删除C代码中非括号部分
 * @param {vector<string>&} src
 * @return {vector<string>} 返回括号序列
 */
vector<string> make_bracket_string(const vector<string> &src) {
    vector<string> ret { }; 
    
    for (vector<string>::size_type i = 0; i < src.size(); ++i) {
        string newLine {""}; 
        bool isConstant = false; 
        for (string::size_type j = 0; j < src.at(i).length(); ++j) {
            if (isConstant && (src.at(i).at(j + 1) == '\'' || src.at(i).at(j) == '\"')) {
                isConstant = false; 
                continue; 
            }
            if (isConstant) continue; 
            if (src.at(i).at(j) == '(' || src.at(i).at(j) == ')') newLine += src.at(i).at(j); 
            if (src.at(i).at(j) == '[' || src.at(i).at(j) == ']') newLine += src.at(i).at(j); 
            if (src.at(i).at(j) == '{' || src.at(i).at(j) == '}') newLine += src.at(i).at(j); 
            if (src.at(i).at(j) == '\'' || src.at(i).at(j) == '\"') isConstant = true; 
        }
        ret.push_back(newLine); 
    }

    return ret; 
}

/**
 * @description: Check for parenthesis matching
 * @param {const string&} Bracket array
 * @param {size_t} index of error bracket
 * @return {bool} Return true if str is an avaliable bracket array
 */
bool is_matching(const std::string &str, size_t &errIndex) {
    char head { str.at(0) }; 
    char tail { str.at(str.length() - 1) }; 
    if (head == ')' || head == ']' || head == '}') return false; 
    if (tail == '(' || tail == '[' || tail == '{') return false; 

    using CmpFunc_t = std::function<bool(char)>; 
    CmpFunc_t cmp_s = [](char opt) noexcept -> bool { return opt == ')'; }; 
    CmpFunc_t cmp_m = [](char opt) noexcept -> bool { return opt == ']'; }; 
    CmpFunc_t cmp_l = [](char opt) noexcept -> bool { return opt == '}'; }; 

    std::stack<pair<char, size_t>> s { }; 
    std::map<char, CmpFunc_t> check {{'(', cmp_s}, {'[', cmp_m}, {'{', cmp_l}}; 

    size_t idx = 0; 
    for (std::string::const_iterator iter = str.cbegin(); iter != str.cend(); ++iter) {
        pair<char, size_t> elem {*iter, idx++}; 
        if (*iter == '(' || *iter == '[' || *iter == '{') {
            s.push(elem); 
            continue; 
        }
        if (check[s.top().first](*iter)) {
            s.pop(); 
            continue; 
        } 
        errIndex = elem.second;  
        return false; 
    }
    if (!s.empty()){
        errIndex = s.top().second; 
        return false; 
    }

    return true; 
}

vector<string> read_file(const string &filePath) {
    ifstream src(filePath, ios::in); 
    if (!src.is_open()) return vector<string>{"error"}; 

    string line {""}; 
    vector<string> ret { }; 
    while (getline(src, line)) ret.push_back(line); 

    src.close(); 
    return ret; 
}

// 测试部分
#ifndef NDEBUG

template<typename T> inline bool
EXPECT_EQ(const T &lhs, const T &rhs) {
    return lhs == rhs; 
}

bool TEST_REMOVE_COMMENTS() {
    string line { }; 
    vector<string> code { }; 
    while (getline(cin, line)) code.push_back(line); 

    cout << "source code: " << endl; 
    for (auto elem : code) {
        cout << elem << endl; 
    }
    cout << endl; 

    vector<string> s = remove_comments(code); 

    cout << "remove comments: " << endl; 
    for (auto elem : s) {
        cout << elem << endl; 
    }
    cout << endl; 
}

bool TEST_MAKE_BRACKET_STRING() {
    vector<string> src {
        "#include<stdio.h>", 
        "int main(){", 
        "printf(\"{ hello world }d\\n\"); /* }*/", 
        "}"
    }; 
    string res = {"(){()}"}; 

    string ret {""}; 

    for (auto elem : make_bracket_string(remove_comments(src))) {
        ret += elem; 
    }
    cout << "ret: " << ret << endl; 
    cout << "res: " << res << endl; 
    return EXPECT_EQ<string>(res, ret); 
}

#endif

int main() {
    
    vector<string> srcBracketArray {make_bracket_string(remove_comments(read_file("./example.c")))}; 
    
    string srcString {""}; 
    for (auto elem : srcBracketArray) srcString += elem; 

    #ifndef NDEBUG
    cout << "src string: " << srcString << endl; 
    #endif

    size_t errIndex = 0; 
    if (is_matching(srcString, errIndex)) cout << srcString << endl; 
    else {
        size_t errIndexFind = errIndex; 
        size_t lineNumber = 0; 
        #ifndef NDEBUG
        cout << "err index: " << errIndex << endl; 
        #endif
        for (vector<string>::const_iterator iter = srcBracketArray.cbegin(); iter != srcBracketArray.cend(); ++iter) {
            if (errIndexFind < iter->length()) lineNumber = distance(srcBracketArray.cbegin(), iter) + 1; 
            else errIndexFind -= iter->length(); 
        }
        printf("without maching '%c' at line %ld\n", srcString.at(errIndex), lineNumber); 
    }

    return 0; 
}
