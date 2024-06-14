#include <stdio.h>

int main() {
    
    int n, m, i, j, min, replace_index;
    int page_faults = 0, page_hits = 0;
  
    printf("Enter the number of frames: ");
    scanf("%d", &m); // Change MAX_FRAMES to a variable

    printf("Enter the number of pages: ");
    scanf("%d", &n);
  
    int frames[m],counter[m],pages[n];
  
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    
  
    for (i = 0; i < m; i++) {
        frames[i] = -1;
        counter[i] = 0;
    }

    printf("\n\t\t\t");
    for(i=1;i<=m;i++){
      printf("Frame %d\t\t",i);
    }
    printf("\n");
  
    for (i = 0; i < n; i++) {
      printf("   %d\t\t    ", pages[i]);
      int page_found = 0;
        for (j = 0; j < m; j++) {
            if (frames[j] == pages[i]) {
                page_hits++;
                page_found = 1;
                counter[j] = i + 1;
                break;
            }
        }
        if (!page_found) {
            page_faults++;
            min = counter[0];
            replace_index = 0;
            for (j = 1; j < m; j++) {
                if (counter[j] < min) {
                    min = counter[j];
                    replace_index = j;
                }
            }
            frames[replace_index] = pages[i];
            counter[replace_index] = i + 1;
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
