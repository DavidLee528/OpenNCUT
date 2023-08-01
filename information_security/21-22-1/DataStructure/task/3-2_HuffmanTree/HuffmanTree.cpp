#define NDEBUG
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

using namespace std; 

typedef struct HuffmanTree {
    uint64_t freq; 
    size_t parent, lchild, rchild; 
    HuffmanTree(uint64_t _freq = 0UL, size_t _parent = 0UL, size_t _lc = 0UL, size_t _rc = 0UL)
    : freq(_freq), parent(_parent), lchild(_lc), rchild(_rc) { }
} HTNode; 

#ifndef NDEBUG          // 测试部分
void test_print_ht_list(HTNode *ht, size_t n); 
void test_func_select(); 
template<typename T> inline bool 
EXPECT_EQ(const T &lhs, const T &rhs); 
#endif


void select(HTNode *ht, size_t n, size_t &s1, size_t &s2) {
    // 找到最小的
    uint64_t cmp = numeric_limits<uint64_t>::max(); 
    size_t idx = 0; 
    for (size_t i = 1; i <= n; ++i) {
        if (ht[i].parent != 0) continue;  
        if (ht[i].freq < cmp) cmp = ht[i].freq, idx = i; 
    }
    s1 = idx; 

    // 找到次小的
    cmp = numeric_limits<uint64_t>::max(); 
    for (size_t i = 1; i <= n; ++i) {
        if (i == s1) continue; 
        if (ht[i].parent != 0) continue; 
        if (ht[i].freq < cmp) cmp = ht[i].freq, idx = i; 
    }
    s2 = idx; 

    return ;
}

void huffman_encode(vector<string> &code, const vector<uint64_t> &freq) {
    // 判断个数合法性
    size_t n = freq.size(); 
    if (n <= 1) return ;

    // 创建初始化的Huffman树  TESTOK
    size_t node_cnt = 2 * n - 1; 
    HTNode *ht = new HTNode[node_cnt + 1]; 
    HTNode *p = ht + 1; 
    for (size_t i = 0; i < n; ++i, ++p) {
        p->freq = freq.at(i); 
    }

    // 构建Huffman树非叶子节点
    for (size_t i = n + 1; i <= node_cnt; ++i) {
        size_t s1 = 0, s2 = 0; 
        select(ht, i - 1, s1, s2); 
        if (s1 > s2) swap(s1, s2);
        ht[s1].parent = i; 
        ht[s2].parent = i; 
        ht[i].lchild = s1; 
        ht[i].rchild = s2; 
        ht[i].freq = ht[s1].freq + ht[s2].freq; 
    }

    #ifndef NDEBUG
    test_print_ht_list(ht, node_cnt); 
    // exit(0); 
    #endif

    // 构建Huffman编码
    string hcode = ""; 
    for (size_t i = 1; i <= n; ++i) {
        size_t parent_idx = ht[i].parent; 
        for (size_t j = i; parent_idx != 0; j = parent_idx, parent_idx = ht[parent_idx].parent) {
            if (ht[parent_idx].lchild == j) hcode += "0"; 
            else hcode += "1"; 
        }
        reverse(hcode.begin(), hcode.end()); 
        code.push_back(hcode); 
        hcode.clear(); 
    } 

    // 释放Huffman树(表)
    delete [] ht; 
    return ;
}

void solve() {
    size_t n = 0; 
    cin >> n; 

    uint64_t each = 0; 
    vector<uint64_t> freq { }; 
    for (size_t i = 0; i < n; ++i) {
        cin >> each; 
        freq.push_back(each); 
    }

    vector<string> res { }; 

    huffman_encode(res, freq); 

    for (const auto &elem : res) cout << elem << endl; 

    return ;
}

int main() {

    solve(); 

    return 0; 
}

#ifndef NDEBUG

template<typename T>
inline bool
EXPECT_EQ(const T &lhs, const T &rhs) {
    return lhs == rhs; 
}


void test_print_ht_list(HTNode *ht, size_t n) {
    cout << endl; 
    cout << "(idx)" << "\t" << "freq" << "\t" << "parent" << "\t" << "lchild" << "\t" << "rchild" << endl; 
    for (size_t i = 0; i <= n; ++i) {
        cout << i << "\t" << ht[i].freq << "\t" << ht[i].parent << "\t" << ht[i].lchild << "\t" << ht[i].rchild << endl; 
    }
}

void test_func_select() {
    vector<uint64_t> nums { 4, 1, 8, 9, 7, 3, 6, 11, 99, 12 }; 
    HTNode *ht = new HTNode[10]; 
    for (size_t i = 0; i < 10; ++i) {
        ht[i] = HTNode(nums.at(i)); 
    }
    
    size_t s1 = 0, s2 = 0; 
    select(ht, static_cast<size_t>(10), s1, s2); 
    
    EXPECT_EQ<size_t>(s1, static_cast<size_t>(1)) ? printf("TEST OK\n") : printf("FAILED\n"); 
    EXPECT_EQ<size_t>(s2, static_cast<size_t>(3)) ? printf("TEST OK\n") : printf("FAILED\n"); 

    return ;
}

#endif