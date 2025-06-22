#include <stdio.h>

int main() {
    int i, n, time_quantum;
    int burst_time[10], remaining_time[10], waiting_time[10] = {0}, turnaround_time[10] = {0};
    int completed = 0;
    float total_waiting_time = 0, total_turnaround_time = 0;
    float current_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i]; // Copy original burst time
    }

    printf("Enter Time Slice (Quantum): ");
    scanf("%d", &time_quantum);

    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                if (remaining_time[i] <= time_quantum) {
                    current_time += remaining_time[i];
                    turnaround_time[i] = current_time; // process completed
                    remaining_time[i] = 0;
                    completed++;
                } else {
                    remaining_time[i] -= time_quantum;
                    current_time += time_quantum;
                }
            }
        }
    }

    // Calculate waiting time = TAT - BT
    for (i = 0; i < n; i++) {
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Output
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);

    return 0;
}
