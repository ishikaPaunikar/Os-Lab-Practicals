#include <stdio.h>

struct Process {
    int id;             // Process ID
    int burstTime;      // Burst Time
    int priority;       // Priority
    int waitingTime;    // Waiting Time
    int turnAroundTime; // Turnaround Time
};

// Function to calculate waiting times for processes
void calculateWaitingTime(struct Process processes[], int n) {
    processes[0].waitingTime = 0;  // The first process has no waiting time
    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }
}

// Function to calculate turnaround times for processes
void calculateTurnAroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnAroundTime = processes[i].burstTime + processes[i].waitingTime;
    }
}

// Function to sort processes by priority (highest priority first)
void sortByPriority(struct Process processes[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].priority < processes[j].priority) {
                // Swap processes[i] and processes[j]
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// Function to print the Gantt chart
void printGanttChart(struct Process processes[], int n) {
    int currentTime = 0;
    printf("\nGantt Chart:\n");
   
    // Print process execution timeline
    for (int i = 0; i < n; i++) {
        printf("| P%d ", processes[i].id);  // Process ID in the chart
        currentTime += processes[i].burstTime;
    }
    printf("|\n");

    // Print the time scale below the Gantt chart
    currentTime = 0;
    for (int i = 0; i < n; i++) {
        printf("  %d   ", currentTime);
        currentTime += processes[i].burstTime;
    }
    printf("%d\n", currentTime);  // Final time
}

// Function to print process details and their respective times
void printProcesses(struct Process processes[], int n) {
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burstTime, processes[i].priority, processes[i].waitingTime, processes[i].turnAroundTime);
    }
}

int main() {
    // Predefined values for processes (No user input)
    struct Process processes[] = {
        {1, 6, 1},   // Process 1: Burst time = 6, Priority = 1
        {2, 8, 4},   // Process 2: Burst time = 8, Priority = 4
        {3, 7, 2},   // Process 3: Burst time = 7, Priority = 2
        {4, 3, 5}    // Process 4: Burst time = 3, Priority = 5
    };
    int n = sizeof(processes) / sizeof(processes[0]);  // Number of processes

    // Sorting processes based on priority (highest priority first)
    sortByPriority(processes, n);

    // Calculate waiting time and turnaround time
    calculateWaitingTime(processes, n);
    calculateTurnAroundTime(processes, n);

    // Print Gantt Chart
    printGanttChart(processes, n);

    // Print process details
    printProcesses(processes, n);

    return 0;
}