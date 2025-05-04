#include <stdio.h>
#include "process.h"
#include "file_io.h"
#include "scheduler.h"

#define MAX_PROCESSES 10

int main() {
    Process processes[MAX_PROCESSES];

    // Step 1: Read raw processes from file
    int raw_processes = read_processes("input.txt", processes, MAX_PROCESSES);

    // Step 2: Filter out any process with burst_time = 0
    int num_processes = 0;
    for (int i = 0; i < raw_processes; i++) {
        if (processes[i].burst_time > 0) {
            processes[num_processes++] = processes[i];
        } else {
            printf("⚠️  Skipping P%d with burst_time = 0\n", processes[i].pid);
        }
    }

    // Step 3: Print all valid processes
    printf("Loaded %d valid processes:\n", num_processes);
    for (int i = 0; i < num_processes; i++) {
        printf("PID: %d | Arrival: %d | Burst: %d | Priority: %d\n",
               processes[i].pid,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].priority);
    }

    // Step 4: Run the Round Robin Scheduler
    int quantum = 2;  // You can change this value as needed
    round_robin(processes, num_processes, quantum);

    return 0;
}
