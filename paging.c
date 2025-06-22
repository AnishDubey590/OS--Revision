#include <stdio.h>

int main() {
    int memorySize, pageSize, totalFrames, remainingFrames;
    int numberOfProcesses;
    int pagesRequired[10], pageTable[10][20];
    int processNumber, pageNumber, offset, physicalAddress;

    // Input memory and page size
    printf("Enter total memory size: ");
    scanf("%d", &memorySize);

    printf("Enter page size: ");
    scanf("%d", &pageSize);

    totalFrames = memorySize / pageSize;
    remainingFrames = totalFrames;

    printf("Number of available frames: %d\n", totalFrames);

    // Input process and their page table
    printf("Enter number of processes: ");
    scanf("%d", &numberOfProcesses);

    for (int i = 0; i < numberOfProcesses; i++) {
        printf("\nEnter number of pages required for Process %d: ", i);
        scanf("%d", &pagesRequired[i]);

        if (pagesRequired[i] > remainingFrames) {
            printf("Not enough memory to allocate pages to Process %d\n", i);
            break;
        }

        remainingFrames -= pagesRequired[i];

        printf("Enter frame numbers for each page of Process %d:\n", i);
        for (int j = 0; j < pagesRequired[i]; j++) {
            scanf("%d", &pageTable[i][j]);
        }
    }

    // Logical to physical address translation
    printf("\nEnter Logical Address (process number, page number, offset): ");
    scanf("%d %d %d", &processNumber, &pageNumber, &offset);

    if (processNumber >= numberOfProcesses ||
        pageNumber >= pagesRequired[processNumber] ||
        offset >= pageSize) {
        printf("Invalid input: check process number, page number, or offset.\n");
    } else {
        physicalAddress = pageTable[processNumber][pageNumber] * pageSize + offset;
        printf("Physical Address: %d\n", physicalAddress);
    }

    return 0;
}
