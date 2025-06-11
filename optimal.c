#include <stdio.h>

int findOptimalIndex(int ref[], int frame[], int current, int n, int frameCount) {
    int farthest = -1, index = -1;
    for (int i = 0; i < frameCount; i++) {
        int j;
        for (j = current + 1; j < n; j++) {
            if (frame[i] == ref[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == n) return i; // not found in future
    }
    return (index == -1) ? 0 : index;
}

int main() {
    int referenceString[25], pageFrames[10];
    int referenceLength, frameCount;
    int pageFaults = 0;

    scanf("%d", &referenceLength);
    for (int i = 0; i < referenceLength; i++)
        scanf("%d", &referenceString[i]);
    scanf("%d", &frameCount);

    for (int i = 0; i < frameCount; i++)
        pageFrames[i] = -1;

    int filled = 0;
    for (int i = 0; i < referenceLength; i++) {
        int found = 0;
        for (int j = 0; j < frameCount; j++) {
            if (pageFrames[j] == referenceString[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            if (filled < frameCount) {
                pageFrames[filled++] = referenceString[i];
            } else {
                int index = findOptimalIndex(referenceString, pageFrames, i, referenceLength, frameCount);
                pageFrames[index] = referenceString[i];
            }
            pageFaults++;
        }

        for (int j = 0; j < frameCount; j++) {
            if (pageFrames[j] == -1) printf("- ");
            else printf("%d ", pageFrames[j]);
        }
        if (!found) printf("Page Fault %d", pageFaults);
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}
