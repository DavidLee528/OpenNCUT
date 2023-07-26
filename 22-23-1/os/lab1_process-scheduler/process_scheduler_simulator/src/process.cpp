#include "process.hpp"

std::ostream &operator<<(std::ostream &os, const Process &p) {
    os << p.pid << "\t"; 
    os << p.arrival_time << "\t"; 
    os << p.burst_time << "\t"; 
    os << p.start_time << "\t"; 
    os << p.completion_time << "\t"; 
    os << p.turnaround_time << "\t"; 
    os << p.weighted_turnaround_time << "\t"; 
    os << p.waiting_time << "\t"; 
    return os; 
}

std::istream &operator>>(std::istream &is, Process &p) {
    is >> p.pid >> p.arrival_time >> p.burst_time; 
    p.remain_time = p.burst_time;   // remain_time is equal to burst_time when init
    return is; 
}

