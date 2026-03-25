#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 50
#define MAX_FRAMES 20

int main() {
    int pages, frames, page_size;
    int page_table[MAX_PAGES];
    int memory[MAX_FRAMES];
    int logical_address, page_number, offset, physical_address;
    
    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter page size: ");
    scanf("%d", &page_size);

    // Initialize memory and page table
    for (int i = 0; i < frames; i++)
        memory[i] = -1;

    for (int i = 0; i < pages; i++)
        page_table[i] = -1;

    int frame_index = 0;

    // Allocate pages to frames
    for (int i = 0; i < pages; i++) {
        if (frame_index < frames) {
            page_table[i] = frame_index;
            memory[frame_index] = i;
            frame_index++;
        } else {
            // Simulate page fault (no free frame)
            page_table[i] = -1;
        }
    }

    printf("\nPage Table:\n");
    printf("Page No.\tFrame No.\n");
    for (int i = 0; i < pages; i++) {
        printf("%d\t\t%d\n", i, page_table[i]);
    }

    // Address translation
    printf("\nEnter logical address: ");
    scanf("%d", &logical_address);

    page_number = logical_address / page_size;
    offset = logical_address % page_size;

    if (page_number >= pages) {
        printf("Invalid logical address!\n");
        return 0;
    }

    if (page_table[page_number] == -1) {
        printf("Page Fault! Page %d not in memory.\n", page_number);

        // Load page into memory (simple replacement: FIFO)
        int replace_frame = page_number % frames;
        memory[replace_frame] = page_number;
        page_table[page_number] = replace_frame;

        printf("Page %d loaded into frame %d\n", page_number, replace_frame);
    }

    physical_address = page_table[page_number] * page_size + offset;

    printf("\nLogical Address: %d\n", logical_address);
    printf("Page Number: %d, Offset: %d\n", page_number, offset);
    printf("Physical Address: %d\n", physical_address);

    return 0;
}
