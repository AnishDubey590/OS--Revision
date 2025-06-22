#include <stdio.h>

int main() {
    int arrival_time[20], burst_time[20], completion_time[20];
    int turnaround_time[20], waiting_time[20], is_completed[20] = {0};
    int num_processes, current_time = 0, completed = 0;
    int i, shortest_bt, selected_process;
    float total_waiting_time = 0, total_turnaround_time = 0;

    // Input section
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    for (i = 0; i < num_processes; i++) {
        printf("Arrival Time of P%d: ", i);
        scanf("%d", &arrival_time[i]);
        printf("Burst Time of P%d: ", i);
        scanf("%d", &burst_time[i]);
    }

    // Main logic: Non-preemptive SJF scheduling
    while (completed < num_processes) {
        shortest_bt = 9999;
        selected_process = -1;

        // Find process with shortest burst time that has arrived and is not completed
        for (i = 0; i < num_processes; i++) {
            if (!is_completed[i] && arrival_time[i] <= current_time && burst_time[i] < shortest_bt) {
                shortest_bt = burst_time[i];
                selected_process = i;
            }
        }

        if (selected_process != -1) {
            // Execute the selected process
            waiting_time[selected_process] = current_time - arrival_time[selected_process];
            current_time += burst_time[selected_process];
            completion_time[selected_process] = current_time;
            turnaround_time[selected_process] = completion_time[selected_process] - arrival_time[selected_process];

            total_waiting_time += waiting_time[selected_process];
            total_turnaround_time += turnaround_time[selected_process];

            is_completed[selected_process] = 1;
            completed++;
        } else {
            // No process is ready to execute; CPU is idle
            current_time++;
        }
    }

    // Output results
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < num_processes; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", 
            i, 
            arrival_time[i], 
            burst_time[i], 
            completion_time[i], 
            turnaround_time[i], 
            waiting_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting_time / num_processes);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / num_processes);

    return 0;
}
