#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "contacts.h"

int main(){

    //Instantiate list of contacts
    contact c1;
    loadContact(&c1);

    char * input = malloc(20);
    printf("****PhoneBook Application****\n\n");
    do{
        printf("1. List Contacts\n2. Add Contact\n");

        //get user input and store in input
        fgets(input, 3, stdin);

        if(strncmp(input, "1\n", 2) == 0){
            printContact(&c1);
        }
        if(strncmp(input, "2\n", 2) == 0){
            addContact(&c1);

        }

    }while (!strncmp(input, "0", 2) == 0);
}