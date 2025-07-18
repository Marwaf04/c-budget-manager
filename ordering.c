
#include "ordering.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareByID(const void* a, const void* b) {
    Entry* entryA = (Entry*)a;
    Entry* entryB = (Entry*)b;
    return entryA->id - entryB->id;
}

int compareByDate(const void* a, const void* b) {
    Entry* entryA = (Entry*)a;
    Entry* entryB = (Entry*)b;
    return strcmp(entryA->date, entryB->date);
}

int compareByAmount(const void* a, const void* b) {
    Entry* entryA = (Entry*)a;
    Entry* entryB = (Entry*)b;
    if (entryA->amount < entryB->amount) return -1;
    if (entryA->amount > entryB->amount) return 1;
    return 0;
}

int compareByDescription(const void* a, const void* b) {
    Entry* entryA = (Entry*)a;
    Entry* entryB = (Entry*)b;
    return strcmp(entryA->description, entryB->description);
}

void sortEntriesMenu(Entry* entries, int entryCount) {
    int sortChoice = 0;

    printf("\nSort Menu\n\n");
    printf("1. Sort by ID\n");
    printf("2. Sort by Date\n");
    printf("3. Sort by Amount\n");
    printf("4. Sort by Description\n\n");
    printf("Choice: ");
    scanf("%d", &sortChoice);

    switch (sortChoice) {
        case 1:
            qsort(entries, entryCount, sizeof(Entry), compareByID);
            printf("\nEntries sorted by ID.\n");
            break;
        case 2:
            qsort(entries, entryCount, sizeof(Entry), compareByDate);
            printf("\nEntries sorted by Date.\n");
            break;
        case 3:
            qsort(entries, entryCount, sizeof(Entry), compareByAmount);
            printf("\nEntries sorted by Amount.\n");
            break;
        case 4:
            qsort(entries, entryCount, sizeof(Entry), compareByDescription);
            printf("\nEntries sorted by Description.\n");
            break;
        default:
            printf("\nInvalid choice.\n");
            break;
    }
}
