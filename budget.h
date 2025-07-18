#ifndef BUDGET_H
#define BUDGET_H

#include "data.h"

void displayAllEntries(Entry* entries, int entryCount);
void displayExpenseDistribution(Entry* entries, int entryCount);
void addEntry(Entry** entries, int* entryCount);
void modifyEntry(Entry* entries, int entryCount);
void filterByMonth(Entry* entries, int entryCount);

#endif
