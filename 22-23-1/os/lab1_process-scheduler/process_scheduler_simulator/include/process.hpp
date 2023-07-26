#ifndef _PROCESS_HPP_
#define _PROCESS_HPP_

#include <iostream>
#include <ostream>
#include <istream>
#include <vector>
#include <string>

class Process {

friend std::ostream &operator<<(std::ostream &os, const Process &p); 
friend std::istream &operator>>(std::istream &is, Process &p); 

public: 
    // initial instance with process id, process arrival time and process estimate burst time
    Process(unsigned long _pid = 0, unsigned long _arrival_time = 0, unsigned long _burst_time = 0): 
        pid(_pid), arrival_time(_arrival_time), burst_time(_burst_time) { }

    ~Process() = default;  

    bool operator==(const Process &rhs) {
        return this->pid == rhs.pid; 
    }

    bool operator!=(const Process &rhs) {
        return this->pid != rhs.pid; 
    }

    bool is_finished() const {
        return finished; 
    }

    unsigned long get_pid() const {
        return pid; 
    }

    unsigned long get_arrival_time() const {
        return arrival_time; 
    }

    unsigned long get_burst_time() const {
        return burst_time; 
    }

    unsigned long get_remain_time() const {
        return remain_time; 
    }

    unsigned long get_start_time() const {
        return start_time; 
    }

    unsigned long get_completion_time() const {
        return completion_time; 
    }

    unsigned long get_turnaround_time() const {
        return turnaround_time; 
    }

    double get_weighted_turnaround_time() const {
        return weighted_turnaround_time; 
    }

    unsigned long get_waiting_time() const {
        return waiting_time; 
    }

    unsigned long get_response_time() const {
        return response_time; 
    }

    bool is_start() const {
        return started; 
    }

    void update_remain_time(const unsigned long &rhs) {
        if (rhs == 0) finished = true;
        this->remain_time = rhs; 
    }

    void set_time_data_when_finish(
        unsigned long _start_time, unsigned long _completion_time, 
        unsigned long _turnaround_time, double _weighted_turnaround_time, unsigned long _waiting_time) {

        start_time                  =       _start_time; 
        completion_time             =       _completion_time; 
        turnaround_time             =       _turnaround_time; 
        weighted_turnaround_time    =       _weighted_turnaround_time; 
        waiting_time                =       _waiting_time; 

        finished = true; 
    }

    void set_start_time(const unsigned long &_start_time) {
        this->start_time = _start_time; 
    }

    void set_turnaround_time(const unsigned long &_turnaround_time) {
        this->turnaround_time = _turnaround_time; 
    }

    void set_completion_time(const unsigned long &_completion_time) {
        this->completion_time = _completion_time; 
    }

    void set_waiting_time(const unsigned long &_waiting_time) {
        this->waiting_time = _waiting_time; 
    }

    void set_reponse_time(const unsigned long &_response_time) {
        this->response_time = _response_time; 
    }

    void update_start_status() {
        this->started = true; 
    }

    bool is_shortest(size_t curr_time, const std::vector<Process> &pa) const {
        if (this->arrival_time < curr_time) return false; 

        for (std::vector<Process>::const_iterator iter = pa.cbegin(); iter != pa.cend(); ++iter) {
            if ((*iter).arrival_time > curr_time) continue; 
            if ((*iter).get_burst_time() < this->burst_time) return false; 
        }

        return true; 
    }

private: 
    bool finished                       = false; 
    bool started                        = false; 

    unsigned long pid                   = 0;    // process id
    unsigned long arrival_time          = 0;    // when arrived
    unsigned long burst_time            = 0;    // how long to run
    unsigned long remain_time           = 0;    // for round-robin only

    unsigned long start_time            = 0;    // when actually start
    unsigned long completion_time       = 0;    // when actually end
    unsigned long turnaround_time       = 0;    // end time - arrive time
    double weighted_turnaround_time     = 0;    // (1 / burst_time) * (end_time - arrive_time)
    unsigned long waiting_time          = 0;    // end_time - arrive_time - burst_time
    unsigned long response_time         = 0;    // start_time - arrival_time
}; 

#endif /* _PROCESS_HPP_ */