#include <iostream>
#include <vector>

using namespace std; 

typedef struct Node {
    int idx;
    int number; 
    struct Node *next; 
} Person; 

/**
 * @description: 初始化循环链表
 * @param {int} n 人数
 * @param {int} *arr 各密码
 * @return {Person*} 返回已经初始化的循环链表
 */
Person* Init(int n, int *arr) {
    // 创建首节点和循环节点
    Person *head = new Person{1, arr[0], nullptr}; 
    Person *cyclic = head; 

    // 创建并链接各节点
    for (int i = 1; i < n; ++i) {
        Person *body = new Person{i + 1, arr[i], nullptr}; 
        cyclic->next = body; 
        cyclic = cyclic->next; 
    }

    // 至此，cyclic指向尾节点
    // 使其指向首节点以循环此链表
    cyclic->next = head; 

    // 返回循环链表
    return head; 
}

/**
 * @description: 模拟出列操作
 * @param {Person*} head 循环链表
 * @param {int} m 初始上限值
 * @param {int} n 人数
 * @return {vector<int>} 出列序号(idx)序列
 */
vector<int> Remove(Person *head, int m, int n) {
    // 创建当前节点
    Person *curr = head; 

    // 创建当前节点的前驱节点
    Person *before_curr = head; 
    while (before_curr->next != curr) before_curr = before_curr->next; 

    // 结果数组
    vector<int> ret { }; 

    for (int i = 0; i < n; ++i) {
        // 找到报m的节点及其前驱
        for (int j = 0; j < m - 1; ++j) {
            curr = curr->next; 
            before_curr = before_curr->next; 
        }

        // 重置上限值
        m = curr->number; 

        // 保存结果
        ret.push_back(curr->idx); 

        // 删除节点
        // 释放内存
        Person *to_delete = curr; 
        before_curr->next = curr->next; 
        curr = curr->next; 
        delete to_delete; 
    }

    // 返回结果数组
    return ret; 
}

int main() {

    int m, n;    
    cin >> m >> n; 

    int *arr = new int[n + 1]; 
    for (int i = 0; i < n; ++i) cin >> arr[i]; 

    vector<int> res = Remove(Init(n, arr), m, n);  

    for (auto elem : res) cout << elem << " "; 
    cout << endl; 

    return 0; 
}