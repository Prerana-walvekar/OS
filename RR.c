#include <stdio.h>
// Function to sum an array elements
float sum(int arr[], int n) {
    float sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}
int main() {
    int n, i, burstTime[10], arrivalTime[10], timeQuantum;
    int remainingBurstTime[10];
    int time = 0, processCount = 0;
    int waitingTime[10], turnaroundTime[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d", &burstTime[i]);
        remainingBurstTime[i] = burstTime[i];
    }

    printf("Enter arrival time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d", &arrivalTime[i]);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);

    printf("\nRound Robin CPU Scheduling:\n");
    printf("Process\t Arrival Time\t Burst Time\t Remaining Time\n");
    printf("-----------------------------------------------------------------\n");

    while(processCount < n) {
        for(i = 0; i < n; i++) {
            if(remainingBurstTime[i] > 0 && time >= arrivalTime[i]) {
                time++;
                if(remainingBurstTime[i] > timeQuantum) {
                    remainingBurstTime[i] -= timeQuantum;
                } else {
                    remainingBurstTime[i] = 0;
                }
                printf("P%d\t\t\t\t %d\t\t\t %d\t\t\t %d\n", i+1, arrivalTime[i], burstTime[i], remainingBurstTime[i]);
                if(remainingBurstTime[i] == 0) {
                    processCount++;
                }
            }
        }
    }

    printf("\nTotal time taken: %d\n", time);

    // Calculate waiting time and turnaround time
    for(i = 0; i < n; i++) {
        waitingTime[i] = time - burstTime[i];
        if(waitingTime[i] < 0)
            waitingTime[i] = 0;
        turnaroundTime[i] = time - arrivalTime[i];
    }

    printf("\nProcess\t Waiting Time\t Turnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t\t %d\t\t\t %d\n", i+1, waitingTime[i], turnaroundTime[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", (float)sum(waitingTime, n) / n);
    printf("Average Turnaround Time = %.2f\n", (float)sum(turnaroundTime, n) / n);

    return 0;
}
