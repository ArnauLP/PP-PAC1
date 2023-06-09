#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "donation.h"

// Parse a tDate from string information
void date_parse(tDate *date, const char *text) {
    // Check output data
    assert(date != NULL);

    // Check input date
    assert(text != NULL);
    assert(strlen(text) == 10);

    // Parse the input date
    sscanf(text, "%d/%d/%d", &(date->day), &(date->month), &(date->year));
}

// Compare two tDate structures and return true if they contain the same value or false otherwise.
bool date_equals(tDate date1, tDate date2) {
    return (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year);
}

////////////////////////////////////////
// EX2: Implement your methods here....

void donationData_init(tDonationData *data) {
    data->n = 0;
}

// Initialize the donations data 



// Get the number of donations
int donationData_len(tDonationData data) {
    return data.n;
}

// Parse input from CSVEntry
void donation_parse(tDonation *donation, tCSVEntry entry) {

    // “12345678N;John;Smith;+34699999999;john.smith@example.com;My street, 25;08001;30/12/1980”
    int n = entry.numFields;
    char * buffer;
    int lenght = 512;
    csv_getAsString(entry,0, buffer,lenght);
    strcpy( donation->document ,  buffer);
}

// Add a new donation
void donationData_add(tDonationData *data, tDonation donation) {
    // TODO
    bool trobat = false;
    bool repetit = false;
    int i = 0;

    // buscar lloc d'insersió
    while (i < data->n && !trobat && !repetit) {
        if (strcmp( data->donationsTable[i].projectCode , donation.projectCode) &&
            date_equals(data->donationsTable[i].date, donation.date) &&
            data->donationsTable[i].document == donation.document) {
            repetit = true;
        } else if (strcmp(data->donationsTable[i].projectCode , donation.projectCode)>0) {
            trobat = true;
        } else {
            i++;
        }
    }
    if (trobat && !repetit) {
        // moure taula
        for (int j = data->n; j <= i; ++j) {
            data->donationsTable[j] = data->donationsTable[j - 1];
        }
        // inserrir elem a pos i
        data->donationsTable[i] = donation;
    }
}

// Get a donation
void donationData_get(tDonationData data, int index, char *buffer) {
    // TODO
    //donation_parse(&data.donationsTable[index],)

    //sprintf();
}

// Remove a donation
void donationData_del(tDonationData *data, tDate date, char projectCode[], char document[]) {
    //var
    int pos;
    bool trobat = false;
    int i = 0;
    //buscar la pos a elminar
    while (i < data->n && !trobat) {
        if (strcmp( data->donationsTable[i].projectCode , projectCode )&& date_equals(data->donationsTable[i].date, date) &&
                                                  strcmp(data->donationsTable[i].document, document)) {
            trobat = true;
            pos = i;
        } else {
            i++;
        }
    }
    //eliminar
    if (trobat) {
        for (int j = pos; j < data->n - 1; ++j) {
            data->donationsTable[j] = data->donationsTable[j + 1];

        }
        data->n--;
    }
}


