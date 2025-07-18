
#include <time.h>
#include "budget.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void displayAllEntries(Entry* entries, int entryCount) {
    printf("Finances Summary\n");
    printf("=================\n\n");

    printf("ID\tDate\t\tType\tCategory\tDescription\t\tAmount\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < entryCount; i++) {
        printf("%d\t%s\t%s\t%s\t\t%s\t\t%.2f\n",
               entries[i].id,
               entries[i].date,
               entries[i].type,
               entries[i].category,
               entries[i].description,
               entries[i].amount);
    }
}


void displayExpenseDistribution(Entry* entries, int entryCount) {
    double totalIncome = 0.0;
    double totalExpenses = 0.0;
    double needsExpenses = 0.0;
    double wantsExpenses = 0.0;

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(entries[i].type, "income") == 0) {
            totalIncome += entries[i].amount;
        } else if (strcmp(entries[i].type, "expense") == 0) {
            totalExpenses += entries[i].amount;

            if (strcmp(entries[i].category, "Needs") == 0) {
                needsExpenses += entries[i].amount;
            } else if (strcmp(entries[i].category, "Wants") == 0) {
                wantsExpenses += entries[i].amount;
            }
        }
    }

    double needsPercentOfExpenses = (totalExpenses > 0) ? (needsExpenses / totalExpenses) * 100 : 0;
    double wantsPercentOfExpenses = (totalExpenses > 0) ? (wantsExpenses / totalExpenses) * 100 : 0;

    double needsPercentOfIncome = (totalIncome > 0) ? (needsExpenses / totalIncome) * 100 : 0;
    double wantsPercentOfIncome = (totalIncome > 0) ? (wantsExpenses / totalIncome) * 100 : 0;

    double netBalance = totalIncome - totalExpenses;

    printf("===== Expense Distribution Report =====\n\n");
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n\n", totalExpenses);

    printf("Needs: $%.2f (%.2f%% of expenses, %.2f%% of income)\n",
           needsExpenses, needsPercentOfExpenses, needsPercentOfIncome);

    printf("Wants: $%.2f (%.2f%% of expenses, %.2f%% of income)\n\n",
           wantsExpenses, wantsPercentOfExpenses, wantsPercentOfIncome);

    printf("Net Balance: $%.2f\n", netBalance);

    printf("=====================================\n");
}


void addEntry(Entry** entries, int* entryCount) {
    // Expand the array by 1
    *entries = realloc(*entries, (*entryCount + 1) * sizeof(Entry));
    if (*entries == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return;
    }

    Entry* newEntry = &(*entries)[*entryCount];

    // Set new ID
    int newID = 1;
    if (*entryCount > 0) {
        newID = (*entries)[*entryCount - 1].id + 1;
    }
    newEntry->id = newID;

    // Ask for date
    char useToday;
    printf("Use today's date? (y/n): ");
    scanf(" %c", &useToday);

    if (useToday == 'y' || useToday == 'Y') {
        // Use today's date
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        sprintf(newEntry->date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    } else {
        // Ask user for date
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", newEntry->date);
    }

    // Ask for type
    printf("Type (income/expense): ");
    scanf("%s", newEntry->type);

    // Ask for category
    printf("Category: ");
    scanf("%s", newEntry->category);

    // Ask for description
    printf("Description: ");
    scanf(" %[^\n]", newEntry->description);

    // Ask for amount
    do {
        printf("Amount: ");
        scanf("%lf", &newEntry->amount);
        if (newEntry->amount < 0) {
            printf("Amount cannot be negative. Please enter again.\n");
        }
    } while (newEntry->amount < 0);

    // Increment count
    (*entryCount)++;

    printf("\nEntry added successfully with ID: %d\n", newEntry->id);
}


void modifyEntry(Entry* entries, int entryCount) {
    int idToModify;
    printf("Enter ID of entry to modify: ");
    scanf("%d", &idToModify);

    // Find entry
    Entry* entryToModify = NULL;
    for (int i = 0; i < entryCount; i++) {
        if (entries[i].id == idToModify) {
            entryToModify = &entries[i];
            break;
        }
    }

    if (entryToModify == NULL) {
        printf("Entry with ID %d not found.\n", idToModify);
        return;
    }

    // Display current details
    printf("\nCurrent Details:\n");
    printf("ID: %d\n", entryToModify->id);
    printf("Date: %s\n", entryToModify->date);
    printf("Type: %s\n", entryToModify->type);
    printf("Category: %s\n", entryToModify->category);
    printf("Description: %s\n", entryToModify->description);
    printf("Amount: %.2f\n", entryToModify->amount);

    // Ask what to modify
    int choice = 0;
    printf("\nWhat would you like to modify?\n");
    printf("1. Date\n");
    printf("2. Amount\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Modify Date
        printf("Enter new date (YYYY-MM-DD): ");
        scanf("%s", entryToModify->date);
        printf("Entry updated successfully.\n");
    } else if (choice == 2) {
        // Modify Amount
        double newAmount;
        do {
            printf("Enter new amount: ");
            scanf("%lf", &newAmount);
            if (newAmount < 0) {
                printf("Amount cannot be negative. Please enter again.\n");
            }
        } while (newAmount < 0);
        entryToModify->amount = newAmount;
        printf("Entry updated successfully.\n");
    } else {
        printf("Invalid choice.\n");
    }
}


void filterByMonth(Entry* entries, int entryCount) {
    int year, month;
    printf("Enter year (YYYY): ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);

    char yearStr[5];
    char monthStr[3];

    sprintf(yearStr, "%04d", year);
    sprintf(monthStr, "%02d", month);

    printf("\nEntries for %d-%02d:\n\n", year, month);
    printf("ID\tDate\t\tType\tCategory\tDescription\t\tAmount\n");
    printf("---------------------------------------------------------------\n");

    int found = 0;

    for (int i = 0; i < entryCount; i++) {
        // Compare year and month
        if (strncmp(entries[i].date, yearStr, 4) == 0 && 
            strncmp(entries[i].date + 5, monthStr, 2) == 0) {
            
            printf("%d\t%s\t%s\t%s\t\t%s\t\t%.2f\n",
                   entries[i].id,
                   entries[i].date,
                   entries[i].type,
                   entries[i].category,
                   entries[i].description,
                   entries[i].amount);
            found = 1;
        }
    }

    if (!found) {
        printf("No entries found for this month.\n");
    }
}

