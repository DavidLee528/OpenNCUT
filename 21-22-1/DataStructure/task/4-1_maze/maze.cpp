#include <iostream>
#include <queue>
#include <cstring>

using namespace std; 

// 迷宫行列数
int m, n; 

// 最大迷宫行列数
const size_t MAX_SIZE = 200; 

// 迷宫二维数组
bool maze[MAX_SIZE][MAX_SIZE]; 

// 全部路径个数
size_t cnt; 

// 访问记录
bool isVisit[MAX_SIZE][MAX_SIZE]; 

// 判断坐标(x, y)是否在迷宫内
inline bool
in_maze(int _x, int _y) {
    return _x >= 0 && _x < m && _y >= 0 && _y < n; 
}

// 深度优先搜索
void dfs(int x, int y) {
    // 到达终点，递归终止
    if (x == m - 1 && y == n - 1) {
        ++cnt; 
        return ;
    }

    // 方向向量
    const int dx[4] = { -1, 0, 1, 0 }; 
    const int dy[4] = { 0, 1, 0, -1 }; 

    // 四处寻路
    for (int i = 0; i < 4; ++i) {
        // 根据方向向量新坐标值
        int tx = x + dx[i]; 
        int ty = y + dy[i]; 
        // 判断：1) 是否在迷宫内; 2) 是否访问过; 3) 是否为墙
        if (in_maze(tx, ty) && !isVisit[tx][ty] && maze[tx][ty] == 0) {
            isVisit[tx][ty] = true;         // 留下足迹
            dfs(tx, ty);                    // 递归调用
            isVisit[tx][ty] = false;        // 恢复现场
        }
    }

    // 此路不通，递归终止
    return ;
}

// 广度优先搜索
int bfs() {
    int d[MAX_SIZE][MAX_SIZE]; 
    memset(d, -1, sizeof(d)); 
    d[0][0] = 0; 

    // 使用队列存储坐标点
    queue<pair<size_t, size_t>> q { }; 

    // 从(0, 0)开始
    q.push({0, 0}); 
    
    // 方向向量
    const int dx[4] = { -1, 0, 1, 0 }; 
    const int dy[4] = { 0, 1, 0, -1 }; 

    while (!q.empty()) {
        pair<size_t, size_t> pos = q.front(); 
        q.pop(); 
        for (size_t i = 0; i < 4; ++i) {
            int tx = pos.first + dx[i]; 
            int ty = pos.second + dy[i]; 
            if (in_maze(tx, ty) && maze[tx][ty] == 0 && d[tx][ty] == -1) {
                d[tx][ty] = d[pos.first][pos.second] + 1; 
                q.push({tx, ty}); 
            }
        }
    }

    // 返回最短路径
    return d[m - 1][n - 1]; 
}

int main() {
    
    // 输入行列数
    cin >> m >> n; 

    // 输入迷宫(1表示墙，0表示路)
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maze[i][j]; 
        }
    }

    // 深度优先搜索计算【全部路径个数】
    dfs(0, 0); 
    cout << cnt << endl; 

    // 广度优先搜索计算【最短路径长度】
    cout << bfs() << endl; 

    return 0; 
}
