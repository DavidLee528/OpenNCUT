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
    // 创建首节点
    // Person *head = (Person*)malloc(sizeof(Person)); 
    Person *head = new Person; 

    // 设置首节点值
    head->idx = 1; 
    head->number = arr[0]; 
    head->next = nullptr; 

    // 创建循环节点
    Person *cyclic = head; 

    for (int i = 1; i < n; ++i) {
        // 创建各节点
        Person *body = new Person; 
        // 设置各节点值
        body->idx = i + 1; 
        body->number = arr[i]; 
        body->next = nullptr; 
        // 链接各节点
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
    // 创建当前节点并使其指向首节点
    Person *curr = head; 

    // 当前节点的前驱节点
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
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; 
    }

    vector<int> res = Remove(Init(n, arr), m, n);  

    for (vector<int>::const_iterator iter = res.cbegin(); iter != res.cend(); ++iter) {
        cout << *iter << " "; 
    }
    cout << endl; 

    return 0; 
}