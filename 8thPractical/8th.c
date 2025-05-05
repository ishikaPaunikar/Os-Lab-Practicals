#include <stdio.h>

#include <stdbool.h>

#define MAX 10


bool isSafe(int processes[], int avail[], int max[][MAX], int allot[][MAX], int n, int m) {
    int need[n][m];        
    bool finish[n];        
    int safeSeq[n];        
    int work[m];            

   
    for (int i = 0; i < n; i++) {
        finish[i] = false;  
    }
    for (int j = 0; j < m; j++) {
        work[j] = avail[j];
    }

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }

   
    int count = 0;
    while (count < n) {
        bool found = false;
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {  
                int j;
               
                for (j = 0; j < m; j++) {
                    if (need[p][j] > work[j]) {
                        break;
                    }
                }
               
                if (j == m) {
                    // Add the resources allocated to process p to the work array
                    for (int k = 0; k < m; k++) {
                        work[k] += allot[p][k];
                    }
                    safeSeq[count++] = processes[p];  
                    finish[p] = true;  
                    found = true;
                }
            }
        }
       
        if (!found) {
            printf("\nSystem is in an Unsafe State!\n");
            return false;
        }
    }

   
    printf("\nSystem is in a Safe State.\n");
    printf("Safe Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", safeSeq[i]);
    }
    return true;
}


void printDetails(int processes[], int avail[], int max[][MAX], int allot[][MAX], int need[][MAX], int n, int m) {
    printf("\nSystem Maximum Resources: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", avail[i]);
    }
    printf("\n");

   
    printf("\nProcess\tMax Needs\tAllocated\tCurrent Need\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t", i);
        for (int j = 0; j < m; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\t\t");
        for (int j = 0; j < m; j++) {
            printf("%d ", allot[i][j]);
        }
        printf("\t\t");
        for (int j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

   
    printf("\nAvailable Resources: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", avail[i]);
    }
    printf("\n");
}


int main() {
    int processes[MAX] = {0, 1, 2, 3, 4};  // Hardcoded process IDs
    int avail[MAX] = {3, 3, 2};  
   
   
    int max[MAX][MAX] = {
        {7, 5, 3},  
        {3, 2, 2},  
        {9, 0, 2},  
        {2, 2, 2},  
        {4, 3, 3}  
    };
   
   
    int allot[MAX][MAX] = {
        {0, 1, 0},  
        {2, 0, 0},  
        {3, 0, 2},  
        {2, 1, 1},  
        {0, 0, 2}  
    };
   
    int n = 5;  
    int m = 3;  

   
    int need[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }

   
    printDetails(processes, avail, max, allot, need, n, m);

   
    isSafe(processes, avail, max, allot, n, m);

    return 0;
}