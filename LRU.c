#include <stdio.h>

int findLeastRecentlyUsed(int reference[], int frame[], int index, int current) {
    int used[10] = {0}, i;
    for (i = current - 1; i >= 0 && index > 0; i--) {
        for (int j = 0; j < index; j++) {
            if (!used[j] && frame[j] == reference[i]) {
                used[j] = 1;
                break;
            }
        }
    }
    for (i = 0; i < index; i++)
        if (!used[i]) return i;
    return 0;
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
                int lruIndex = findLeastRecentlyUsed(referenceString, pageFrames, frameCount, i);
                pageFrames[lruIndex] = referenceString[i];
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
