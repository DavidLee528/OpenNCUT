#ifndef _MAIN_HPP_
#define _MAIN_HPP_ 1

#include <iostream>
#include "fcfs.hpp"
#include "sjf.hpp"
#include "hrrn.hpp"
#include "rr.hpp"
#include <fstream>
#include "test_case_path.hpp"

void start_simulate(bool gantt_mode = false); 

#define     ASCII_COLOR_RED 			"\033[1;31m"
#define     ASCII_COLOR_WHITE			"\033[1;37m"
#define     ASCII_COLOR_GREEN           "\033[0;32m"
#define     ASCII_COLOR_END			    "\033[0m"
#define     DEBUG_INFO(fmt, args...)    ({do {printf(ASCII_COLOR_WHITE"[APP INFO]:%s[%d]: ", __FUNCTION__,__LINE__); printf(fmt, ##args); printf(ASCII_COLOR_END);}while(0);})


#endif /* _MAIN_HPP_ */