#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void loadEntries(const char* filename, Entry** entries, int* entryCount) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        exit(1);
    }

    *entries = NULL;
    *entryCount = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        *entries = realloc(*entries, (*entryCount + 1) * sizeof(Entry));
        if (*entries == NULL) {
            fprintf(stderr, "Error: Memory allocation failed.\n");
            exit(1);
        }

        
        char* token = strtok(line, "|");
        (*entries)[*entryCount].id = atoi(token);

        token = strtok(NULL, "|");
        strncpy((*entries)[*entryCount].date, token, 10);
        (*entries)[*entryCount].date[10] = '\0';

        token = strtok(NULL, "|");
        strncpy((*entries)[*entryCount].type, token, 19);
        (*entries)[*entryCount].type[19] = '\0';

        token = strtok(NULL, "|");
        strncpy((*entries)[*entryCount].category, token, 19);
        (*entries)[*entryCount].category[19] = '\0';

        token = strtok(NULL, "|");
        strncpy((*entries)[*entryCount].description, token, 100);
        (*entries)[*entryCount].description[100] = '\0';

        token = strtok(NULL, "|");
        (*entries)[*entryCount].amount = atof(token);

        (*entryCount)++;
    }

    fclose(file);
}
