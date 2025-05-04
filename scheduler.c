#include <stdio.h>
#include "scheduler.h"

void round_robin(Process processes[], int n, int quantum) {
    int time = 0;
    int completed = 0;

    printf("\n--- Round Robin Scheduling ---\n");

    while (completed < n) {
        int done_in_this_cycle = 0;

        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= time) {
                done_in_this_cycle = 1;

                int time_slice = (processes[i].remaining_time > quantum) ? quantum : processes[i].remaining_time;
                printf("Time %d: P%d running for %d units\n", time, processes[i].pid, time_slice);

                time += time_slice;
                processes[i].remaining_time -= time_slice;

                if (processes[i].remaining_time == 0) {
                    processes[i].completion_time = time;
                    completed++;
                }
            }
        }

        if (!done_in_this_cycle)
            time++; // Idle time if no process is ready
    }

    // Print completion times
    printf("\n--- Completion Times ---\n");
    for (int i = 0; i < n; i++) {
        printf("P%d finished at time %d\n", processes[i].pid, processes[i].completion_time);
    }

    // Turnaround and waiting time calculation
    printf("\n--- Turnaround and Waiting Times ---\n");
    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++) {
        int turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        int waiting_time = turnaround_time - processes[i].burst_time;
        total_tat += turnaround_time;
        total_wt += waiting_time;

        printf("P%d | TAT: %d | WT: %d\n", processes[i].pid, turnaround_time, waiting_time);
    }

    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    printf("Average Waiting Time    = %.2f\n", total_wt / n);
}
