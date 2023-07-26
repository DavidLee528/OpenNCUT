#!/bin/bash

./process_scheduler_simulator/build/src/process_scheduler_simulator 1 | python ./gantt_chart_drawer/draw_gantt_chart.py
