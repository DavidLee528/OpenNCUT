#ifndef _SIM_HPP_
#define _SIM_HPP_ 1

#include <iostream>
#include <vector>
#include <algorithm>

#include "process.hpp"

class Sim {
public: 
    virtual void simulate() = 0; 
    virtual void show() {
        show_table_title(); 
        for (const auto &elem : processes) {
            std::cout << elem << std::endl;
        }
        calculate_avg_time(); 
        std::cout << "Average Turnaround Time:          " << avg_turnaround_time << std::endl; 
        std::cout << "Average Weighted Turnaround Time: " << avg_weighted_turnaround_time << std::endl; 
        std::cout << "Average Waiting Time              " << avg_waiting_time << std::endl; 
    }

    virtual void gantt() {
        // each line:  (pid, start, end)
        for (const auto &elem : processes) {
            std::cout << "(" << elem.get_pid() << "," << elem.get_start_time() << "," << elem.get_completion_time() << "," << elem.get_arrival_time() << ")" << std::endl; 
        }
    }

protected: 
    size_t process_number;                  // how many process to be simulate
    std::vector<Process> processes;         // process array
    
    double avg_turnaround_time              = 0.0;      
    double avg_weighted_turnaround_time     = 0.0; 
    double avg_waiting_time                 = 0.0; 

private: 
    void show_table_title() const {
        std::cout << "pid\t" << "arrive\t" << "burst\t" << "start\t" << "end\t" << "turna\t" << "wturna\t" << "wait\t" << std::endl; 
    }
    void calculate_avg_time() {
        for (const auto &elem : processes) {
            avg_turnaround_time += (double)elem.get_turnaround_time(); 
            avg_weighted_turnaround_time += (double)elem.get_weighted_turnaround_time(); 
            avg_waiting_time += (double)elem.get_waiting_time(); 
        }
        avg_turnaround_time /= processes.size(); 
        avg_weighted_turnaround_time /= processes.size(); 
        avg_waiting_time /= processes.size(); 
    }
}; 

#endif /* _SIM_HPP_ */