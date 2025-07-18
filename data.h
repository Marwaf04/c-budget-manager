
#ifndef DATA_H
#define DATA_H

typedef struct {
    int id;
    char date[11];          
    char type[20];         
    char category[20];     
    char description[101];  
    double amount;
} Entry;

void loadEntries(const char* filename, Entry** entries, int* entryCount);

#endif
