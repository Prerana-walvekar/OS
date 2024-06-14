#include <stdio.h>

#define MAX_PAGES 10

int main() {
    int n, m, i, j, page_faults = 0, page_hits = 0, k = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &m);
    
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int frames[m]; // Adjusted to use MAX_PAGES
    int pages[n];
    
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

     // Get the frame size from the user

    for (i = 0; i < m; i++) // Initialize frames using the variable frame size
        frames[i] = -1;

    printf("\n\t\t\t");
    for(i=1;i<=m;i++){
        printf("Frame %d\t\t",i);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("   %d\t\t    ", pages[i]);
        int page_found = 0;
        for (j = 0; j < m; j++) { // Use the variable frame size here
            if (frames[j] == pages[i]) {
                page_hits++;
                page_found = 1;
                break;
            }
        }
        if (!page_found) {
            frames[k] = pages[i];
            k = (k + 1) % m; // Use the variable frame size here
            page_faults++;
            for (j = 0; j < m; j++){
                if (frames[j]!= -1) {
                    printf("%d\t\t\t", frames[j]);
                } else {
                    printf("-\t\t\t");
                }
            }
            printf("\tPage Fault");
        } else {
            for (j = 0; j < m; j++)
                printf("%d\t\t\t", frames[j]);
            printf("\tPage Hit");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    printf("Total Page Hits: %d\n", page_hits);

    return 0;
}
