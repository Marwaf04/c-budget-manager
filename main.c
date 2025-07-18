
#include "data.h"
#include "budget.h"
#include "ordering.h"
#include <stdio.h>
#include <stdlib.h>

// Function to clear screen
void clearScreen() {
    system("clear");  
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <inputfile>\n", argv[0]);
        return 1;
    }

   
    Entry* entries = NULL;
    int entryCount = 0;
    loadEntries(argv[1], &entries, &entryCount);

    int choice = 0;
    do {
        clearScreen();

        // Display menu
        printf("Budget Tracking System\n");
        printf("=====================\n\n");
        printf("1. Display all entries\n");
        printf("2. Expense Distribution\n");
        printf("3. Sort Entries\n");
        printf("4. Add Income/Expense Entry\n");
        printf("5. Modify Entry\n");
        printf("6. Filter by Month\n");
        printf("7. Exit\n\n");

        printf("Choice: ");
        scanf("%d", &choice);

        // Handle choice
        switch (choice) {
            case 1:
                displayAllEntries(entries, entryCount);
                break;
            case 2:
                displayExpenseDistribution(entries, entryCount);
                break;
            case 3:
                sortEntriesMenu(entries, entryCount);
                break;
            case 4:
                addEntry(&entries, &entryCount);
                break;
            case 5:
                modifyEntry(entries, entryCount);
                break;
            case 6:
                filterByMonth(entries, entryCount);
                break;
            case 7:
                printf("\nGoodbye and thanks for using our budget tracker app!!!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        if (choice != 7) {
            printf("\nPress Enter to continue...");
            getchar(); 
            getchar(); 
        }

    } while (choice != 7);

    // Free memory
    free(entries);

    return 0;
}
