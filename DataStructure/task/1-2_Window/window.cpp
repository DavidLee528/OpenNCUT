#define NDEBUG
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

typedef struct Node {
    // 序号
    size_t idx; 
    // 左下顶点
    uint32_t x1; 
    uint32_t y1; 
    // 右上顶点
    uint32_t x2; 
    uint32_t y2; 
    // 后继节点
    struct Node *next; 
} Window; 

void TEST(Window *); 

/**
 * @description: 初始化
 * @param {vector<Window>&} allWindows 底层窗口靠前的数组
 * @return {Window*} 返回一个顶层窗口靠前的单链表
 */
Window* Init(const vector<Window> &allWindows) {
    // 使顶层窗口在数组前面
    vector<Window> reversedAllWindows {allWindows.rbegin(), allWindows.rend()}; 

    // 创建首节点
    Window *head = new Window {
        reversedAllWindows.at(0).idx, 
        reversedAllWindows.at(0).x1, 
        reversedAllWindows.at(0).y1, 
        reversedAllWindows.at(0).x2, 
        reversedAllWindows.at(0).y2, 
        nullptr
    }; 

    // 创建链接节点
    Window *link = head; 

    for (vector<Window>::const_iterator iter = reversedAllWindows.cbegin() + 1; 
                                        iter != reversedAllWindows.cend() + 1; ++iter) {
        // 创建每个节点
        Window *body = new Window {iter->idx, iter->x1, iter->y1, iter->x2, iter->y2, nullptr}; 

        // 链接前一个节点与此节点
        link->next = body; 
        
        // 链接节点后移
        link = link->next; 
    }

    // 返回此单链表
    return head; 
}

inline bool
CheckInside(Window *window, uint32_t x, uint32_t y) {
    return (window->x1 <= x && x <= window->x2)
        && (window->y1 <= y && y <= window->y2); 
}

Window* MoveToFront(Window *windowsArray, size_t sz, Window *targetWindow) {
    // 已在最前，无需操作
    if (windowsArray->idx == targetWindow->idx) return windowsArray; 

    vector<Window> newWindowVector { }; 
    newWindowVector.push_back(*targetWindow); 

    Window *curr = windowsArray; 
    while (curr->next != nullptr) {
        if (curr->idx != targetWindow->idx) newWindowVector.push_back(*curr); 
        curr = curr->next; 
    }

    reverse(newWindowVector.begin(), newWindowVector.end()); 

    Window *newWindowsArray = new Window(*Init(newWindowVector)); 

    return newWindowsArray; 
}

/**
 * @description: 模拟点击过程
 * @param {Window*} windowsArray 窗口序列
 * @param {int} x 点击横坐标
 * @param {int} y 点击纵坐标
 * @return {int} 返回窗口序号，若没有则返回-1
 */
int Click(Window *windowsArray, size_t sz, uint32_t x, uint32_t y) {
    // 创建当前节点
    Window *curr = windowsArray; 
    
    for (size_t i = 0; i < sz; ++i) {
        // 坐标范围判断
        if (!CheckInside(curr, x, y)) {
            // if (i == sz - 1) break; 
            curr = curr->next; 
            continue; 
        }

        // 返回值为点击到窗口的序号
        size_t ret = curr->idx; 

        // 移动窗口
        Window *newWindowsArray = MoveToFront(windowsArray, sz, curr);  

        // 更新窗口序列
        windowsArray->next = newWindowsArray->next; 
        windowsArray->idx = newWindowsArray->idx; 
        windowsArray->x1 = newWindowsArray->x1; 
        windowsArray->x2 = newWindowsArray->x2; 
        windowsArray->y1 = newWindowsArray->y1; 
        windowsArray->y2 = newWindowsArray->y2; 
        return ret; 
    }

    return -1; 
}

#ifndef NDEBUG
void TEST(Window *arr) {
    Window *curr = arr; 
    cout << "{*} WINDOWS LIST: "; 
    while (curr->next != nullptr) {
        cout << curr->idx << " "; 
        curr = curr->next; 
    }
    cout << endl;   
}
#endif


int main() {

    size_t n, m; 
    cin >> n >> m; 

    uint32_t x1, y1, x2, y2; 
    vector<Window> allWindows { }; 
    for (size_t i = 0; i < n; ++i) {
        cin >> x1 >> y1 >> x2 >> y2; 
        Window *curr = new Window{i + 1, x1, y1, x2, y2, nullptr}; 
        allWindows.push_back(*curr); 
    }

    Window *windowsList = Init(allWindows); 

    #ifndef NDEBUG
    TEST(windowsList); 
    #endif

    uint32_t x, y; 
    for (size_t i = 0; i < m; ++i) {
        cin >> x >> y; 
        int res = Click(windowsList, n, x, y); 
        #ifndef NDEBUG
        TEST(windowsList); 
        #endif
        if (res == -1) {
            cout << "IGNORED" << endl; 
            continue; 
        }
        cout << res << endl; 
    }


    return 0; 
}