#include <iostream>
#include <stack>
#include <queue>
#include <map>

using namespace std; 

const bool IN = 0; 
const bool OUT = 1; 
const int OK = 2; 
const int VEHICLE_DOES_NOT_EXIST = -1; 
const int VEHICLE_EXIT_FROM_ROAD = -1; 

typedef struct Node {
    int num; 
    int time_in; 
} Car; 

size_t size = 0;            // 停车场容量
double price = 0.0;         // 单价
stack<Car> parking { };     // 模拟停车场
queue<Car> road { };        // 模拟便道
map<int, double> cost { };  // 计费表单：｛车牌号, 价格｝

void Enter(int num, int time_in) {
    // 创建车辆
    Car *thisCar = new Car{num, time_in}; 

    // 进入停车场或便道
    (parking.size() < size) ? parking.push(*thisCar) : road.push(*thisCar); 
}

Car Exit(int targetNum, int leaveTime) {
    Car currCar, retCar;  

    // 检测车辆是否存在于便道
    if (!road.empty()) {
        queue<Car> tmpRoad { }; 
        bool onTheRoad = false; 
        while (!road.empty()) {
            currCar = road.front(); 
            road.pop(); 
            if (currCar.num != targetNum) {
                tmpRoad.push(currCar); 
                continue; 
            } 
            retCar = currCar; 
            onTheRoad = true; 
            break; 
        }
        while (!tmpRoad.empty()) {
            currCar = tmpRoad.front(); 
            tmpRoad.pop(); 
            road.push(currCar); 
        }
        // 此车辆不计费
        if (onTheRoad) return Car{-2, -2}; 
    }
    
    // 检测车辆是否存在于停车场
    if (!parking.empty()) {
        stack<Car> tmpParkingLot { }; 
        bool inTheParkingLot = false; 
        while (!parking.empty()) {
            currCar = parking.top(); 
            parking.pop(); 
            if (currCar.num != targetNum) {
                tmpParkingLot.push(currCar); 
                continue; 
            }
            retCar = currCar;  
            inTheParkingLot = true; 
            break; 
        }
        while (!tmpParkingLot.empty()) {
            currCar = tmpParkingLot.top(); 
            tmpParkingLot.pop(); 
            parking.push(currCar); 
        }
        // 便道车辆驶入停车场
        if (!road.empty()) {
            parking.push(road.front()); 
            road.pop(); 
        }
        // 返回出场车辆，记录费用
        if (inTheParkingLot) return retCar; 
    }
    
    // 找不到车辆
    return Car{-1, -1}; 
}

int Operate(bool opt, int num, int time) {
    // 车辆驶入后结束操作
    if (opt == IN) { 
        Enter(num, time); 
        return OK; 
    }
    
    // 离开的车辆
    Car exitCar = Exit(num, time); 

    // 不存在车辆，返回错误，结束操作
    if (exitCar.num == -1 && exitCar.time_in == -1) return VEHICLE_DOES_NOT_EXIST; 

    // 车辆从便道驶离，不计费
    if (exitCar.num == -2 && exitCar.time_in == -2) return VEHICLE_EXIT_FROM_ROAD; 

    // 计算价格
    double expense = (double)(time - exitCar.time_in) * price; 

    // 若重复进出场，则累加价格
    if (cost.find(num) != cost.end()) expense += cost.at(num); 

    // 存入计费表单
    cost.insert({num, expense}); 

    // 结束操作
    return OK;  
}

void PrintResult() {
    // 输出计费结果
    for (auto elem : cost) {
        printf("%d %.2lf\n", elem.first, elem.second); 
    }

    // 输出停车场剩余车辆
    if (!parking.empty()) {
        // 要求从北向南输出
        stack<Car> reverseParkingLot { }; 

        // 使栈顶朝北
        while (!parking.empty()) {
            reverseParkingLot.push(parking.top()); 
            parking.pop(); 
        }

        while (!reverseParkingLot.empty()) {
            printf("%d ", reverseParkingLot.top().num); 
            reverseParkingLot.pop(); 
        }
        cout << endl;         
    }
    
    // 输出便道剩余车辆
    while (!road.empty()) {
        printf("%d ", road.front().num); 
        road.pop(); 
    }
    cout << endl; 
    
}


int main() {

    cin >> size >> price; 

    bool opt; 
    int num, time; 
    while (1) {
        cin >> opt >> num >> time; 
        if (opt == 0 && num == 0 && time == 0) break; 
        if (Operate(opt, num, time) == VEHICLE_DOES_NOT_EXIST) 
            cerr << "VEHICLE_DOES_NOT_EXIST" << endl; 
    }

    PrintResult(); 

    return 0; 
}