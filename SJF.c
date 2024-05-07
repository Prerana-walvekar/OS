#include <stdio.h>

void Sort(int arr[], int pids[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                int pid_temp = pids[j];
                pids[j] = pids[j+1];
                pids[j+1] = pid_temp;
            }
        }
    }
}

void sjf(int processes[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0,i;
    // Sort burst times and PIDs according to burst time
    Sort(bt, processes, n);

    wt[0] = 0; // Waiting time for first process is 0
    for (i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];

    for (i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    // Calculate average waiting time and average turnaround time
    for (i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    float avg_wt = (float)total_wt / (float)n;
    float avg_tat = (float)total_tat / (float)n;

    // Print process details 
    printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage waiting time = %.2f", avg_wt);
    printf("\nAverage turnaround time = %.2f", avg_tat);
}

int main() {
    int n,i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burst_time[n];

    printf("Enter process id of all the processes: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &processes[i]);
    }

    printf("Enter burst time of all the processes: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &burst_time[i]);
    }

    sjf(processes, n, burst_time);

    return 0;
}
