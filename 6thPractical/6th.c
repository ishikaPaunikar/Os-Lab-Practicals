cd Documents
ls
cat file.c
gcc file.c -o test
./test

Code:
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;    
    int bt;    
    int at;    
    int ct;    
    int tat;    
    int wt;    
} Process;


int compare(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;

    if (p1->at == p2->at)
        return p1->bt - p2->bt;
    return p1->at - p2->at;
}


void findWaitingAndTurnaroundTimes(Process processes[], int n) {
    processes[0].ct = processes[0].at + processes[0].bt;

   
    for (int i = 1; i < n; i++) {
        processes[i].ct = (processes[i - 1].ct > processes[i].at) ? (processes[i - 1].ct + processes[i].bt) : (processes[i].at + processes[i].bt);
    }

   
    for (int i = 0; i < n; i++) {
        processes[i].tat = processes[i].ct - processes[i].at;  // TAT = CT - AT
        processes[i].wt = processes[i].tat - processes[i].bt;  // WT = TAT - BT
    }
}


void printTable(Process processes[], int n) {
    printf("\nProcess Table\n");
    printf("------------------------------------------------------------------------------------------\n");
  #include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;    
    int bt;    
    int at;    
    int ct;    
    int tat;    
    int wt;    
} Process;


int compare(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;

    if (p1->at == p2->at)
        return p1->bt - p2->bt;
    return p1->at - p2->at;
}


void findWaitingAndTurnaroundTimes(Process processes[], int n) {
    processes[0].ct = processes[0].at + processes[0].bt;

   
    for (int i = 1; i < n; i++) {
        processes[i].ct = (processes[i - 1].ct > processes[i].at) ? (processes[i - 1].ct + processes[i].bt) : (processes[i].at + processes[i].bt);
    }

   
    for (int i = 0; i < n; i++) {
        processes[i].tat = processes[i].ct - processes[i].at;  // TAT = CT - AT
        processes[i].wt = processes[i].tat - processes[i].bt;  // WT = TAT - BT
    }
}
  printf("| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |\n");
    printf("------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("|   P%-2d   |     %-2d      |     %-2d     |       %-3d       |       %-3d        |      %-3d      |\n",
                processes[i].id, processes[i].at, processes[i].bt, processes[i].ct, processes[i].tat, processes[i].wt);
    }
   
    printf("------------------------------------------------------------------------------------------\n");
}


void printGanttChart(Process processes[], int n) {
    printf("\nGantt Chart:\n ");

   
    for (int i = 0; i < n; i++) {
        printf("--------");
    }
    printf("\n|");

   
    for (int i = 0; i < n; i++) {
        printf("  P%-2d  |", processes[i].id);
    }
    printf("\n ");

   
    for (int i = 0; i < n; i++) {
        printf("--------");
    }
    printf("\n");

   
    printf("0");
    for (int i = 0; i < n; i++) {
        printf("       %-3d", processes[i].ct);
    }
    printf("\n");
}

int main() {
    int n = 4;

   
    Process processes[] = {
        {1, 8, 0},  // Process 1: Burst Time = 8, Arrival Time = 0
        {2, 4, 1},  // Process 2: Burst Time = 4, Arrival Time = 1
        {3, 9, 2},  // Process 3: Burst Time = 9, Arrival Time = 2
        {4, 5, 3}   // Process 4: Burst Time = 5, Arrival Time = 3
    };

   
    qsort(processes, n, sizeof(Process), compare);

   
    findWaitingAndTurnaroundTimes(processes, n);

   
    printTable(processes, n);

   
    printGanttChart(processes, n);

    return 0;
}