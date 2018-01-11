//
// Created by elias on 11.01.18.
//

#include <stdio.h>
#include <stdlib.h>
#include "contacts.h"
#include <memory.h>



void printContact(contact * c1){
    do{
        printf("----------\n");
        printf("%s%s\n", c1->name, c1->number);
        c1 = c1->next;
    }while(c1 != NULL);
}

//populates the list of contacts
void loadContact(contact * c1){
    c1->name = "John\n";
    c1->number = "2223\n";
    c1->next = malloc(sizeof(contact));
    c1->next->name = "doe\n";
    c1->next->number = "323\n";
    c1->next->next = NULL;
}

void addContact(contact * c1){
    printf("\nAdd Contact\n");
    char * name = malloc(8);
    char * number = malloc(8);
    printf("Name of contact\n");
    fgets(name, 7, stdin);
    printf("Number of contact");
    fgets(number, 7, stdin);
    do{
        c1 = c1->next;
    }while(c1->next != NULL);
    c1->next = malloc(sizeof(contact));
    c1 = c1->next;
    c1->name = name;
    c1->number = number;
    c1->next = NULL;
}

void removeContact(contact * c1){
    char * input = malloc(8);
    printf("name of contact to remove: ");
    fgets(input, 7, stdin);

    //In case the name to be removed is first in the list
    if(strncmp(c1->name, input, 8) == 0){
        contact * tmp = c1;
        c1 = c1->next;
        free(tmp);
        return;
    }
    do{
        if(strncmp(c1->name, input, 8) == 0){
            if(c1->next != NULL){
                contact * tmp = c1->next;
                c1->next = c1->next->next;
                free(tmp);
            }
        }

    }while(c1->next != NULL);
}
