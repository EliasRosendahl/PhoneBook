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
    c1->name = "john\n";
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
    //No need to free tmp, as it is freed at the end of the function (maybe)
    if(strncmp(c1->name, input, 8) == 0){
        *c1 = *c1->next;
        printf("Contact Deleted\n");
        return;
    }
    do{
        if(strncmp(c1->next->name, input, 8) == 0){
            if(c1->next->next != NULL){
                c1->next = c1->next->next;
                printf("Contact Deleted\n");
                return;
            }
            if(c1->next->next == NULL){
                c1->next = NULL;
                printf("Contact Deleted\n");
                return;
            }
        }
        c1 = c1->next;
        printf("Contact not found\n");

    }while(c1->next != NULL);
}
