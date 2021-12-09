#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

typedef struct Node {
    char value; 
    struct Node *lchild; 
    struct Node *rchild; 
    Node(char _value = 0, struct Node *_lc = nullptr, struct Node *_rc = nullptr)
    : value(_value), lchild(_lc), rchild(_rc) { }
} BTNode; 

BTNode* build_tree(const string &dlr, size_t preStart, size_t preEnd, const string &ldr, size_t inStart, size_t inEnd) {
    // 非法边界，返回空指针
    if (preStart > preEnd || inStart > inEnd) return nullptr; 

    // 生成一个节点
    BTNode *bt = new BTNode(dlr.at(preStart)); 

    // 在中序遍历序列中找到根节点
    // 递归调用
    for (size_t i = inStart; i <= inEnd; ++i) {
        if (ldr.at(i) == dlr[preStart]) {
            bt->lchild = build_tree(dlr, preStart + 1, preStart + i - inStart, ldr, inStart, i - 1); 
            bt->rchild = build_tree(dlr, preStart + i - inStart + 1, preEnd, ldr, i + 1, inEnd); 
        }
    }

    // 返回种好的树
    return bt; 
}

void get_tree(BTNode *bt, const string &dlr, const string &ldr) {
    BTNode *tmp = build_tree(dlr, 0, dlr.length() - 1, ldr, 0, ldr.length() - 1); 
    bt->value = tmp->value; 
    bt->lchild = tmp->lchild; 
    bt->rchild = tmp->rchild; 
}

void lrd(BTNode *bt, string &res) {
    if (!bt) return ;
    lrd(bt->lchild, res); 
    lrd(bt->rchild, res); 
    res += bt->value; 
}

string trans_to_lrd(const string &dlr, const string &ldr) {
    // 创建根节点
    BTNode *bt = new BTNode(); 

    // 种树
    get_tree(bt, dlr, ldr); 

    // 后跟遍历序列结果
    string ret {""}; 

    // 后根遍历
    lrd(bt, ret);

    return ret; 
}

void solve() {
    // 先序遍历序列和中序遍历序列
    string dlr, ldr; 

    // 输入两个序列
    cin >> dlr >> ldr; 

    // 转换为后序遍历序列
    string lrd = trans_to_lrd(dlr, ldr); 

    // 输出结果
    cout << lrd << endl; 
}

int main() {
    solve(); 
    return 0; 
}