//
// Created by elias on 11.01.18.
//

#ifndef PHONEBOOK_CONTACTS_H
#define PHONEBOOK_CONTACTS_H

#include <printf.h>

typedef struct contact{
    char * name;
    char * number;
    struct contact * next;
}contact;

void printContact(contact * p1);
void loadContact(contact * p1);
void addContact(contact * c1);
void removeContact(contact * c1);

#endif //PHONEBOOK_CONTACTS_H
