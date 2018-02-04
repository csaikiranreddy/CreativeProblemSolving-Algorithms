#include <stdio.h>
#include <stdlib.h>
#include "Contact.h"
int showMenu()
{
    int choice;
    printf("\nMENU");
    printf("\n====");
    printf("\n1. Add Contact");
    printf("\n2. Search Contact");
    printf("\n3. List Contacts");
    printf("\n4. Delete Contact");
    printf("\n5. Exit");
    printf("\n\nYour Choice: ");
    scanf("%d", &choice);
    return choice;
}
void unitTests()
{
    Contact *pb = NULL;
    pb = addContact(pb, "Anisha", "Challa", "34534");
    pb = addContact(pb, "Ajay", "Kumar", "34534");
    pb = addContact(pb, "Lokesh", "Atmuri", "34534");
    pb = addContact(pb, "Rushank", "Reddy", "34534");
    pb = addContact(pb, "Krishna", "Mohan", "34534");
    pb = addContact(pb, "Nikhila", "Reddy", "34534");
    pb = addContact(pb, "Sai", "Kiran", "34534");
    listContacts(pb);
    listNamesBeginningWith(pb, "a");
    pb = deleteContact(pb, "Sai");
    pb = deleteContact(pb, "Anisha");
    pb = deleteContact(pb, "Rushank");
    listContacts(pb);
}
int menuDrivenProgram()
{
    Contact *pb = NULL;

    char fn[200], ln[200], mobile[200];
    int choice;
    while(1)
    {
        choice = showMenu();
        switch(choice)
        {
        case 1:
            printf("\nEnter First Name: ");
            scanf("%s", fn);
            printf("\nEnter Last Name: ");
            scanf("%s", ln);
            printf("\nEnter Mobile Number: ");
            scanf("%s", mobile);
            pb = addContact(pb, fn, ln, mobile);
            break;
        case 2:
            printf("\nEnter First Name: ");
            scanf("%s", fn);
            listNamesBeginningWith(pb, fn);
            break;
        case 3:
            listContacts(pb);
            break;
        case 4:
            printf("\nEnter First Name: ");
            scanf("%s", fn);
            pb = deleteContact(pb, fn);
            break;
        case 5:
            return 0;
        //OR exit(0);
        default:
            printf("\nBAD CHOICE! TRY AGAIN!!\n");
            break;
        }
    }
    return 0;
}

int main()
{
    unitTests();
    return 0;
}
