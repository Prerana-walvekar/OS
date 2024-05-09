#include <stdio.h>

// Adjusted sort function to only consider priority
void sortA(int priority[], int burst[], int index[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Check if the current process has a higher priority
            if (priority[j] > priority[j + 1]) {
                // Swap elements based on priority
                int temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;
                int tempBurst = burst[j];
                burst[j] = burst[j + 1];
                burst[j + 1] = tempBurst;
                int tempIndex = index[j];
                index[j] = index[j + 1];
                index[j + 1] = tempIndex;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    int burst[n], priority[n], index[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time, Priority Value for Process %d: ", i + 1);
        scanf("%d %d", &burst[i], &priority[i]);
        index[i] = i + 1;
    }

    sortA(priority, burst, index, n);

    int t = 0;
    printf("\n");

    printf("Process Id\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    int wait_time = 0;
    int total_wait_time = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d\n", index[i], burst[i], priority[i], wait_time, wait_time + burst[i]);
        total_wait_time += wait_time;
        wait_time += burst[i];
    }

    float avg_wait_time = (float)total_wait_time / n;
    printf("Average waiting time is %.2f\n", avg_wait_time);

    int total_Turn_Around = 0;
    for (int i = 0; i < n; i++) {
        total_Turn_Around += burst[i];
    }
    float avg_Turn_Around = (float)total_Turn_Around / n;
    printf("Average TurnAround Time is %.2f", avg_Turn_Around);

    return 0;
}
