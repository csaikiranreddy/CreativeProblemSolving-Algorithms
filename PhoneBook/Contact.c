#include <stdlib.h>
#include "Contact.h"
#include <string.h>
#include <stdio.h>

Contact *createContactNode(char *f, char *l, char *mobile)
{
    Contact *c = malloc(sizeof(Contact));

    c->fn = malloc(strlen(f)+1);
    strcpy(c->fn, f);

    c->ln = malloc(strlen(l)+1);
    strcpy(c->ln, l);

    c->mobile = malloc(strlen(mobile)+1);
    strcpy(c->mobile, mobile);

    c->next = NULL;
    return c;
}

Contact *addContact(Contact *head, char *f, char *l, char *m)
{
    Contact *c = createContactNode(f, l, m);

    if(head==NULL)
        return c;

    // Insert in Beginning
    if(strcmp(head->fn, f)>0)
    {
        c->next = head;
        return c;
    }

    Contact *cur = head;
    Contact *prev = NULL;
    while(cur!=NULL)
    {
        if(strcmp(cur->fn,f)>0)
        {
            // Insertion in Middle
            prev->next = c;
            c->next = cur;
            return head;
        }
        else
        {
            prev  = cur;
            cur = cur->next;
        }
    }

    // Inserted in End
    prev->next = c;

    return head;
}


void listContacts(Contact *head)
{
    int i=1;
    printf("\n\nListing Names:");
    printf("\n---------------------------------------------------");
    printf("\n| %-3s | %-10s | %-10s | %-15s |", "SR", "FN", "LN", "MOBILE");
    printf("\n---------------------------------------------------");
    while(head!=NULL)
    {
        printf("\n| %-3d | %-10s | %-10s | %-15s |",
               i,
               head->fn,
               head->ln,
               head->mobile);
        head = head->next;
        i++;
    }
    if(i!=1)
        printf("\n---------------------------------------------------");
}
void listNamesBeginningWith(Contact *head, char *pfn)
{
    int i=1;
    printf("\n\nNames Matching '%s'", pfn);
    printf("\n---------------------------------------------------");
    printf("\n| %-3s | %-10s | %-10s | %-15s |", "SR", "FN", "LN", "MOBILE");
    printf("\n---------------------------------------------------");
    while(head!=NULL)
    {
        if(strnicmp(head->fn, pfn, strlen(pfn))==0)
        {
            printf("\n| %-3d | %-10s | %-10s | %-15s |",
                   i,
                   head->fn,
                   head->ln,
                   head->mobile);
            i++;
        }
        head = head->next;
    }
    if(i==1)
        printf("\nNO MATCH FOUND\n");
    else
        printf("\n---------------------------------------------------");
}


Contact *deleteContact(Contact *head, char fn[])
{
    // Empty List
    if(head==NULL)
        return NULL;

    // Deletion of Head
    Contact *next;
    if(strcmpi(head->fn, fn)==0)
    {
        next = head->next;
        free(head);
        return next;
    }
    Contact *cur = head, *prev=NULL;
    while(cur!=NULL)
    {
        if(strcmpi(cur->fn, fn)==0)
        {
            prev->next = cur->next;
            free(cur);
            return head;
        }
        prev = cur;
        cur = cur->next;
    }
    return head;
}
