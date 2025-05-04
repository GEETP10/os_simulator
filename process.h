#ifndef PROCESS_H  // ifndef,define,endif will make sure it the file isnt included twice 
#define PROCESS_H

typedef struct{
    int pid;
    int arrival_time ;
    int burst_time;
    int priority;
    int remaining_time;
    int completion_time;
} Process;
#endif