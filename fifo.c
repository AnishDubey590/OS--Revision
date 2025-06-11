#include <stdio.h>

int main() {
    int referenceString[25], pageFrames[10];
    int referenceLength, frameCount;
    int i, currentIndex = 0, pageFaults = 0;

    scanf("%d", &referenceLength);
    for (i = 0; i < referenceLength; i++)
        scanf("%d", &referenceString[i]);

    scanf("%d", &frameCount);
    for (i = 0; i < frameCount; i++)
        pageFrames[i] = -1;

    for (i = 0; i < referenceLength; i++) {
        int pageFound = 0;
        for (int j = 0; j < frameCount; j++) {
            if (pageFrames[j] == referenceString[i]) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            pageFrames[currentIndex] = referenceString[i];
            currentIndex = (currentIndex + 1) % frameCount;
            pageFaults++;
        }

        // Print frame content after each reference
        for (int j = 0; j < frameCount; j++) {
            if (pageFrames[j] == -1)
                printf("- ");
            else
                printf("%d ", pageFrames[j]); 
        }
        if (!pageFound) printf("Page Fault %d", pageFaults);
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}
