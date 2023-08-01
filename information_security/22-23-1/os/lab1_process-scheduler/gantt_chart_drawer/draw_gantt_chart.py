from asyncio import Task
import this
import plotly.figure_factory as ff
import plotly as py

gantt_fcfs = []
gantt_sjf = []
gantt_hrrn = []
gantt_rr = []

flag = 0
while True: 
    line = str(input())

    if line == "<end_simulate>": 
        break
    elif "First Come First Serve" in line: 
        flag = 1
        continue
    elif "Shortest Job First" in line:
        flag = 2
        continue 
    elif "Highest Response-Ratio Next" in line:
        flag = 3
        continue 
    elif "Round-Robin" in line:
        flag = 4
        continue   
    elif line[0] == '(':
        elem = line.strip('(').strip(')').split(',')
        output = "pid = " + elem[0] + "\tstart = " + elem[1] + "\tend = " + elem[2] + "\tflag = " + str(flag)
        if flag == 1:
            gantt_fcfs.append((elem[0], elem[1], elem[2], elem[3]))
        elif flag == 2:
            gantt_sjf.append((elem[0], elem[1], elem[2], elem[3]))
        elif flag == 3:
            gantt_hrrn.append((elem[0], elem[1], elem[2], elem[3]))
        else:
            gantt_rr.append((elem[0], elem[1], elem[2], elem[3]))
    else:
        continue

colors = {'Waiting': 'rgb(220, 0, 0)', 'Running': 'rgb(0, 255, 100)'}


gantt_df_fcfs = []
for elem in gantt_fcfs:
    gantt_df_fcfs.append(dict(Task = str(elem[0]), Start = int(elem[1]), Finish = int(elem[2]), name = 'Running'))
    if elem[1] == elem[3]:
        continue
    gantt_df_fcfs.append(dict(Task = str(elem[0]), Start = int(elem[3]), Finish = int(elem[1]), name = 'Waiting'))
pyplt = py.offline.plot
fig_fcfs = ff.create_gantt(gantt_df_fcfs, title="Gantt Chart of FCFS", colors=colors, index_col='name', group_tasks=True, show_colorbar=True)
fig_fcfs.layout.xaxis.type = 'linear'
pyplt(fig_fcfs, filename='./gantt_chart_drawer/fcfs.html')

gantt_df_sjf = []
for elem in gantt_sjf:
    gantt_df_sjf.append(dict(Task = str(elem[0]), Start = int(elem[1]), Finish = int(elem[2]), name = 'Running'))
    if elem[1] == elem[3]:
        continue
    gantt_df_sjf.append(dict(Task = str(elem[0]), Start = int(elem[3]), Finish = int(elem[1]), name = 'Waiting'))
pyplt = py.offline.plot
fig_sjf = ff.create_gantt(gantt_df_sjf, title="Gantt Chart of SJF", colors=colors, index_col='name', group_tasks=True, show_colorbar=True)
fig_sjf.layout.xaxis.type = 'linear'
pyplt(fig_sjf, filename='./gantt_chart_drawer/sjf.html')

gantt_df_hrrn = []
for elem in gantt_hrrn:
    gantt_df_hrrn.append(dict(Task = str(elem[0]), Start = int(elem[1]), Finish = int(elem[2]), name = 'Running'))
    if elem[1] == elem[3]:
        continue
    gantt_df_hrrn.append(dict(Task = str(elem[0]), Start = int(elem[3]), Finish = int(elem[1]), name = 'Waiting'))
pyplt = py.offline.plot
fig_hrrn = ff.create_gantt(gantt_df_hrrn, title="Gantt Chart of HRRN", colors=colors, index_col='name', group_tasks=True, show_colorbar=True)
fig_hrrn.layout.xaxis.type = 'linear'
pyplt(fig_hrrn, filename='./gantt_chart_drawer/hrrn.html')

gantt_df_rr = []
for elem in gantt_rr:
    gantt_df_rr.append(dict(Task = str(elem[0]), Start = int(elem[1]), Finish = int(elem[2]), name = 'Running'))
for i in range(1, len(gantt_rr)):
    if (gantt_rr[i][0] != gantt_rr[i - 1][0]):
        continue
    gantt_df_rr.append(dict(Task = gantt_rr[i][0], Start = int(gantt_rr[i - 1][2]), Finish = int(gantt_rr[i][1]), name = 'Waiting'))
    
pyplt = py.offline.plot
fig_rr = ff.create_gantt(gantt_df_rr, title="Gantt Chart of RR", colors=colors, index_col='name', group_tasks=True, show_colorbar=True)
fig_rr.layout.xaxis.type = 'linear'
pyplt(fig_rr, filename='./gantt_chart_drawer/rr.html')