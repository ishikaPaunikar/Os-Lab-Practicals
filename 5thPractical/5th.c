#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;  // Waiting time for the first process is 0
   
    // Calculate waiting time for remaining processes
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];  // Waiting time = previous burst time + previous waiting time
    }
}

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Turnaround time = Burst time + Waiting time
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void printTable(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Print the header for the table
    printf("\nProcess Table\n");
    printf("----------------------------------------------------------\n");
    printf("| Process | Burst Time | Waiting Time | Turnaround Time |\n");
    printf("----------------------------------------------------------\n");
   
    // Print the details for each process
    for (int i = 0; i < n; i++) {
        printf("|   P%d    |    %2d     |     %2d      |       %2d        |\n", processes[i], bt[i], wt[i], tat[i]);
    }
    printf("----------------------------------------------------------\n");
}

void printGanttChart(int processes[], int n, int bt[]) {
    printf("\nGantt Chart\n");
    printf("-------------------------------------------------------------\n");
    printf("P |");
   
    // Print the process execution order
    for (int i = 0; i < n; i++) {
        printf(" P%d |", processes[i]);
    }
    printf("\n");
   
    // Print the time slots
    printf("-------------------------------------------------------------\n");
    printf(" 0 ");
    int time = 0;
    for (int i = 0; i < n; i++) {
        time += bt[i];
        printf(" %2d ", time);
    }
    printf("\n");
    printf("-------------------------------------------------------------\n");
}

void findAvgTimes(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
   
    // Calculate waiting time and turnaround time
    findWaitingTime(processes, n, bt, wt);
    findTurnaroundTime(processes, n, bt, wt, tat);

    // Print the table
    printTable(processes, n, bt, wt, tat);

    // Print the Gantt Chart
    printGanttChart(processes, n, bt);

    // Calculate average waiting time and turnaround time
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("\nAverage waiting time: %.2f\n", total_wt / n);
    printf("Average turnaround time: %.2f\n", total_tat / n);
}

int main() {
    int processes[] = {1, 2, 3, 4}; // Process IDs
    int n = sizeof(processes) / sizeof(processes[0]);
   
    // Burst time of processes
    int bt[] = {6, 8, 7, 3}; // Example burst times
   
    // Call the function to calculate average times and print the table and Gantt chart
    findAvgTimes(processes, n, bt);
   
    return 0;
}

