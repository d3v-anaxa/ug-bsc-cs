#include <stdio.h>
#define MEMORY_SIZE 100 // Total memory size
struct MemoryBlock {
    int id; // Block ID
    int size; // Block size
    int allocated; // 1 if allocated, 0 if free
};
void initializeMemory(struct MemoryBlock memory[], int n) {
    for (int i = 0; i < n; i++) {
        memory[i].id = i;
        memory[i].size = 0;
        memory[i].allocated = 0;
    }
}
void displayMemory(struct MemoryBlock memory[], int n) {
    printf("Memory Blocks:\n");
    printf("ID\tSize\tAllocated\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%s\n", memory[i].id, memory[i].size, memory[i].allocated ? "Yes" : "No");
    }
}
int firstFit(struct MemoryBlock memory[], int n, int size) {
    for (int i = 0; i < n; i++) {
        if (!memory[i].allocated && memory[i].size >= size) {
            memory[i].allocated = 1;
            return i;
        }
    }
    return -1; // Allocation failed
}
int bestFit(struct MemoryBlock memory[], int n, int size) {
    int minSize = MEMORY_SIZE + 1;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (!memory[i].allocated && memory[i].size >= size && memory[i].size < minSize) {
            minSize = memory[i].size;
            index = i;
        }
    }
    if (index != -1) {
        memory[index].allocated = 1;
    }
    return index;
}
int worstFit(struct MemoryBlock memory[], int n, int size) {
    int maxSize = -1;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (!memory[i].allocated && memory[i].size >= size && memory[i].size > maxSize) {
            maxSize = memory[i].size;
            index = i;
        }
    }
    if (index != -1) {
        memory[index].allocated = 1;
    }
    return index;
}
int main() {
    struct MemoryBlock memory[MEMORY_SIZE];
    initializeMemory(memory, MEMORY_SIZE);
    int choice, size, index;
    do {
        printf("\nMemory Allocation Strategies\n");
        printf("1. First-Fit\n");
        printf("2. Best-Fit\n");
        printf("3. Worst-Fit\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter size of block to allocate: ");
                scanf("%d", &size);
                index = firstFit(memory, MEMORY_SIZE, size);
                if (index != -1) {
                    printf("Block allocated at index %d.\n", index);
                } else {
                    printf("Memory allocation failed.\n");
                }
                break;
            case 2:
                printf("Enter size of block to allocate: ");
                scanf("%d", &size);
                index = bestFit(memory, MEMORY_SIZE, size);
                if (index != -1) {
                    printf("Block allocated at index %d.\n", index);
                } else {
                    printf("Memory allocation failed.\n");
                }
                break;
            case 3:
                printf("Enter size of block to allocate: ");
                scanf("%d", &size);
                index = worstFit(memory, MEMORY_SIZE, size);
                if (index != -1) {
                    printf("Block allocated at index %d.\n", index);
                } else {
                    printf("Memory allocation failed.\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
        displayMemory(memory, MEMORY_SIZE);
    } while (choice != 4);
    return 0;
}
