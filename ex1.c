#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "ex1.h"

#define MAX_CONTACTS 20

// Structure
typedef struct {
    char firstName[20];
    char lastName[30];
    char phonenumber[20];
} Contact;

Contact addressBook[MAX_CONTACTS];
int contactCount = 0;

// Adds a new contact
bool addContact(const char *firstName, const char *lastName, const char *phonenumber) {
    if (contactCount >= MAX_CONTACTS) {
        return false;
    }
    strcpy(addressBook[contactCount].firstName, firstName);
    strcpy(addressBook[contactCount].lastName, lastName);
    strcpy(addressBook[contactCount].phonenumber, phonenumber);
    contactCount++;
    return true;
}

// Searches for a contact by last name
int findContactByLastName(const char *lastName) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(addressBook[i].lastName, lastName) == 0) {
            return i;
        }
    }
    return -1;
}

// Removes a contact by last name
bool removeContactByLastName(const char *lastName) {
    int index = findContactByLastName(lastName);
    if (index == -1) {
        return false;
    }
    for (int i = index; i < contactCount - 1; i++) {
        addressBook[i] = addressBook[i + 1];
    }
    contactCount--;
    return true;
}

// Prints all contacts
void printAllContacts() {
    if (contactCount == 0) {
        printf("There are no contacts\n");
    } else {
        for (int i = 0; i < contactCount; i++) {
            printf("%d. %s %s, phone: %s\n",
                   i + 1,
                   addressBook[i].firstName,
                   addressBook[i].lastName,
                   addressBook[i].phonenumber);
        }
    }
}

/*  (FUN FACT)
    The longest name in the world is Adolph Blaine Charles David Earl Frederick
    Gerald Hubert Irvin John Kenneth Lloyd Martin Nero Oliver Paul Quincy Randolph
    Sherman Thomas Uncas Victor William Xerxes Yancy Zeus Wolfeschlegelsteinhausen
    bergerdorffwelchevoralternwarengewissenhaftschaferswessenschafewarenwohlgepfle
    geundsorgfaltigkeitbeschutzenvonangreifendurchihrraubgierigfeindewelchevoralte
    rnzwolftausendjahresvorandieerscheinenvanderersteerdemenschderraumschiffgebrau
    chlichtalsseinursprungvonkraftgestartseinlangefahrthinzwischensternartigraumau
    fdersuchenachdiesternwelchegehabtbewohnbarplanetenkreisedrehensichundwohindern
    eurassevonverstandigmenschlichkeitkonntefortpflanzenundsicherfreuenanlebenslan
    glichfreudeundruhemitnichteinfurchtvorangreifenvonandererintelligentgeschopfsv
    onhinzwischensternartigraum.
    He was commonly known as Hubert Blaine Wolfeschlegelsteinhausen-bergerdorff Sr.

    I would never try to look him up in a telephone book by name
    */

void run_ex1() {
    // Sample contacts
    addContact("Kamil", "Pomaranczowy", "123456789");
    addContact("Anna", "Zielony", "987654321");
    addContact("Piotr", "Bialy", "5432167890");

    printf("Address book:\n");
    printAllContacts();


    addContact("Ziemowit", "Czarny", "547698124");
    removeContactByLastName("Zielony");

    printf("\nAddress book after modifications:\n");
    printAllContacts();

    //Search for surname
    char surname[50];
    printf("\nEnter last name to search: ");
    scanf("%s", surname);
    int index = findContactByLastName(surname);

    if (index != -1) {
        printf("Found contact: %s %s, phone: %s\n",
               addressBook[index].firstName,
               addressBook[index].lastName,
               addressBook[index].phonenumber);
    } else {
        printf("Contact with last name \"%s\" does not exist\n", surname);
    }
}
